#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lab3_z2.h"
#include "time_utils.h"

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

	struct timespec t0, t1;
	double acc_time = 0.0;

	int pass = 0;
	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < N; j++)
			in[j] = rand() % N-1;

		for (j = 0; j < M; j++)
			out[j] = 0;

		if(!gettime(&t0)) {
			printf("Error in calling gettime\n");
			exit(EXIT_FAILURE);
		}

	    lab3_z2(in, out);

	    if(!gettime(&t1)) {
	    printf("Error in calling gettime\n");
	    exit(EXIT_FAILURE);
	    }

	    double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
	    printf("Elapsed time: %lf seconds\n", diff);

	    for (j = 0; j < N; j++)
	    	actual_out[in[j]]++;

	    pass = arentEqual(out, actual_out);
	}

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};

