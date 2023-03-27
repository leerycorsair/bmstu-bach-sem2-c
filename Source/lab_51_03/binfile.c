#define __USE_MINGW_ANSI_STDIO
#include "binfile.h"


int create_random_num_bin_file(char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (f != NULL)
        return FILE_ALRD_EXISTS;
    f = fopen(filename, "ab");
    srand(150);
    size_t num_counts = rand() % 150;
    for (size_t i = 0; i < num_counts; i++)
    {
        int rand_num = rand() % 200 - 100;
        fwrite(&rand_num, sizeof(rand_num), 1, f);
    }
    fclose(f);
    return SUCCESS;
}

int print_bin_file(char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        return FILE_NOT_EXISTS;
    int ec = get_bin_size(f);
    if (ec > 0)
    {
        int num;
        while (fread(&num, sizeof(num), 1, f))
            printf("%d ", num);
        return SUCCESS;
    }
    fclose(f);
    return ec;
}

int get_bin_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    if (file_size % sizeof(int) == 0 && file_size != 0)
    {
        rewind(f);
        return file_size;
    }
    else if (file_size == 0)
        return EMPTY_FILE;
    else
        return CORRUPTED_FILE;
}

int sort_bin_file(char *filename)
{
    FILE *f = fopen(filename, "rb+");
    if (f == NULL)
        return FILE_NOT_EXISTS;
    int size = get_bin_size(f);
    if (size > 0)
    {
        for (size_t i = 0; i < (size / sizeof(int)) - 1; i++)
            for (size_t j = i + 1; j < size / sizeof(int); j++)
                if (get_number_by_pos(f, i) > get_number_by_pos(f, j))
                {
                    int tmp = get_number_by_pos(f, i);
                    put_number_by_pos(f, get_number_by_pos(f, j), i);
                    put_number_by_pos(f, tmp, j);
                }
        return SUCCESS;
    }
    else
        return size;
}


int get_number_by_pos(FILE *f, size_t pos)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    int num;
    fread(&num, sizeof(int), 1, f);
    return num;
}

void put_number_by_pos(FILE *f, int num, size_t pos)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, f);
}