#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double r1, r2, r3;
    printf("Enter resistances:\n");
    scanf("%lf%lf%lf", &r1, &r2, &r3);
    double r;
    r = (r1 * r2 * r3) / (r2 * r3 + r1 * r3 + r1 * r2);
    printf("General resistance: %lf", r);
    return EXIT_SUCCESS;
}