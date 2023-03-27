#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define EPS 1e-10

int main(void)
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double xp, yp;
    double os1, os2, os3;
    printf("Enter coodinates of the triangle and the dot:\n");
    if (scanf("%lf", &x1) != 1 || scanf("%lf", &y1) != 1 || scanf("%lf", &x2) != 1
        || scanf("%lf", &y2) != 1 || scanf("%lf", &x3) != 1 || scanf("%lf", &y3) != 1
        || scanf("%lf", &xp) != 1 || scanf("%lf", &yp) != 1)
        return EXIT_FAILURE;
    else if (fabs((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) < EPS)
        return EXIT_FAILURE;
    else
    {
        os1 = (x1 - xp) * (y2 - y1) - (x2 - x1) * (y1 - yp);
        os2 = (x2 - xp) * (y3 - y2) - (x3 - x2) * (y2 - yp);
        os3 = (x3 - xp) * (y1 - y3) - (x1 - x3) * (y3 - yp);
        if ((os1 > 0 && os2 > 0 && os3 > 0) || (os1 < 0 && os2 < 0 && os3 < 0))
            printf("%d", 0);
        else if (fabs(os1) < EPS || fabs(os2) < EPS || fabs(os3) < EPS)
            printf("%d", 1);
        else
            printf("%d", 2);
        return EXIT_SUCCESS;
    }
}