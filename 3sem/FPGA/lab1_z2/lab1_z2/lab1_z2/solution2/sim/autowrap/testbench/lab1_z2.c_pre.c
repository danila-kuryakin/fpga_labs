# 1 "D:/Labs/3sem/FPGA/lab1_z2/lab1_z2/lab1_z2/source/lab1_z2.c"
# 1 "D:/Labs/3sem/FPGA/lab1_z2/lab1_z2/lab1_z2/source/lab1_z2.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Labs/3sem/FPGA/lab1_z2/lab1_z2/lab1_z2/source/lab1_z2.c" 2
# 1 "D:/Labs/3sem/FPGA/lab1_z2/lab1_z2/lab1_z2/source/lab1_z2.h" 1


typedef short din_type;
typedef int dout_type;

void lab1_z2(din_type inArr[3], din_type a,
  din_type b, din_type c, dout_type outArr[3]);
# 2 "D:/Labs/3sem/FPGA/lab1_z2/lab1_z2/lab1_z2/source/lab1_z2.c" 2

void lab1_z2(din_type inArr[3], din_type a,
  din_type b, din_type c, dout_type outArr[3])
{
 din_type x;
 dout_type y;
 for(int i = 0; i < 3; i++)
 {
#pragma HLS PIPELINE off
 x =inArr[i];
  y = x + a + b + c;
  outArr[i] = y;
 }
}
