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
#define AUTOTB_TVIN_inArr "../tv/cdatafile/c.lab1_z2.autotvin_inArr.dat"
#define AUTOTB_TVOUT_inArr "../tv/cdatafile/c.lab1_z2.autotvout_inArr.dat"
// wrapc file define:
#define AUTOTB_TVIN_a "../tv/cdatafile/c.lab1_z2.autotvin_a.dat"
#define AUTOTB_TVOUT_a "../tv/cdatafile/c.lab1_z2.autotvout_a.dat"
// wrapc file define:
#define AUTOTB_TVIN_b "../tv/cdatafile/c.lab1_z2.autotvin_b.dat"
#define AUTOTB_TVOUT_b "../tv/cdatafile/c.lab1_z2.autotvout_b.dat"
// wrapc file define:
#define AUTOTB_TVIN_c "../tv/cdatafile/c.lab1_z2.autotvin_c.dat"
#define AUTOTB_TVOUT_c "../tv/cdatafile/c.lab1_z2.autotvout_c.dat"
// wrapc file define:
#define AUTOTB_TVIN_outArr "../tv/cdatafile/c.lab1_z2.autotvin_outArr.dat"
#define AUTOTB_TVOUT_outArr "../tv/cdatafile/c.lab1_z2.autotvout_outArr.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_inArr "../tv/rtldatafile/rtl.lab1_z2.autotvout_inArr.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_a "../tv/rtldatafile/rtl.lab1_z2.autotvout_a.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_b "../tv/rtldatafile/rtl.lab1_z2.autotvout_b.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_c "../tv/rtldatafile/rtl.lab1_z2.autotvout_c.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_outArr "../tv/rtldatafile/rtl.lab1_z2.autotvout_outArr.dat"


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
  inArr_depth = 0;
  a_depth = 0;
  b_depth = 0;
  c_depth = 0;
  outArr_depth = 0;
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
  total_list << "{inArr " << inArr_depth << "}\n";
  total_list << "{a " << a_depth << "}\n";
  total_list << "{b " << b_depth << "}\n";
  total_list << "{c " << c_depth << "}\n";
  total_list << "{outArr " << outArr_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int inArr_depth;
    int a_depth;
    int b_depth;
    int c_depth;
    int outArr_depth;
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
extern "C" void lab1_z2_hw_stub_wrapper(volatile void *, short, short, short, volatile void *);

extern "C" void apatb_lab1_z2_hw(volatile void * __xlx_apatb_param_inArr, short __xlx_apatb_param_a, short __xlx_apatb_param_b, short __xlx_apatb_param_c, volatile void * __xlx_apatb_param_outArr) {
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
transaction<32> tr(3);
aesl_fh.read(AUTOTB_TVOUT_PC_outArr, tr.p, tr.tbytes);
tr.reorder();
tr.send<4>((char*)__xlx_apatb_param_outArr, 3);
}
#else
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outArr);
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
          std::vector<sc_bv<32> > outArr_pc_buffer(3);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outArr");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outArr_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outArr" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 3; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_outArr)[j*4+0] = outArr_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_outArr)[j*4+1] = outArr_pc_buffer[i].range(15, 8).to_int64();
((char*)__xlx_apatb_param_outArr)[j*4+2] = outArr_pc_buffer[i].range(23, 16).to_int64();
((char*)__xlx_apatb_param_outArr)[j*4+3] = outArr_pc_buffer[i].range(31, 24).to_int64();
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
unsigned __xlx_offset_byte_param_inArr = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_inArr, 'b');
transaction<16> tr(3);
  __xlx_offset_byte_param_inArr = 0*2;
  if (__xlx_apatb_param_inArr) {
tr.import<2>((char*)__xlx_apatb_param_inArr, 3, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_inArr, tr.p, tr.tbytes);
}

  tcl_file.set_num(3, &tcl_file.inArr_depth);
#else
// print inArr Transactions
{
aesl_fh.write(AUTOTB_TVIN_inArr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_inArr = 0*2;
  if (__xlx_apatb_param_inArr) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_inArr)[j];
aesl_fh.write(AUTOTB_TVIN_inArr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(3, &tcl_file.inArr_depth);
aesl_fh.write(AUTOTB_TVIN_inArr, end_str());
}

#endif
// print a Transactions
{
aesl_fh.write(AUTOTB_TVIN_a, begin_str(AESL_transaction));
{
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_a);
aesl_fh.write(AUTOTB_TVIN_a, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.a_depth);
aesl_fh.write(AUTOTB_TVIN_a, end_str());
}

// print b Transactions
{
aesl_fh.write(AUTOTB_TVIN_b, begin_str(AESL_transaction));
{
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_b);
aesl_fh.write(AUTOTB_TVIN_b, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.b_depth);
aesl_fh.write(AUTOTB_TVIN_b, end_str());
}

// print c Transactions
{
aesl_fh.write(AUTOTB_TVIN_c, begin_str(AESL_transaction));
{
    sc_bv<16> __xlx_tmp_lv = *((short*)&__xlx_apatb_param_c);
aesl_fh.write(AUTOTB_TVIN_c, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.c_depth);
aesl_fh.write(AUTOTB_TVIN_c, end_str());
}

unsigned __xlx_offset_byte_param_outArr = 0;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVIN_outArr, 'b');
transaction<32> tr(3);
  __xlx_offset_byte_param_outArr = 0*4;
  if (__xlx_apatb_param_outArr) {
tr.import<4>((char*)__xlx_apatb_param_outArr, 3, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVIN_outArr, tr.p, tr.tbytes);
}

  tcl_file.set_num(3, &tcl_file.outArr_depth);
#else
// print outArr Transactions
{
aesl_fh.write(AUTOTB_TVIN_outArr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_outArr = 0*4;
  if (__xlx_apatb_param_outArr) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_outArr)[j];
aesl_fh.write(AUTOTB_TVIN_outArr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(3, &tcl_file.outArr_depth);
aesl_fh.write(AUTOTB_TVIN_outArr, end_str());
}

#endif
CodeState = CALL_C_DUT;
lab1_z2_hw_stub_wrapper(__xlx_apatb_param_inArr, __xlx_apatb_param_a, __xlx_apatb_param_b, __xlx_apatb_param_c, __xlx_apatb_param_outArr);
CodeState = DUMP_OUTPUTS;
#ifdef USE_BINARY_TV_FILE
{
aesl_fh.touch(AUTOTB_TVOUT_outArr, 'b');
transaction<32> tr(3);
  __xlx_offset_byte_param_outArr = 0*4;
  if (__xlx_apatb_param_outArr) {
tr.import<4>((char*)__xlx_apatb_param_outArr, 3, 0);
  }
tr.reorder();
aesl_fh.write(AUTOTB_TVOUT_outArr, tr.p, tr.tbytes);
}

  tcl_file.set_num(3, &tcl_file.outArr_depth);
#else
// print outArr Transactions
{
aesl_fh.write(AUTOTB_TVOUT_outArr, begin_str(AESL_transaction));
{
  __xlx_offset_byte_param_outArr = 0*4;
  if (__xlx_apatb_param_outArr) {
    for (int j = 0  - 0, e = 3 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_outArr)[j];
aesl_fh.write(AUTOTB_TVOUT_outArr, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
    }
  }
}

  tcl_file.set_num(3, &tcl_file.outArr_depth);
aesl_fh.write(AUTOTB_TVOUT_outArr, end_str());
}

#endif
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
