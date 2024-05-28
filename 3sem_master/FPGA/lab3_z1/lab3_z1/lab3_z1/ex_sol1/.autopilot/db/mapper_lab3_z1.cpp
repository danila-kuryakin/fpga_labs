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
extern "C" int lab3_z1(short, short, volatile void *, volatile void *);
extern "C" int apatb_lab3_z1_hw(short __xlx_apatb_param_inA, short __xlx_apatb_param_inB, volatile void * __xlx_apatb_param_inC, volatile void * __xlx_apatb_param_res) {
  // DUT call
  int ap_return = lab3_z1(__xlx_apatb_param_inA, __xlx_apatb_param_inB, __xlx_apatb_param_inC, __xlx_apatb_param_res);
return ap_return;
}
