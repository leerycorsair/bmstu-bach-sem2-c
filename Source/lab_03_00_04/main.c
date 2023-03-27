#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

long reading_array(long arr[][MAXSIZE], size_t *row)
{
    size_t column;
    if ((scanf("%lu", row) != 1) || scanf("%lu", &column) != 1 || column != *row || *row == 0
        || *row > 10)
    {
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *row; j++)
        {
            if (scanf("%ld", &arr[i][j]) != 1)
            {
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

long find_min_odd_under_diag(long arr[][MAXSIZE], size_t row, long **min)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if ((arr[i][j] < **min) & (abs(arr[i][j]) % 2 == 1) & (*min != &arr[0][0]))
            {
                **min = arr[i][j];
            }
            else if ((abs(arr[i][j]) % 2 == 1) & (*min == &arr[0][0]))
            {
                *min = &arr[i][j];
            }
        }
    }
    return (*min == &arr[0][0]);
}


int main()
{
    size_t row;
    long arr[MAXSIZE][MAXSIZE];
    if (reading_array(arr, &row) != 1)
    {
        long *min = &arr[0][0];
        if (find_min_odd_under_diag(arr, row, &min) != 1)
        {
            printf("%ld", *min);
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