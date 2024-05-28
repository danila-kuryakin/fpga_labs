#include <stdio.h>
#include "lab1_z2.h"

int arentEqual(dout_type expectedArr[ROWS],
		dout_type actualArr[ROWS])
{
	for(int i = 0;i < ROWS; i++)
		if (expectedArr[i] != actualArr[i])
		{
			fprintf(stdout, "ERROR: expected=%d actual=%d for ROW: %d \n",
					expectedArr[i], actualArr[i], i);
			return 1;
		}
	return 0;
}

int main()
{
	din_type inA, inB, inC;
	din_type inArr[ROWS];
	dout_type expectedArr[ROWS], actualArr[ROWS];

	int pass = 0;
	for (int i = 0; i < 3; i++)
	{
		inA = rand() % 100;
		inB = rand() % 100;
		inC = rand() % 100;
		for (int j=0; j<ROWS; j++)
		{
			inArr [j] = rand() % 1000;
			actualArr[j] = 0;
		}

		lab1_z2(inArr, inA, inB, inC, actualArr);

		for (int i=0; i<ROWS; i++)
			expectedArr[i] = inArr[i] + inA + inB + inC;

		if (arentEqual(expectedArr, actualArr))
			pass = 1;
	}
	if (!pass)
		fprintf(stdout,"--------------Pass!-------------\n");
	else
		fprintf(stderr, "-------------Fail!-------------\n");
	return pass;
}


