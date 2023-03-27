#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10


long reading_array(long arr[][MAXSIZE], size_t *row, size_t *column)
{
    if ((scanf("%lu", row) != 1) || (scanf("%lu", column) != 1) || *row == 0 || *row > 10
        || *column == 0 || *column > 10)
    {
        return EXIT_FAILURE;
    }
    for (size_t i = 0; i < *row; i++)
    {
        for (size_t j = 0; j < *column; j++)
        {
            if (scanf("%ld", &arr[i][j]) != 1)
            {
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

void array_sort(long arr[][MAXSIZE], size_t row, size_t column)
{
    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = 0; j < row - i - 1; j++)
        {
            long sum1 = 0;
            long sum2 = 0;
            for (size_t k = 0; k < column; k++)
            {
                sum1 += arr[j][k];
                sum2 += arr[j + 1][k];
            }
            if (sum1 > sum2)
            {
                for (size_t k = 0; k < column; k++)
                {
                    long tmp = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = tmp;
                }
            }
        }
    }
}


void printing_array(long arr[][MAXSIZE], size_t row, size_t column)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    size_t row;
    size_t column;
    long arr[MAXSIZE][MAXSIZE];
    if (reading_array(arr, &row, &column) != 1)
    {
        array_sort(arr, row, column);
        printing_array(arr, row, column);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}