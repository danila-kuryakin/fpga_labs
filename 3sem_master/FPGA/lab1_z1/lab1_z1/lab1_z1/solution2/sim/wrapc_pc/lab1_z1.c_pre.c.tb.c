// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "D:/Labs/3sem/FPGA/lab1_z1/lab1_z1/source/lab1_z1.c"
# 1 "D:/Labs/3sem/FPGA/lab1_z1/lab1_z1/source/lab1_z1.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Labs/3sem/FPGA/lab1_z1/lab1_z1/source/lab1_z1.c" 2
# 1 "D:/Labs/3sem/FPGA/lab1_z1/lab1_z1/source/lab1_z1.h" 1
typedef short din_type;
typedef int dout_type;


dout_type lab1_z1(din_type a, din_type b, din_type c, din_type d);
# 2 "D:/Labs/3sem/FPGA/lab1_z1/lab1_z1/source/lab1_z1.c" 2
dout_type lab1_z1(din_type a, din_type b, din_type c, din_type d)
{
 dout_type y;
 y = a + b + c - d;
 return y;
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
int apatb_lab1_z1_ir(short, short, short, short);
#ifdef __cplusplus
extern "C"
#endif
int lab1_z1_hw_stub(short a, short b, short c, short d){
int _ret = lab1_z1(a, b, c, d);
return _ret;
}
#ifdef __cplusplus
extern "C"
#endif
int apatb_lab1_z1_sw(short a, short b, short c, short d){
int _ret = apatb_lab1_z1_ir(a, b, c, d);
return _ret;
}
#endif
# 7 "D:/Labs/3sem/FPGA/lab1_z1/lab1_z1/source/lab1_z1.c"

