#define __USE_MINGW_ANSI_STDIO
#include "filehandling.h"

#include <stdio.h>


int main()
{
    long min_d = -1;
    long ec = process(stdin, &min_d);
    if (!ec)
        printf("%ld", min_d);
    return ec;
}