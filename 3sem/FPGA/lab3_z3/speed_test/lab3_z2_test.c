#include "lab3_z2.h"

int arentEqual(data_sc expected_arr[N], data_sc actual_arr[N])
{
	for (int i = 0; i < M; i++)
		if (expected_arr[i] != actual_arr[i])
		{
			fprintf(stdout, " ERROR: expected=%d  actual=%d  \n", expected_arr[i], actual_arr[i]);
			return 1;
		}
    return 0;
}


int main() {

	data_sc in[N];
	out_ar out[M], actual_out[M];
	int i, j;

	int pass = 0;
	for (i = 0; i < 1; i++)
	{
		srand(6789+i);
		for (j = 0; j < N; j++)
			in[j] = rand() % N-1;

		for (j = 0; j < M; j++)
			out[j] = 0;

	    lab3_z2(in, out);

	    for (j = 0; j < N; j++)
	    	actual_out[in[j]] = actual_out[in[j]] + 1;

	    pass = arentEqual(out, actual_out);
	}

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};

