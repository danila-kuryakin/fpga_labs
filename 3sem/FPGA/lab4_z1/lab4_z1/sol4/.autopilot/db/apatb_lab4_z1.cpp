#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_firstVector_arr "../tv/cdatafile/c.lab4_z1.autotvin_firstVector_arr.dat"
#define AUTOTB_TVOUT_firstVector_arr "../tv/cdatafile/c.lab4_z1.autotvout_firstVector_arr.dat"
// wrapc file define:
#define AUTOTB_TVIN_secondVector_arr "../tv/cdatafile/c.lab4_z1.autotvin_secondVector_arr.dat"
#define AUTOTB_TVOUT_secondVector_arr "../tv/cdatafile/c.lab4_z1.autotvout_secondVector_arr.dat"
// wrapc file define:
#define AUTOTB_TVIN_resultVecror_arr "../tv/cdatafile/c.lab4_z1.autotvin_resultVecror_arr.dat"
#define AUTOTB_TVOUT_resultVecror_arr "../tv/cdatafile/c.lab4_z1.autotvout_resultVecror_arr.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_firstVector_arr "../tv/rtldatafile/rtl.lab4_z1.autotvout_firstVector_arr.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_secondVector_arr "../tv/rtldatafile/rtl.lab4_z1.autotvout_secondVector_arr.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_resultVecror_arr "../tv/rtldatafile/rtl.lab4_z1.autotvout_resultVecror_arr.dat"


inline void rev_endian(char* p, size_t nbytes)
{
  std::reverse(p, p+nbytes);
}

template<size_t bit_width>
struct transaction {
  typedef uint64_t depth_t;
  static const size_t wbytes = (bit_width+7)>>3;
  static const size_t dbytes = sizeof(depth_t);
  const depth_t depth;
  const size_t vbytes;
  const size_t tbytes;
  char * const p;
  typedef char (*p_dat)[wbytes];
  p_dat vp;

  void reorder() {
    rev_endian(p, dbytes);
    p_dat vp = (p_dat) (p+dbytes);
    for (depth_t i = 0; i < depth; ++i) {
      rev_endian(vp[i], wbytes);
    }
  }

  transaction(depth_t depth)
    : depth(depth), vbytes(wbytes*depth), tbytes(dbytes+vbytes),
      p(new char[tbytes]) {
    *(depth_t*)p = depth;
    vp = (p_dat) (p+dbytes);
  }

  template<size_t psize>
  void import(char* param, depth_t num, int64_t offset) {
    param -= offset*psize;
    for (depth_t i = 0; i < num; ++i) {
      memcpy(vp[i], param, wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[i], wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num, int64_t skip) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[skip+i], wbytes);
      param += psize;
    }
  }

  ~transaction() { if (p) { delete[] p; } }
};
      

inline const std::string begin_str(int num)
{
  return std::string("[[transaction]] ")
         .append(std::to_string(num))
         .append("\n");
}

inline const std::string end_str()
{
  return std::string("[[/transaction]] \n");
}
      
class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  firstVector_arr_depth = 0;
  secondVector_arr_depth = 0;
  resultVecror_arr_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{firstVector_arr " << firstVector_arr_depth << "}\n";
  total_list << "{secondVector_arr " << secondVector_arr_depth << "}\n";
  total_list << "{resultVecror_arr " << resultVecror_arr_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int firstVector_arr_depth;
    int secondVector_arr_depth;
    int resultVecror_arr_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static bool RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool err = false;
  size_t x_found;

  // search and replace 'X' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('X', 0)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  // search and replace 'x' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('x', 2)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  return err;}
extern "C" void lab4_z1_hw_stub_wrapper(volatile void *, volatile void *, volatile void *);

extern "C" void apatb_lab4_z1_hw(volatile void * __xlx_apatb_param_firstVector_arr, volatile void * __xlx_apatb_param_secondVector_arr, volatile void * __xlx_apatb_param_resultVecror_arr) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
static AESL_FILE_HANDLER aesl_fh;
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;
#ifdef USE_BINARY_TV_FILE
{
transaction<32> tr(4);
aesl_fh.read(AUTOTB_TVOUT_PC_resultVecror_arr, tr.p, tr.tbytes);
tr.reorder();
tr.send<4>((char*)__xlx_apatb_param_resultVecror_arr, 4);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_resultVecror_arr);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > resultVecror_arr_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "resultVecror_arr");
  
            // push token into output port buffer
            if (AESL_token != "") {
              resultVecror_arr_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "resultVecror_arr" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_resultVecror_arr)[j*4+0] = resultVecror_arr_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_resultVecror_arr)[j*4+1] = resultVecror_arr_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_resultVecror_arr)[j*4+2] = resultVecror_arr_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_resultVecror_arr)[j*4+3] = resultVecror_arr_pc_buffer[i].range(31, 24).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  #endif

    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_firstVector_arr = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_firstVector_arr, 'b');
transaction<16> tr(4);
  __xlx_offset_byte_param_firstVector_arr = 0*2;
  if (__xlx_apatb_param_firstVector_arr) {
tr.import<2>((char*)__xlx_apatb_param_firstVector_arr, 4, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_firstVector_arr, tr.p, tr.tbytes);
}

  tcl_file.set_num(4, &tcl_file.firstVector_arr_depth);
#else
// print firstVector_arr Transactions
{
aesl_fh.write(AUTOTB_TVIN_firstVector_arr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_firstVector_arr = 0*2;
  if (__xlx_apatb_param_firstVector_arr) {
    for (int j = 0  - 0, e = 4 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_firstVector_arr)[j];
aesl_fh.write(AUTOTB_TVIN_firstVector_arr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(4, &tcl_file.firstVector_arr_depth);
aesl_fh.write(AUTOTB_TVIN_firstVector_arr, end_str());
}

#endif
unsigned __xlx_offset_byte_param_secondVector_arr = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_secondVector_arr, 'b');
transaction<16> tr(4);
  __xlx_offset_byte_param_secondVector_arr = 0*2;
  if (__xlx_apatb_param_secondVector_arr) {
tr.import<2>((char*)__xlx_apatb_param_secondVector_arr, 4, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_secondVector_arr, tr.p, tr.tbytes);
}

  tcl_file.set_num(4, &tcl_file.secondVector_arr_depth);
#else
// print secondVector_arr Transactions
{
aesl_fh.write(AUTOTB_TVIN_secondVector_arr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_secondVector_arr = 0*2;
  if (__xlx_apatb_param_secondVector_arr) {
    for (int j = 0  - 0, e = 4 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_secondVector_arr)[j];
aesl_fh.write(AUTOTB_TVIN_secondVector_arr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(4, &tcl_file.secondVector_arr_depth);
aesl_fh.write(AUTOTB_TVIN_secondVector_arr, end_str());
}

#endif
unsigned __xlx_offset_byte_param_resultVecror_arr = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_resultVecror_arr, 'b');
transaction<32> tr(4);
  __xlx_offset_byte_param_resultVecror_arr = 0*4;
  if (__xlx_apatb_param_resultVecror_arr) {
tr.import<4>((char*)__xlx_apatb_param_resultVecror_arr, 4, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_resultVecror_arr, tr.p, tr.tbytes);
}

  tcl_file.set_num(4, &tcl_file.resultVecror_arr_depth);
#else
// print resultVecror_arr Transactions
{
aesl_fh.write(AUTOTB_TVIN_resultVecror_arr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_resultVecror_arr = 0*4;
  if (__xlx_apatb_param_resultVecror_arr) {
    for (int j = 0  - 0, e = 4 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_resultVecror_arr)[j];
aesl_fh.write(AUTOTB_TVIN_resultVecror_arr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(4, &tcl_file.resultVecror_arr_depth);
aesl_fh.write(AUTOTB_TVIN_resultVecror_arr, end_str());
}

#endif
CodeState = CALL_C_DUT;
lab4_z1_hw_stub_wrapper(__xlx_apatb_param_firstVector_arr, __xlx_apatb_param_secondVector_arr, __xlx_apatb_param_resultVecror_arr);
CodeState = DUMP_OUTPUTS;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_resultVecror_arr, 'b');
transaction<32> tr(4);
  __xlx_offset_byte_param_resultVecror_arr = 0*4;
  if (__xlx_apatb_param_resultVecror_arr) {
tr.import<4>((char*)__xlx_apatb_param_resultVecror_arr, 4, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVOUT_resultVecror_arr, tr.p, tr.tbytes);
}

  tcl_file.set_num(4, &tcl_file.resultVecror_arr_depth);
#else
// print resultVecror_arr Transactions
{
aesl_fh.write(AUTOTB_TVOUT_resultVecror_arr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_resultVecror_arr = 0*4;
  if (__xlx_apatb_param_resultVecror_arr) {
    for (int j = 0  - 0, e = 4 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_resultVecror_arr)[j];
aesl_fh.write(AUTOTB_TVOUT_resultVecror_arr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(4, &tcl_file.resultVecror_arr_depth);
aesl_fh.write(AUTOTB_TVOUT_resultVecror_arr, end_str());
}

#endif
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
