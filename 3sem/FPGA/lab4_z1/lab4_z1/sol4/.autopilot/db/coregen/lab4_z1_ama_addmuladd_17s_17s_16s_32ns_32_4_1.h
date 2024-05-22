// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1__HH__
#define __lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1__HH__
#include "lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0.h"
#include <systemc>

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int din2_WIDTH,
    int din3_WIDTH,
    int dout_WIDTH>
SC_MODULE(lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1) {
    sc_core::sc_in_clk clk;
    sc_core::sc_in<sc_dt::sc_logic> reset;
    sc_core::sc_in<sc_dt::sc_logic> ce;
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_in< sc_dt::sc_lv<din2_WIDTH> >   din2;
    sc_core::sc_in< sc_dt::sc_lv<din3_WIDTH> >   din3;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0 lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U;

    SC_CTOR(lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1):  lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U ("lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U") {
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.clk(clk);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.rst(reset);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.ce(ce);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.in0(din0);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.in1(din1);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.in2(din2);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.in3(din3);
        lab4_z1_ama_addmuladd_17s_17s_16s_32ns_32_4_1_DSP48_0_U.dout(dout);

    }

};

#endif //
