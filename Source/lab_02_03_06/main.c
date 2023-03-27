#define __USE_MINGW_ANSI_STDIO
#include <inttypes.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define MAXITER 100


int64_t get_indexation_time(long arr[])
{
    int64_t indexation_time;
    struct timeval tv_start, tv_stop;
    gettimeofday(&tv_start, NULL);
    long copy_arr[NMAX];
    for (size_t i = 0; i < NMAX; i++)
    {
        copy_arr[i] = arr[i];
    }
    long min = copy_arr[0] * copy_arr[1];
    for (size_t i = 1; i < NMAX - 1; i++)
    {
        if (copy_arr[i] * copy_arr[i + 1] < min)
        {
            min = copy_arr[i] * copy_arr[i + 1];
        }
    }
    gettimeofday(&tv_stop, NULL);
    indexation_time
        = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    return indexation_time;
}

int64_t get_sumpointer_time(long arr[])
{
    int64_t sumpointer_time;
    struct timeval tv_start, tv_stop;
    gettimeofday(&tv_start, NULL);
    long copy_arr[NMAX];
    for (size_t i = 0; i < NMAX; i++)
    {
        *(copy_arr + i) = *(arr + i);
    }
    long min = *(copy_arr) * *(copy_arr + 1);
    for (size_t i = 1; i < NMAX - 1; i++)
    {
        if (*(copy_arr + i) * *(copy_arr + i + 1) > min)
        {
            min = *(copy_arr + i) * *(copy_arr + i + 1);
        }
    }
    gettimeofday(&tv_stop, NULL);
    sumpointer_time
        = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    return sumpointer_time;
}

int64_t get_pointer_time(long arr[])
{
    int64_t pointer_time;
    struct timeval tv_start, tv_stop;
    gettimeofday(&tv_start, NULL);
    long copy_arr[NMAX];
    long *copy_p = copy_arr;
    long *arr_p = arr;
    for (size_t i = 0; i < NMAX; i++)
    {
        *copy_arr = *arr_p;
        copy_p += 1;
        arr_p += 1;
    }
    long *copy_arr_s = copy_arr;
    long min = *copy_arr_s * *(copy_arr_s + 1);
    while (copy_arr_s < copy_p - 1)
    {
        if (*copy_arr_s * *(copy_arr_s + 1) < min)
            min = *copy_arr_s * *(copy_arr_s + 1);
        copy_arr_s++;
    }
    gettimeofday(&tv_stop, NULL);
    pointer_time
        = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
    return pointer_time;
}

int main()
{
    long arr[NMAX];
    int64_t t1 = 0;
    int64_t t2 = 0;
    int64_t t3 = 0;
    for (size_t i = 0; i < MAXITER; i++)
    {
        for (size_t j = 0; j < NMAX; j++)
        {
            arr[j] = rand();
        }
        t1 += get_indexation_time(arr);
        t2 += get_sumpointer_time(arr);
        t3 += get_pointer_time(arr);
    }
    printf("Размер массива - %d, кол-во повторов - %d\n", NMAX, MAXITER);
    printf("a[i] %" PRId64 " µs\n", t1);
    printf("*(a+i) %" PRId64 " µs\n", t2);
    printf("Работа с указателями %" PRId64 " µs\n", t3);
}