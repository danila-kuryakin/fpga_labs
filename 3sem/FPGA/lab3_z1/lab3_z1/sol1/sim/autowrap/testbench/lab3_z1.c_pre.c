# 1 "D:/Labs/3sem/FPGA/lab3_z1/lab3_z1/source/lab3_z1.c"
# 1 "D:/Labs/3sem/FPGA/lab3_z1/lab3_z1/source/lab3_z1.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "D:/Labs/3sem/FPGA/lab3_z1/lab3_z1/source/lab3_z1.c" 2
# 1 "D:/Labs/3sem/FPGA/lab3_z1/lab3_z1/source/lab3_z1.h" 1


typedef short data_in, pnt_in;
typedef int pnt_out, data_ret;

data_ret lab3_z1 (data_in inA, data_in inB, pnt_in *inC, pnt_out *res);
# 2 "D:/Labs/3sem/FPGA/lab3_z1/lab3_z1/source/lab3_z1.c" 2

data_ret lab3_z1 (data_in inA, data_in inB, pnt_in *inC, pnt_out *res)
{
 data_ret temp;
 temp = inA * *inC;
 *res = temp + inB;
 return temp;
}
