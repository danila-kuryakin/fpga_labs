#include <stdio.h>
#include "lab2_z0.h"

//function for comparing expected and actual results in arrays
int arentEqual(dout_type expectedArr[ROWS], dout_type actualArr[ROWS])
{
    // Linearly compare elements 
    for (int i = 0; i < ROWS; i++)
        if (expectedArr[i] != actualArr[i])
        {
        	fprintf(stdout, " ERROR: expected=%d  actual=%d  for ROW: %d  \n",
            expectedArr[i], actualArr[i], i);
            return 1;
        }
    // If all elements were the same.
    return 0;
}

int main() {
	din_type inArr_a[ROWS], inArr_b[ROWS];
	dout_type expectedArr[ROWS], actualArr[ROWS];

    int pass = 0;
    // Calling the function for 3 times and the results comparing
    for (int i = 0; i < 3; i++)
    {
        // initial settings
    	for (int j=0; j<ROWS; j++)
        {
        	inArr_a [j] = rand() % 1000;
            inArr_b [j] = inArr_a [j] + rand() % 1000;           
        	actualArr[j]= 0;
        }

    	//function invocation and getting actual results
    	lab2_z0(inArr_a, inArr_b, actualArr);

    	//expected results evaluation
        for (int i=0; i<ROWS; i++)
        	expectedArr[i] 	= inArr_a [i] + inArr_b [i];

        // Compare the actual results against the expected results
        if (arentEqual(expectedArr, actualArr))
        	pass = 1;
     }

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};

