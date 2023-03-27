#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXARRSIZE 1024

#define SUCCESS 0
#define READING_ERROR -1
#define EMPTY_ARR -2

#define INCORRECT_FILE -3
#define NO_FILE -4
#define EMPTY_FILE -5

#define HEIGHT 2.0

#define INCORRECT_PARAMS -10

typedef struct 
{
    char surname[26];
    char name[11];
    double height;
    double weight;
} student;



long read_arr(long arr[], size_t* size)
{
    if (scanf("%zu", size) && *size > 0 && *size < MAXARRSIZE)
        for (size_t i = 0; i < *size; i++)
            if (scanf("%ld", &arr[i]) != 1)
                return READING_ERROR;
    if (*size > 0)
        return SUCCESS;
    return READING_ERROR;
}

void print_arr(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        printf("%ld ", arr[i]);
}

long del_even(long arr[], size_t* size)
{
    for (size_t i = 0; i < *size; i++)
        if (arr[i]%2 == 0)
        {
            for (size_t j = i; j < *size - 1; j++)
                arr[j] = arr[j+1];
            i -= 1;
            *size -= 1;
        }
    if (*size > 0)
        return SUCCESS;
    else 
        return EMPTY_ARR;
}

int bin_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    if (file_size % sizeof(student) == 0 && file_size != 0)
    {
        rewind(f);
        return file_size;
    }
    else if (file_size == 0)
        return EMPTY_FILE;
    else
        return INCORRECT_FILE;
}

student get_rec_by_pos(FILE *f, size_t pos)
{
    fseek(f, pos * sizeof(student), SEEK_SET);
    student student_r;
    fread(&student_r, sizeof(student), 1, f);
    return student_r;
}

void put_rec_by_pos(FILE *f, student rec, size_t pos)
{
    fseek(f, pos * sizeof(student), SEEK_SET);
    fwrite(&rec, sizeof(student), 1, f);
}

long del_high_students(char *filename)
{
    FILE *f = fopen(filename, "rb+");
    if (f == NULL)
        return NO_FILE;
    int size = bin_size(f);
    if (size > 0)
    {
        size_t i = 0;
        while (i < (size / sizeof(student)))
        {
            student student_r = get_rec_by_pos(f, i);
            if (student_r.height > HEIGHT)
            {
                for (size_t j = i; j < (size / sizeof(student)) - 1; j++)
                {
                    student_r = get_rec_by_pos(f, j + 1);
                    put_rec_by_pos(f, student_r, j);
                }
                i -= 1;
                size -= sizeof(student);
            }
            i += 1;
        }
        fclose(f);
        truncate(filename, size);
        return SUCCESS;
    }
    else
        return size;
}


int main(int argc, char **argv)
{
    if ( argc == 2 && strcmp(argv[1],"de")==0)
    {
        size_t arr_size;
        long arr [MAXARRSIZE];
        if (!read_arr(arr, &arr_size))
        {
            if (!del_even(arr, &arr_size))
            {
                print_arr(arr, arr_size);
                return SUCCESS;
            }
            else 
                return EMPTY_ARR;
        }
    }
    else if (argc == 3 && strcmp(argv[1],"ds")==0)
    {
        long ec = del_high_students(argv[2]);
        return ec;
    }
    else
        return INCORRECT_PARAMS;
}