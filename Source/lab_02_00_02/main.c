#define __USE_MINGW_ANSI_STDIO
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

long reading(long arr[], size_t *size_in)
{
    if (scanf("%zu", size_in) != 1 || *size_in == 0 || *size_in > MAX_SIZE)
    {
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < *size_in; i++)
    {
        if (scanf("%ld", &arr[i]) != 1)
        {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

double get_am(long arr[], size_t size)
{
    double am = 0;
    for (size_t i = 0; i < size; i++)
    {
        am += arr[i];
    }
    am = am / size;
    return am;
}

long printing_array(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%ld ", arr[i]);
    }
    return 1;
}
long form_out_arr(long arr_in[], size_t size_in, long arr_out[], size_t *size_out, double am)
{
    for (size_t i = 0; i < size_in; i++)
    {
        if (arr_in[i] > am)
        {
            arr_out[*size_out] = arr_in[i];
            *size_out += 1;
        }
    }
    if (*size_out == 0)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main()
{
    long arr_in[MAX_SIZE];
    size_t size_in;
    double am = 0;
    if (reading(arr_in, &size_in) == 0)
    {
        am = get_am(arr_in, size_in);
        long arr_out[MAX_SIZE];
        size_t size_out = 0;
        if (form_out_arr(arr_in, size_in, arr_out, &size_out, am) == 0)
        {
            printing_array(arr_out, size_out);
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }
    }
    else
    {
        return EXIT_FAILURE;
    }
}
