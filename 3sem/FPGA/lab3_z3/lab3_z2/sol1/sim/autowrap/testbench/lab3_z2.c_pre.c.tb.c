// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "D:/Labs/3sem/FPGA/lab3_z3/source/lab3_z2.c"
# 1 "D:/Labs/3sem/FPGA/lab3_z3/source/lab3_z2.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Labs/3sem/FPGA/lab3_z3/source/lab3_z2.c" 2
# 1 "D:/Labs/3sem/FPGA/lab3_z3/source/lab3_z2.h" 1



typedef short data_sc;

void lab3_z2 (data_sc inA_ar[4096], data_sc out_ar[4096]);
# 2 "D:/Labs/3sem/FPGA/lab3_z3/source/lab3_z2.c" 2

void lab3_z2(data_sc inA_ar[4096], data_sc out_ar[4096])
{
 int i;
 data_sc temp;
 for (i = 0; i < 4096; i++)
 {
#pragma HLS PIPELINE off
 temp = inA_ar[i];
  out_ar[temp] = out_ar[temp] + 1;
 }
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_lab3_z2_ir(short *, short *);
#ifdef __cplusplus
extern "C"
#endif
void lab3_z2_hw_stub(short *inA_ar, short *out_ar){
lab3_z2(inA_ar, out_ar);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_lab3_z2_sw(short *inA_ar, short *out_ar){
apatb_lab3_z2_ir(inA_ar, out_ar);
return ;
}
#endif
# 13 "D:/Labs/3sem/FPGA/lab3_z3/source/lab3_z2.c"

