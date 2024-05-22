# include "lab3_z1.h"

data_ret lab3_z1 (data_in inA, data_in inB, pnt_in *inC, pnt_out *res)
{
	data_ret temp;
	temp = inA * *inC;
	*res = temp + inB;
	return temp;
}
