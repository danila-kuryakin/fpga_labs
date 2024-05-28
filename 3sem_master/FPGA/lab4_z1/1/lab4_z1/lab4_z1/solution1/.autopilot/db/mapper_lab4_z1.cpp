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
extern "C" void lab4_z1(short*, short*, int*);
extern "C" void apatb_lab4_z1_hw(volatile void * __xlx_apatb_param_firstVector_arr, volatile void * __xlx_apatb_param_secondVector_arr, volatile void * __xlx_apatb_param_resultVecror_arr) {
  // Collect __xlx_firstVector_arr__tmp_vec
  vector<sc_bv<16> >__xlx_firstVector_arr__tmp_vec;
  for (int j = 0, e = 4; j != e; ++j) {
    sc_bv<16> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_firstVector_arr)[j*2+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_firstVector_arr)[j*2+1];
    __xlx_firstVector_arr__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_firstVector_arr = 4;
  int __xlx_offset_param_firstVector_arr = 0;
  int __xlx_offset_byte_param_firstVector_arr = 0*2;
  short* __xlx_firstVector_arr__input_buffer= new short[__xlx_firstVector_arr__tmp_vec.size()];
  for (int i = 0; i < __xlx_firstVector_arr__tmp_vec.size(); ++i) {
    __xlx_firstVector_arr__input_buffer[i] = __xlx_firstVector_arr__tmp_vec[i].range(15, 0).to_uint64();
  }
  // Collect __xlx_secondVector_arr__tmp_vec
  vector<sc_bv<16> >__xlx_secondVector_arr__tmp_vec;
  for (int j = 0, e = 4; j != e; ++j) {
    sc_bv<16> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_secondVector_arr)[j*2+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_secondVector_arr)[j*2+1];
    __xlx_secondVector_arr__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_secondVector_arr = 4;
  int __xlx_offset_param_secondVector_arr = 0;
  int __xlx_offset_byte_param_secondVector_arr = 0*2;
  short* __xlx_secondVector_arr__input_buffer= new short[__xlx_secondVector_arr__tmp_vec.size()];
  for (int i = 0; i < __xlx_secondVector_arr__tmp_vec.size(); ++i) {
    __xlx_secondVector_arr__input_buffer[i] = __xlx_secondVector_arr__tmp_vec[i].range(15, 0).to_uint64();
  }
  // Collect __xlx_resultVecror_arr__tmp_vec
  vector<sc_bv<32> >__xlx_resultVecror_arr__tmp_vec;
  for (int j = 0, e = 4; j != e; ++j) {
    sc_bv<32> _xlx_tmp_sc;
    _xlx_tmp_sc.range(7, 0) = ((char*)__xlx_apatb_param_resultVecror_arr)[j*4+0];
    _xlx_tmp_sc.range(15, 8) = ((char*)__xlx_apatb_param_resultVecror_arr)[j*4+1];
    _xlx_tmp_sc.range(23, 16) = ((char*)__xlx_apatb_param_resultVecror_arr)[j*4+2];
    _xlx_tmp_sc.range(31, 24) = ((char*)__xlx_apatb_param_resultVecror_arr)[j*4+3];
    __xlx_resultVecror_arr__tmp_vec.push_back(_xlx_tmp_sc);
  }
  int __xlx_size_param_resultVecror_arr = 4;
  int __xlx_offset_param_resultVecror_arr = 0;
  int __xlx_offset_byte_param_resultVecror_arr = 0*4;
  int* __xlx_resultVecror_arr__input_buffer= new int[__xlx_resultVecror_arr__tmp_vec.size()];
  for (int i = 0; i < __xlx_resultVecror_arr__tmp_vec.size(); ++i) {
    __xlx_resultVecror_arr__input_buffer[i] = __xlx_resultVecror_arr__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  lab4_z1(__xlx_firstVector_arr__input_buffer, __xlx_secondVector_arr__input_buffer, __xlx_resultVecror_arr__input_buffer);
// print __xlx_apatb_param_firstVector_arr
  sc_bv<16>*__xlx_firstVector_arr_output_buffer = new sc_bv<16>[__xlx_size_param_firstVector_arr];
  for (int i = 0; i < __xlx_size_param_firstVector_arr; ++i) {
    __xlx_firstVector_arr_output_buffer[i] = __xlx_firstVector_arr__input_buffer[i+__xlx_offset_param_firstVector_arr];
  }
  for (int i = 0; i < __xlx_size_param_firstVector_arr; ++i) {
    ((char*)__xlx_apatb_param_firstVector_arr)[i*2+0] = __xlx_firstVector_arr_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_firstVector_arr)[i*2+1] = __xlx_firstVector_arr_output_buffer[i].range(15, 8).to_uint();
  }
// print __xlx_apatb_param_secondVector_arr
  sc_bv<16>*__xlx_secondVector_arr_output_buffer = new sc_bv<16>[__xlx_size_param_secondVector_arr];
  for (int i = 0; i < __xlx_size_param_secondVector_arr; ++i) {
    __xlx_secondVector_arr_output_buffer[i] = __xlx_secondVector_arr__input_buffer[i+__xlx_offset_param_secondVector_arr];
  }
  for (int i = 0; i < __xlx_size_param_secondVector_arr; ++i) {
    ((char*)__xlx_apatb_param_secondVector_arr)[i*2+0] = __xlx_secondVector_arr_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_secondVector_arr)[i*2+1] = __xlx_secondVector_arr_output_buffer[i].range(15, 8).to_uint();
  }
// print __xlx_apatb_param_resultVecror_arr
  sc_bv<32>*__xlx_resultVecror_arr_output_buffer = new sc_bv<32>[__xlx_size_param_resultVecror_arr];
  for (int i = 0; i < __xlx_size_param_resultVecror_arr; ++i) {
    __xlx_resultVecror_arr_output_buffer[i] = __xlx_resultVecror_arr__input_buffer[i+__xlx_offset_param_resultVecror_arr];
  }
  for (int i = 0; i < __xlx_size_param_resultVecror_arr; ++i) {
    ((char*)__xlx_apatb_param_resultVecror_arr)[i*4+0] = __xlx_resultVecror_arr_output_buffer[i].range(7, 0).to_uint();
    ((char*)__xlx_apatb_param_resultVecror_arr)[i*4+1] = __xlx_resultVecror_arr_output_buffer[i].range(15, 8).to_uint();
    ((char*)__xlx_apatb_param_resultVecror_arr)[i*4+2] = __xlx_resultVecror_arr_output_buffer[i].range(23, 16).to_uint();
    ((char*)__xlx_apatb_param_resultVecror_arr)[i*4+3] = __xlx_resultVecror_arr_output_buffer[i].range(31, 24).to_uint();
  }
}
