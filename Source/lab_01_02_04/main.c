#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long int t, h, m, s;
    printf("Enter time in seconds:\n");
    scanf("%ld", &t);
    h = t / 3600;
    m = t / 60 - h * 60;
    s = t - h * 3600 - m * 60;
    printf("Formated time: %ld %ld %ld", h, m, s);
    return EXIT_SUCCESS;
}