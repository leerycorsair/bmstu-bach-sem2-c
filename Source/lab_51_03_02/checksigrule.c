#include "checksigrule.h"

double get_am(FILE *f, long *len)
{
    double num, am = 0;
    while (fscanf(f, "%lf", &num) == 1)
    {
        am += num;
        *len += 1;
    }
    if (*len)
    {
        am = am / *len;
        rewind(f);
        return am;
    }
    else
        return INCOR_CONTENT;
}

double get_disp(FILE *f, double am, long len)
{
    double disp = 0;
    double num;
    while (fscanf(f, "%lf", &num) == 1)
        disp += (num - am) * (num - am);
    disp = disp / len;
    rewind(f);
    return disp;
}

long check_seq_sigg_rule(FILE *f)
{
    long len = 0;
    long am = get_am(f, &len);
    if (len > 1)
    {
        double delt = sqrt(get_disp(f, am, len));
        double num;
        long in_dots = 0;
        while (fscanf(f, "%lf", &num) == 1)
        {
            if ((num > am - 3 * delt) && (num < am + 3 * delt))
                in_dots += 1;
        }
        double my_prob = (double)in_dots / len;
        if (my_prob < NORM_PROB)
            return NO;
        else
            return YES;
    }
    else if (len == 1)
        return YES;
    return INCOR_CONTENT;
}