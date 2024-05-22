#include "lab3_z2.h"

void lab3_z2(data_sc inA_ar[N], data_sc out_ar[M])
{
	int i;
	data_sc temp;
	for (i = 0; i < N; i++)
	{
        #pragma HLS PIPELINE off
		temp = inA_ar[i];
		out_ar[temp] = out_ar[temp] + 1;
	}
}
