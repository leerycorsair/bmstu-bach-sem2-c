#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-10

int main(void)
{
    double x, acc;
    printf("Enter the argument and an accuracy: \n");
    if (scanf("%lf", &x) != 1 || scanf("%lf", &acc) != 1)
        return EXIT_FAILURE;
    else if (fabs(x) >= 1 || acc <= 0 || acc >= 1)
        return EXIT_FAILURE;
    else
    {
        double curr_x, sum, frac_uncer, abs_uncer;
        long int i;
        curr_x = x;
        i = 1;
        sum = 0;
        while (fabs(curr_x) > acc)
        {
            sum += curr_x;
            curr_x = curr_x * (x * x * i * i) / ((i + 1) * (i + 2));
            i += 2;
        }
        abs_uncer = fabs(sum - asin(x));
        if (x < EPS)
            frac_uncer = 0.0;
        else
            frac_uncer = abs_uncer / asin(x);
        printf("%lf %lf %lf %lf", sum, asin(x), abs_uncer, frac_uncer);
        return EXIT_SUCCESS;
    }
}