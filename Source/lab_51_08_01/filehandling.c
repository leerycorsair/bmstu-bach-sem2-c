#include "filehandling.h"

int process(FILE *f, long *min_d)
{
    long d = 0;
    size_t check = 0;
    long num_l, num, num_r;
    if (fscanf(f, "%ld", &num_l) == 1 && fscanf(f, "%ld", &num) == 1)
    {
        while (fscanf(f, "%ld", &num_r) == 1)
        {
            if (num > num_r && num > num_l && check)
                if ((*min_d == -1 || d < *min_d) && d != 0)
                {
                    *min_d = d;
                    d = 0;
                }
            if (num > num_r && num > num_l && !check)
                check = 1;
            if (check)
                d += 1;
            num_l = num;
            num = num_r;
        }
        if (*min_d != -1)
            return SUCCESS;
        else
            return N_T_MAX;
    }
    else
        return N_SEQ;
}