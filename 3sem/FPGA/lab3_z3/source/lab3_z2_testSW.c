#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lab3_z2.h"
#include "lab3_z2.c"

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

    struct timespec t0, t1;
    double all_time = 0.0;
    double max_time = 0.0;
    double min_time = 0.0;


    int pass = 0;
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < N; j++)
            in[j] = rand() % M;

        for (j = 0; j < M; j++){
            out[j] = 0;
            expected_ar[j] = 0;
        }

        if(clock_gettime(CLOCK_REALTIME, &t0) != 0) {
            perror("Error in calling clock_gettime");
            exit(EXIT_FAILURE);
        }

        lab3_z2(in, out);

        if(clock_gettime(CLOCK_REALTIME, &t1) != 0) {
            perror("Error in calling clock_gettime");
            exit(EXIT_FAILURE);
        }

        double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec));
        all_time += diff;

        if(max_time < diff || i == 0)
            max_time = diff;
        if(min_time > diff || i == 0)
            min_time = diff;

        for (j = 0; j < N; j++)
            expected_ar[in[j]]++;

        pass = arentEqual(out, expected_ar);
    }
    printf("All time: %.0fns, max time: %.0fns, min time: %.0fns\n", all_time, max_time, min_time);

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
};