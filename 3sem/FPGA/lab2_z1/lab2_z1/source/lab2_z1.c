#include "lab2_z1.h"

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
