#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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


long is_prime(long m)
{
    long check = 1;
    if (m <= 1)
        check = 0;
    else
    {
        for (long i = 2; i <= sqrt(m); i++)
        {
            if (m % i == 0)
                check = 0;
        }
    }
    return check;
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

void reverse_arr(long arr[MAXSIZE * MAXSIZE], size_t size)
{
    for (size_t i = 0; i < size / 2; i++)
    {
        long tmp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = tmp;
    }
}

size_t reverse_primes(long arr[][MAXSIZE], long prime_arr[MAXSIZE * MAXSIZE], size_t row, size_t column)
{
    size_t prime_arr_size = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            if (is_prime(arr[i][j]))
            {
                prime_arr[prime_arr_size] = arr[i][j];
                prime_arr_size += 1;
            }
        }
    }
    if (prime_arr_size)
    {
        reverse_arr(prime_arr, prime_arr_size);

        size_t prime_index = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                if (is_prime(arr[i][j]))
                {
                    arr[i][j] = prime_arr[prime_index];
                    prime_index += 1;
                }
            }
        }
    }
    return prime_arr_size;
}

int main()
{
    size_t row;
    size_t column;
    long arr[MAXSIZE][MAXSIZE];
    long prime_arr[MAXSIZE * MAXSIZE];
    if (reading_array(arr, &row, &column) != 1 && reverse_primes(arr, prime_arr, row, column) != 0)
    {
        printing_array(arr, row, column);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}