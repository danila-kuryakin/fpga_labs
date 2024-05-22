// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "D:/Labs/3sem/FPGA/lab2_z0/lab2_z0/source/lab2_z0.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 365 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Labs/3sem/FPGA/lab2_z0/lab2_z0/source/lab2_z0.c" 2
# 1 "D:/Labs/3sem/FPGA/lab2_z0/lab2_z0/source/lab2_z0.h" 1


typedef short din_type;
typedef int dout_type;


void lab2_z0 (din_type in_a[3], din_type in_b[3], dout_type res[3]);
# 2 "D:/Labs/3sem/FPGA/lab2_z0/lab2_z0/source/lab2_z0.c" 2

void lab2_z0 (din_type in_a[3], din_type in_b[3], dout_type res[3])
{
 din_type tmp_a, tmp_b;
 dout_type tmp_res;
 for(int i = 0; i < 3; i++)
 {
#pragma HLS PIPELINE off
 tmp_a = in_a[i];
  tmp_b = in_b[i];

  tmp_res = tmp_a + tmp_b;

  res[i] = tmp_res;
 }
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
void apatb_lab2_z0_ir(short *, short *, int *);
#ifdef __cplusplus
extern "C"
#endif
void lab2_z0_hw_stub(short *in_a, short *in_b, int *res){
lab2_z0(in_a, in_b, res);
return ;
}
#ifdef __cplusplus
extern "C"
#endif
void apatb_lab2_z0_sw(short *in_a, short *in_b, int *res){
apatb_lab2_z0_ir(in_a, in_b, res);
return ;
}
#endif
# 17 "D:/Labs/3sem/FPGA/lab2_z0/lab2_z0/source/lab2_z0.c"

