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
