#include "lab2_z0.h"

void lab2_z0 (din_type in_a[ROWS], din_type in_b[ROWS], dout_type res[ROWS])
{
	din_type tmp_a, tmp_b;
	dout_type tmp_res;
	for(int i = 0; i < ROWS; i++) 
	{
		#pragma HLS PIPELINE off
		tmp_a 	= in_a[i];
		tmp_b 	= in_b[i];

		tmp_res = tmp_a + tmp_b;

		res[i] 	= tmp_res;
	}
}

