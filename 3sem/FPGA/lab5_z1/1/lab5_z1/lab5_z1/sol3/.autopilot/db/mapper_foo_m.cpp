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
extern "C" void foo_m(int*, int, int*, int*);
extern "C" void apatb_foo_m_hw(volatile void * __xlx_apatb_param_data_in, int __xlx_apatb_param_scale, volatile void * __xlx_apatb_param_data_out1, volatile void * __xlx_apatb_param_data_out2) {
  // Collect __xlx_data_in__tmp_vec
  vector<sc_bv<32> >__xlx_data_in__tmp_vec;
  for (int j = 0, e = 16384; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_data_in)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_data_in)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_data_in)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_data_in)[j*4+3];
    __xlx_data_in__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_data_in = 16384;
  int __xlx_offset_param_data_in = 0;
  int __xlx_offset_byte_param_data_in = 0*4;
  int* __xlx_data_in__input_buffer= new int[__xlx_data_in__tmp_vec.size()];
  for (int i = 0; i < __xlx_data_in__tmp_vec.size(); ++i) {
    __xlx_data_in__input_buffer[i] = __xlx_data_in__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_data_out1__tmp_vec
  vector<sc_bv<32> >__xlx_data_out1__tmp_vec;
  for (int j = 0, e = 16384; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_data_out1)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_data_out1)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_data_out1)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_data_out1)[j*4+3];
    __xlx_data_out1__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_data_out1 = 16384;
  int __xlx_offset_param_data_out1 = 0;
  int __xlx_offset_byte_param_data_out1 = 0*4;
  int* __xlx_data_out1__input_buffer= new int[__xlx_data_out1__tmp_vec.size()];
  for (int i = 0; i < __xlx_data_out1__tmp_vec.size(); ++i) {
    __xlx_data_out1__input_buffer[i] = __xlx_data_out1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_data_out2__tmp_vec
  vector<sc_bv<32> >__xlx_data_out2__tmp_vec;
  for (int j = 0, e = 16384; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_data_out2)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_data_out2)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_data_out2)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_data_out2)[j*4+3];
    __xlx_data_out2__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_data_out2 = 16384;
  int __xlx_offset_param_data_out2 = 0;
  int __xlx_offset_byte_param_data_out2 = 0*4;
  int* __xlx_data_out2__input_buffer= new int[__xlx_data_out2__tmp_vec.size()];
  for (int i = 0; i < __xlx_data_out2__tmp_vec.size(); ++i) {
    __xlx_data_out2__input_buffer[i] = __xlx_data_out2__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  foo_m(__xlx_data_in__input_buffer, __xlx_apatb_param_scale, __xlx_data_out1__input_buffer, __xlx_data_out2__input_buffer);
// print __xlx_apatb_param_data_in
  sc_bv<32>*__xlx_data_in_output_buffer = new sc_bv<32>[__xlx_size_param_data_in];
  for (int i = 0; i < __xlx_size_param_data_in; ++i) {
    __xlx_data_in_output_buffer[i] = __xlx_data_in__input_buffer[i+__xlx_offset_param_data_in];
  }
  for (int i = 0; i < __xlx_size_param_data_in; ++i) {
    ((char*)__xlx_apatb_param_data_in)[i*4+0] = __xlx_data_in_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_data_in)[i*4+1] = __xlx_data_in_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_data_in)[i*4+2] = __xlx_data_in_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_data_in)[i*4+3] = __xlx_data_in_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_data_out1
  sc_bv<32>*__xlx_data_out1_output_buffer = new sc_bv<32>[__xlx_size_param_data_out1];
  for (int i = 0; i < __xlx_size_param_data_out1; ++i) {
    __xlx_data_out1_output_buffer[i] = __xlx_data_out1__input_buffer[i+__xlx_offset_param_data_out1];
  }
  for (int i = 0; i < __xlx_size_param_data_out1; ++i) {
    ((char*)__xlx_apatb_param_data_out1)[i*4+0] = __xlx_data_out1_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_data_out1)[i*4+1] = __xlx_data_out1_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_data_out1)[i*4+2] = __xlx_data_out1_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_data_out1)[i*4+3] = __xlx_data_out1_output_buffer[i].range(31, 24).to_uint();
  }
// print __xlx_apatb_param_data_out2
  sc_bv<32>*__xlx_data_out2_output_buffer = new sc_bv<32>[__xlx_size_param_data_out2];
  for (int i = 0; i < __xlx_size_param_data_out2; ++i) {
    __xlx_data_out2_output_buffer[i] = __xlx_data_out2__input_buffer[i+__xlx_offset_param_data_out2];
  }
  for (int i = 0; i < __xlx_size_param_data_out2; ++i) {
    ((char*)__xlx_apatb_param_data_out2)[i*4+0] = __xlx_data_out2_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_data_out2)[i*4+1] = __xlx_data_out2_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_data_out2)[i*4+2] = __xlx_data_out2_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_data_out2)[i*4+3] = __xlx_data_out2_output_buffer[i].range(31, 24).to_uint();
  }
}
