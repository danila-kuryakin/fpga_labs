#include <stdio.h>
#include "lab2_z1.h"

int arentEqual(dout_type expectedArr, dout_type actualArr)
{
    if (expectedArr != actualArr)
    {
        fprintf(stdout, " ERROR: expected=%d  actual=%d  \n", expectedArr, actualArr);
        return 1;
    }
    return 0;
}


dout_type lab2_z1_rec (din_type in){

	dout_type res;
	if (in == 0){
		res = 1;
	} else {
		res = in * lab2_z1_rec(in-1);
	}
	return (res);
}


int main() {
	din_type in;
	dout_type expectedArr, actualArr;


    int pass = 0;
    for (int i = 0; i < 3; i++)
    {
    	in = (rand() %15) + 5;

    	expectedArr = lab2_z1(in);
    	actualArr = lab2_z1_rec(in);

    	fprintf(stdout, "%d: %d, %d, %d \n", i, in, expectedArr, actualArr);

        if (arentEqual(expectedArr, actualArr))
        	pass = 1;
     }

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};

