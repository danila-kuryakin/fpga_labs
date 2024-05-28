#include <stdio.h>
#include "lab5_z1.h"

void initialize_int_arr(int_arr temp_arr[N])
{
    for (int i = 0; i < N; i++)
        temp_arr[i] = 0;
}

void check_func(int check_in1[N], int check_in2[N], int scale, int foo_m_out1[N], int foo_m_out2[N])
{
	for (int j = 0; j < N; j++)
    {
    	#pragma HLS pipeline off
    	check_in1[j] = foo_m_out1[j] / 22 / scale;
	}

	for (int k = 0; k < N; k++)
	{
		#pragma HLS pipeline off
		check_in2[k] = foo_m_out2[k] / 33 / scale;
	}
}

int main()
{
    int pass = 0;

    int_arr scale, foo_m_in[N], foo_m_out1[N], foo_m_out2[N], check_in1[N], check_in2[N];

    for (int i = 0; i < 2; i++)
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
        // fprintf(stdout, " scale = %d ", scale);

        foo_m(foo_m_in, scale, foo_m_out1, foo_m_out2);

        check_func(check_in1, check_in2, scale, foo_m_out1, foo_m_out2);

        for (int p = 0; p < N; p++)
        {
            if (foo_m_in[p] != check_in1[p] || check_in1[p] != check_in2[p])
            {
                pass = 1;
                fprintf(stdout, " ERROR: actual in1 = %d actual in2 = %d; expected in = %d\n", check_in1[p], check_in2[p], foo_m_in[p]);
            }
        }
    }

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
}
