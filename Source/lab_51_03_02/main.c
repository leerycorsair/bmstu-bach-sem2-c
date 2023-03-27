#define __USE_MINGW_ANSI_STDIO
#include "checksigrule.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return NOT_ENOUGH_PARAM;
    }
    FILE* f;
    f = fopen(argv[1], "r");
    if (f == NULL)
        return NO_FILE;
    else
    {
        long check = check_seq_sigg_rule(f);
        if (check == YES || check == NO)
        {
            printf("%ld", check);
            fclose(f);
            return EXIT_SUCCESS;
        }
        else
        {
            fclose(f);
            return check;
        }
    }
}