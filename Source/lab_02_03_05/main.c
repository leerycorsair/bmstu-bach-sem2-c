#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

long *reading(long *p_arr_e)
{
    long size;
    long *p_arr_s = p_arr_e;
    if ((scanf("%ld", &size) != 1) || (size <= 0) || (size > 10))
    {
        return p_arr_s;
    }
    for (long i = 0; i < size; i++)
    {
        if (scanf("%ld", p_arr_e) != 1)
            return p_arr_s;
        p_arr_e++;
    }
    return p_arr_e;
}


long get_min_multi(long *p_arr_s, long *p_arr_e)
{
    long min = *p_arr_s * *(p_arr_s + 1);
    while (p_arr_s < p_arr_e - 1)
    {
        if (*p_arr_s * *(p_arr_s + 1) < min)
            min = *p_arr_s * *(p_arr_s + 1);
        p_arr_s++;
    }
    return min;
}

int main()
{
    long arr[NMAX];
    long *p_arr_s = arr;
    long *p_arr_e;
    p_arr_e = reading(p_arr_s);
    if ((p_arr_e != p_arr_s) & (p_arr_s + 1 != p_arr_e))
    {
        long min_multi = get_min_multi(p_arr_s, p_arr_e);
        printf("%ld", min_multi);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}