#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 47
long int fib(long int n)
{
    long int f0, f1, f2, i;
    f0 = 0;
    f1 = 1;
    i = 1;
    if (n > 1)
    {
        while (i < n)
        {
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
            i += 1;
        }
        return f2;
    }
    else if (n == 1)
    {
        return f1;
    }
    else
    {
        return f0;
    }
}

int main(void)
{
    long int n, result;
    printf("Enter the Fibonacci serial number: \n");
    if (scanf("%ld", &n) != 1)
        return EXIT_FAILURE;
    else if (n < 0 || n > MAX_FIB)
    {
        return EXIT_FAILURE;
    }

    result = fib(n);
    printf("Fibonacci  number: %ld", result);
    return EXIT_SUCCESS;
}