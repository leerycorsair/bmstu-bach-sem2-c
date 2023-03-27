#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 64
long reading_array(long arr[][MAXSIZE], long *row, long *column)
{
    if ((scanf("%ld", row) != 1) || (scanf("%ld", column) != 1) || *row < 0 || *row > MAXSIZE
        || *column < 0 || *column > MAXSIZE)
    {
        return EXIT_FAILURE;
    }
    for (long i = 0; i < *row; i++)
    {
        for (long j = 0; j < *column; j++)
        {
            if (scanf("%ld", &arr[i][j]) != 1)
            {
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}

void printing_array(long arr[][MAXSIZE], long row, long column)
{
    for (long i = 0; i < row; i++)
    {
        for (long j = 0; j < column; j++)
        {
            printf("%ld ", arr[i][j]);
        }
        printf("\n");
    }
}

double func(long arr[][MAXSIZE], long r, long c)
{
    double res = 0;
    long tmp = r / 2;
    for (long i = 0; i < tmp; i++)
    {
        res += sqrt(arr[i][c]*arr[i][c]);
    }
    return res;
}



void array_sort(long arr[][MAXSIZE], long r, long c)
{
    for (long i = 0; i < c - 1; i++)
    {
        for (long j = 0; j < c - i - 1; j++)
        {
            double res1 = func (arr, r , j);
            double res2 = func (arr, r, j+1);
            if (res1 < res2)
            {
                for (long k = 0; k < r; k++)
                {
                    long tmp = arr[k][j];
                    arr[k][j] = arr[k][j+1];
                    arr[k][j+1] = tmp;
                }
            }
        }
    }
}

int main()
{
    long row;
    long column;
    long arr[MAXSIZE][MAXSIZE];
    if (reading_array(arr, &row, &column) != 1)
    {    
        if (row == 0 || column == 0)
        {
            return EXIT_SUCCESS;
        }
        array_sort(arr, row, column);
        printing_array(arr, row, column);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}