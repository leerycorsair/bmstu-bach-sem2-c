#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 0
#define READING_SIZE_ERROR 1
#define READING_NUM_ERROR 2
#define READING_ELEM_ERROR 3
#define EMPTY_ARR 4

#define MAXSIZE 64

double func(long arr[], long n)
{
    double res = 0;
    for (long i = 0; i < n; i++)
    {
        res += sqrt(arr[i]*arr[i]);
    }
    return res;
}

long reading(long arr[], long *n, long *p)
{
    if (scanf("%ld", n)!= 1 || *n > MAXSIZE || *n < 0)
    {
        return READING_SIZE_ERROR;
    }
    else if (scanf("%ld", p)!= 1 || *p > *n || *p < 0)
    {
        return READING_NUM_ERROR;
    }
    
    else 
    {
        for (long i = 0; i < *n; i++)
        {
            if (scanf("%ld", &arr[i])!=1)
            {
                return READING_ELEM_ERROR;
            }
        }
    }
    return SUCCESS;
}

void elem_del (long arr[], long *n, long res)
{
    for (long i = 0; i < *n; i++)
    {
        if (arr[i] > res)
        {
            for (long j = i; j < *n - 2; j++)
            {
                arr[j] = arr[j+1];
            }
            *n -= 1;
            i--;
        }
    }
}


int main ()
{
    long arr[MAXSIZE];
    double res;
    long n;
    long p;
    long EC = reading(arr, &n, &p);
    if (EC == SUCCESS)
    {   
        if (n == 0)
        {
            return SUCCESS;
        }
        res = func(arr, p);
        elem_del(arr, &n, res);
        if (n!=0)
        {
            for (long i = 0; i < n; i++)
            {
                printf("%ld ", arr[i]);
            }
        }
        else
        {
            return EMPTY_ARR;
        }
    }
    else
    {
        return EC;
    }
}