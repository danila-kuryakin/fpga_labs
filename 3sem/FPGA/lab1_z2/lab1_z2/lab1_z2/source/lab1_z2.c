#include"lab1_z2.h"

void lab1_z2(din_type inArr[ROWS], din_type a,
		din_type b, din_type c, dout_type outArr[ROWS])
{
	din_type x;
	dout_type y;
	for(int i = 0; i < ROWS; i++)
	{
		#pragma HLS PIPELINE off
		x =inArr[i];
		y = x + a + b + c;
		outArr[i] = y;
	}
}


