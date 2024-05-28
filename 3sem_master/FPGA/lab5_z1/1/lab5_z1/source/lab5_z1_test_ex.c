#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab5_z1.h"
#include "lab5_z1.c"

void initialize_int_arr(int_arr temp_arr[N])
{
    for (int i = 0; i < N; i++)
        temp_arr[i] = 0;
}

int main()
{
    int pass = 0;

    int_arr scale, foo_m_in[N], foo_m_out1[N], foo_m_out2[N], check_in1[N], check_in2[N];

    long average = 0;

    struct timespec t0, t1;
	double min = 1000000.0, max = 0.0, acc_time = 0.0;

    for (int i = 0; i < 32; i++)
    {
        initialize_int_arr(foo_m_in);
        initialize_int_arr(foo_m_out1);
        initialize_int_arr(foo_m_out2);
        initialize_int_arr(check_in1);
        initialize_int_arr(check_in2);

        scale = rand() % 15 + 1;

        for (int j = 0; j < N; j++)
        {
        	foo_m_in[j] = rand() % 5;
        }

       if (clock_gettime(CLOCK_REALTIME, &t0) != 0){
			perror("Error in calling clock_gettime\n");
			exit(EXIT_FAILURE);
		}

        foo_m(foo_m_in, scale, foo_m_out1, foo_m_out2);

        if (clock_gettime(CLOCK_REALTIME, &t1) != 0){
			perror("Error in calling clock_gettime\n");
			exit(EXIT_FAILURE);
		}

        double diff_sec = (double)(t1.tv_sec - t0.tv_sec);
		double diff_sec_mult = diff_sec * 1000000000.0;
		double diff_nsec = (double)(t1.tv_nsec - t0.tv_nsec);
		double diff_time = diff_sec_mult + diff_nsec;

		acc_time = acc_time + diff_time;
        double temp_avg_time = acc_time / (i+1);
		printf("%d Elapsed time: %.41f nanoseconds\n", i+1, temp_avg_time);

        
        if (diff_time<min) 
            min = diff_time;
        if (diff_time>max) 
            max = diff_time;
    }

    printf("Min %.4f nanosec\n",min);
    printf("Max %.4f nanosec\n",max);

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
}
