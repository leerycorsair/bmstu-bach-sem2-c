#define __USE_MINGW_ANSI_STDIO
#include "binfile.h"
#include "student.h"
#include "errorcodes.h"

int main(int argc, char **argv)
{
    int ec;
    if (argc == 3 && strcmp(argv[1], "sb") == 0)
    {
        ec = sort_records(argv[2]);
        return ec;
    }
    else if (argc == 3 && strcmp(argv[1], "db") == 0)
    {
        ec = del_bad_students(argv[2]);
        return ec;
    }
    else if (argc == 5 && strcmp(argv[1], "fb") == 0)
    {
        ec = find_records(argv[2], argv[3], argv[4]);
        return ec;
    }
    else
    {
        return UNKNOWN_PARAMS;
    }
}