#include "lab3_z2.h"

int arentEqual(data_sc expected_arr[M], data_sc actual_arr[M])
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
	data_sc out[M], expected_ar[M];
	int i, j;

	int pass = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < N; j++)
			in[j] = rand() % M;

		for (j = 0; j < M; j++){
			out[j] = 0;
			expected_ar[j] = 0;
		}

	    lab3_z2(in, out);

	    for (j = 0; j < N; j++)
	    	expected_ar[in[j]]++;

	    pass = arentEqual(out, expected_ar);
	}

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};

