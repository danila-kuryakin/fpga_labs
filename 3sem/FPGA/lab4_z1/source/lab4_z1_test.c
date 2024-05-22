#include <stdio.h>
#include "lab4_z1.h"

void initialize_int_arr(data_out temp_arr[N]) {
    for (int i = 0; i < N; i++)
        temp_arr[i] = 0;
}

void initialize_short_arr(data_in temp_arr[N]) {
    for (int i = 0; i < N; i++)
        temp_arr[i] = 0;
}

void check_func(data_in tempA_arr[N], data_out result_arr[N], data_in expected_ar[N]){
    int sumA=0;

    for (int i=0; i<N; i++){
        sumA += tempA_arr[i];
    }

    for (int j = 0; j < N; j++)
    {
        expected_ar[j] = result_arr[j] / sumA;
    }
}

int arentEqual(data_in expected_ar[N], data_in actual_arr[N])
{
    for (int i = 0; i < N; i++) {
        if (expected_ar[i] != actual_arr[i]) {
            fprintf(stdout, " ERROR: actual second vector  =%d expected second vector = %d\n",
            		actual_arr[i], expected_ar[i]);
            return 1;
        }
    }
    return 0;
}

int main() {
    int pass = 0;

    data_in firstVector_arr[N], actual_arr[N],  expected_ar[N];
    data_out actual_ar[N];

    for (int i = 0; i < 2; i++)
    {
        initialize_int_arr(actual_ar);

        for (int j = 0; j < N; j++) {
            firstVector_arr[j] = rand() % N;
            actual_arr[j] = rand() % N;
        }

        lab4_z1(firstVector_arr, actual_arr, actual_ar);

        initialize_short_arr(expected_ar);

        check_func(firstVector_arr, actual_ar, expected_ar);

        pass = arentEqual(expected_ar, actual_arr);
    }

    if (!pass)
        fprintf(stdout, "----------Pass!------------ \n");
    else
        fprintf(stderr, "----------Fail!------------ \n");

    return pass;
}
