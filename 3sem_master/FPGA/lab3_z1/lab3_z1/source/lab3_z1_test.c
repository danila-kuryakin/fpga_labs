#include <stdio.h>
#include "lab3_z1.h"

int arentEqual(pnt_out expectedArr, pnt_out actualArr)
{
    if (expectedArr != actualArr)
    {
        fprintf(stdout, " ERROR: expected=%d  actual=%d  \n", expectedArr, actualArr);
        return 1;
    }else{
    	fprintf(stdout, " GOOD!: expected=%d  actual=%d  \n", expectedArr, actualArr);
    }
    return 0;
}


int main() {

	data_in inA, inB, inC;
	data_in temp, test_temp;
	pnt_out test_res;
	pnt_out res;

	    int pass = 0;
	    for (int i = 0; i < 3; i++)
	    {
	    	inA = (rand() %15) + 5;
	    	inB = (rand() %15) + 5;
	    	inC = (rand() %15) + 5;
	    	test_res = inA * inC + inB;

	    	temp = lab3_z1(inA, inB, &inC, &res);

	        if (arentEqual(res, test_res))
	        	pass = 1;
	        res = 0;
	        temp = 0;
	     }

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};

