#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void lab1_z2(short*, short, short, short, int*);
extern "C" void apatb_lab1_z2_hw(volatile void * __xlx_apatb_param_inArr, short __xlx_apatb_param_a, short __xlx_apatb_param_b, short __xlx_apatb_param_c, volatile void * __xlx_apatb_param_outArr) {
  // Collect __xlx_inArr__tmp_vec
  vector<sc_bv<16> >__xlx_inArr__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<16> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_inArr)[j*2+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_inArr)[j*2+1];
    __xlx_inArr__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_inArr = 3;
  int __xlx_offset_param_inArr = 0;
  int __xlx_offset_byte_param_inArr = 0*2;
  short* __xlx_inArr__input_buffer= new short[__xlx_inArr__tmp_vec.size()];
  for (int i = 0; i < __xlx_inArr__tmp_vec.size(); ++i) {
    __xlx_inArr__input_buffer[i] = __xlx_inArr__tmp_vec[i].range(15, 0).to_uint64();
  }
  // Collect __xlx_outArr__tmp_vec
  vector<sc_bv<32> >__xlx_outArr__tmp_vec;
  for (int j = 0, e = 3; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_outArr)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_outArr)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_outArr)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_outArr)[j*4+3];
    __xlx_outArr__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_outArr = 3;
  int __xlx_offset_param_outArr = 0;
  int __xlx_offset_byte_param_outArr = 0*4;
  int* __xlx_outArr__input_buffer= new int[__xlx_outArr__tmp_vec.size()];
  for (int i = 0; i < __xlx_outArr__tmp_vec.size(); ++i) {
    __xlx_outArr__input_buffer[i] = __xlx_outArr__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  lab1_z2(__xlx_inArr__input_buffer, __xlx_apatb_param_a, __xlx_apatb_param_b, __xlx_apatb_param_c, __xlx_outArr__input_buffer);
// print __xlx_apatb_param_inArr
  sc_bv<16>*__xlx_inArr_output_buffer = new sc_bv<16>[__xlx_size_param_inArr];
  for (int i = 0; i < __xlx_size_param_inArr; ++i) {
    __xlx_inArr_output_buffer[i] = __xlx_inArr__input_buffer[i+__xlx_offset_param_inArr];
  }
  for (int i = 0; i < __xlx_size_param_inArr; ++i) {
    ((char*)__xlx_apatb_param_inArr)[i*2+0] = __xlx_inArr_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_inArr)[i*2+1] = __xlx_inArr_output_buffer[i].range(15, 8).to_uint();
  }
// print __xlx_apatb_param_outArr
  sc_bv<32>*__xlx_outArr_output_buffer = new sc_bv<32>[__xlx_size_param_outArr];
  for (int i = 0; i < __xlx_size_param_outArr; ++i) {
    __xlx_outArr_output_buffer[i] = __xlx_outArr__input_buffer[i+__xlx_offset_param_outArr];
  }
  for (int i = 0; i < __xlx_size_param_outArr; ++i) {
    ((char*)__xlx_apatb_param_outArr)[i*4+0] = __xlx_outArr_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_outArr)[i*4+1] = __xlx_outArr_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_outArr)[i*4+2] = __xlx_outArr_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_outArr)[i*4+3] = __xlx_outArr_output_buffer[i].range(31, 24).to_uint();
  }
}
