#include "lab4_z1.h"
#include <stdio.h>

void lab4_z1(data_in firstVector_arr[N], data_in secondVector_arr[N], data_out resultVecror_arr[N])
{
	int i, j;

L2:
	for (i = 0; i < N; i++)
	{
	L1:
		for (j = 0; j < N; j++)
		{
			resultVecror_arr[i] += firstVector_arr[j] * secondVector_arr[i];
		}
	}
}
