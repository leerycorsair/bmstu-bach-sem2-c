/**
 * **************************************************************************
 * Данная программа предназначена для изучения работы с бинарным файлом.
 *
 * Внимание:
 * + числа в бинарном файле типа int
 * + используется алгоритм сортировки пузырьком
 * + сортировка чисел в файле выполняется по возрастанию
 *
 * **************************************************************************
*/


#include "binfile.h"
#include <string.h>

int main(int argc, char **argv)
{
    int ec;
    if (argc != 3)
    {
        ec = INCOR_PARAMS;
        return ec;
    }
    if (strcmp(argv[1], "c") == 0)
    {
        ec = create_random_num_bin_file(argv[2]);
        return ec;
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        ec = print_bin_file(argv[2]);
        return ec;
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        ec = sort_bin_file(argv[2]);
        return ec;
    }
    else
    {
        ec = UNKNOWN_PARAM_VALUE;
        return ec;
    }
}