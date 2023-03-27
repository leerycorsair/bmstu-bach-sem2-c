#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
    printf("Enter coordinates:\n");
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double perimeter;
    perimeter = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
        + sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3))
        + sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    printf("Perimeter: %lf", perimeter);
    return EXIT_SUCCESS;
}