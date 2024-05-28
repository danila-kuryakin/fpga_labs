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
