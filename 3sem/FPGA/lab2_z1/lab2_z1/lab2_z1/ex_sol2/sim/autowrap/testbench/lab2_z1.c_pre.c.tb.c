// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "D:/Labs/3sem/FPGA/lab2_z1/lab2_z1/source/lab2_z1.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 365 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Labs/3sem/FPGA/lab2_z1/lab2_z1/source/lab2_z1.c" 2
# 1 "D:/Labs/3sem/FPGA/lab2_z1/lab2_z1/source/lab2_z1.h" 1


typedef short din_type;
typedef int dout_type;

dout_type lab2_z1 (din_type in);
# 2 "D:/Labs/3sem/FPGA/lab2_z1/lab2_z1/source/lab2_z1.c" 2

dout_type lab2_z1 (din_type in)
{
 dout_type res = 1;
 for(int i = 1; i <= in; i++)
 {
#pragma HLS PIPELINE off
#pragma HLS LOOP_TRIPCOUNT max=12
 res = res * i;
 }
 return res;
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
int apatb_lab2_z1_ir(short);
#ifdef __cplusplus
extern "C"
#endif
int lab2_z1_hw_stub(short in){
int _ret = lab2_z1(in);
return _ret;
}
#ifdef __cplusplus
extern "C"
#endif
int apatb_lab2_z1_sw(short in){
int _ret = apatb_lab2_z1_ir(in);
return _ret;
}
#endif
# 13 "D:/Labs/3sem/FPGA/lab2_z1/lab2_z1/source/lab2_z1.c"

