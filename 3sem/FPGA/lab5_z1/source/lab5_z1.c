#include "lab5_z1.h"
#include <stdio.h>

void split(int_arr in[N], int_arr out1[N], int_arr out2[N])
{
L1:
	for (int i = 0; i < N; i++)
	{
		#pragma HLS pipeline off
		out1[i] = in[i];
		out2[i] = in[i];
	}
}

void foo_m(int data_in[N], int scale, int data_out1[N], int data_out2[N])
{
	int temp1[N], temp2[N], temp3[N];

Loop1:
	for (int i = 0; i < N; i++)
	{
		#pragma HLS pipeline off
		temp1[i] = data_in[i] * scale;
	}

	split(temp1, temp2, temp3);

Loop2:
	for (int j = 0; j < N; j++)
	{
		#pragma HLS pipeline off
		data_out1[j] = temp2[j] * 22;
	}
Loop3:
	for (int k = 0; k < N; k++)
	{
		#pragma HLS pipeline off
		data_out2[k] = temp3[k] * 33;
	}
}
