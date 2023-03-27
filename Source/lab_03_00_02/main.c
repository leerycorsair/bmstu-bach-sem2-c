#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20


long reading_array(long arr[][MAXSIZE], size_t *row, size_t *column, size_t *num)
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
    if (scanf("%lu", num) != 1 || *num > 9)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


size_t get_s_num(size_t value)
{
    while (value >= 10)
    {
        value = value / 10;
    }
    return value;
}

void array_processing(long arr[][MAXSIZE], size_t *row, size_t column, size_t num)
{
    for (size_t i = 0; i < *row; i++)
    {
        size_t s_num_count = 0;
        size_t e_num_count = 0;

        for (size_t j = 0; j < column; j++)
        {
            if (abs(arr[i][j] % 10) == num)
            {
                e_num_count++;
            }
            if (get_s_num(abs(arr[i][j])) == num)
            {
                s_num_count++;
            }
        }

        if ((s_num_count == e_num_count) & (s_num_count > 0))
        {
            for (size_t j = *row; j > i + 1; j--)
            {
                for (size_t k = 0; k < column; k++)
                {
                    arr[j][k] = arr[j - 1][k];
                }
            }
            for (size_t j = 0; j < column; j++)
            {
                arr[i + 1][j] = 100;
            }

            *row += 1;
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
    size_t num;
    if (reading_array(arr, &row, &column, &num) != 1)
    {
        array_processing(arr, &row, column, num);
        printing_array(arr, row, column);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}