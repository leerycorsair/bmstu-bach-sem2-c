#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

long reading_array(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (scanf("%ld", &arr[i]) != 1)
            return 0;
    }
    return 1;
}

long printing_array(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%ld ", arr[i]);
    }
    return 1;
}


void selection_sort(long arr[], size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t tmp_i_1 = i;
        size_t tmp_i_2 = i + 1;
        while (tmp_i_2 < size)
        {
            if (arr[tmp_i_2] < arr[tmp_i_1])
                tmp_i_1 = tmp_i_2;
            tmp_i_2 += 1;
        }
        long tmp = arr[i];
        arr[i] = arr[tmp_i_1];
        arr[tmp_i_1] = tmp;
    }
}

int main()
{
    size_t size;
    long arr[MAX_SIZE];
    if (scanf("%zu", &size) != 1 || size == 0 || size > MAX_SIZE)
        return EXIT_FAILURE;
    if (reading_array(arr, size) != 1)
    {
        return EXIT_FAILURE;
    }
    selection_sort(arr, size);
    printing_array(arr, size);
    return EXIT_SUCCESS;
}