
#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

long reading_array(long arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (scanf("%ld", &arr[i]) != 1)
        {
            return 0;
        }
    }
    return 1;
}
long even_counter(long arr[], size_t n)
{
    long counter = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            counter++;
        }
    }
    return counter;
}

long sum_of_even(long arr[], size_t n)
{
    long sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    size_t n;
    long arr[MAX_SIZE];
    if (scanf("%zu", &n) != 1 || n == 0 || n > MAX_SIZE)
    {
        return EXIT_FAILURE;
    }
    if (reading_array(arr, n))
    {
        long even_count;
        even_count = even_counter(arr, n);
        if (even_count == 0)
            return EXIT_FAILURE;
        else
        {
            long sum;
            sum = sum_of_even(arr, n);
            printf("%ld", sum);
        }
        return EXIT_SUCCESS;
    }
    else
        return EXIT_FAILURE;
}