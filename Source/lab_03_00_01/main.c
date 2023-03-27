#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

long reading_array(long arr[][MAXSIZE], size_t *row, size_t *column)
{
    if ((scanf("%lu", row) != 1) || (scanf("%lu", column) != 1) || *row == 0 || *row > 10 || *column == 0
        || *column > 10)
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
void order_check(long arr[][MAXSIZE], long arr_res[], size_t row, size_t column)
{
    for (size_t j = 0; j < column; j++)
    {
        long check = 1;
        if (row > 1)
        {
            for (size_t i = 0; i < row - 1; i++)
            {
                if (arr[i][j] <= arr[i + 1][j])
                {
                    check = 0;
                }   
            }
        }
        else
        {
            check = 0;
        }        
        arr_res[j] = check; 
    }
}
long printing_array(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%ld ", arr[i]);
    }
    return 1;
}
int main()
{
    size_t row;
    size_t column;
    long arr[MAXSIZE][MAXSIZE];
    long arr_res[MAXSIZE];
    if (reading_array(arr, &row, &column) != 1)
    {
        order_check(arr, arr_res, row, column);
        printing_array(arr_res, column);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}
