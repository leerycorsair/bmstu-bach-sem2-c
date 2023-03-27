#include "binfile.h"


#define MAXREC 1024

int sort_records(char *filename)
{
    FILE *f = fopen(filename, "rb+");
    if (f == NULL)
        return NO_FILE;
    int size = bin_size(f);
    if (size > 0)
    {
        student student_r_1, student_r_2, tmp_r;
        for (size_t i = 0; i < (size / sizeof(student)) - 1; i++)
            for (size_t j = i + 1; j < size / sizeof(student); j++)
            {
                student_r_1 = get_rec_by_pos(f, i);
                student_r_2 = get_rec_by_pos(f, j);
                if (strcmp(student_r_1.surname, student_r_2.surname) > 0)
                {
                    tmp_r = student_r_1;
                    put_rec_by_pos(f, student_r_2, i);
                    put_rec_by_pos(f, tmp_r, j);
                }
                else if (strcmp(student_r_1.surname, student_r_2.surname) == 0)
                    if (strcmp(student_r_1.name, student_r_2.name) > 0)
                    {
                        tmp_r = student_r_1;
                        put_rec_by_pos(f, student_r_2, i);
                        put_rec_by_pos(f, tmp_r, j);
                    }
            }
        fseek(f, 0, SEEK_SET);
        for (size_t i = 0; i < (size / sizeof(student)); i++)
        {
            student_r_1 = get_rec_by_pos(f, i);
            printf("%s\n%s\n%u %u %u %u\n", student_r_1.surname, student_r_1.name,
            student_r_1.marks[0], student_r_1.marks[1], student_r_1.marks[2],
            student_r_1.marks[3]);
        }
        fclose(f);
        return SUCCESS;
    }
    else
        return size;
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
        return CORRUPTED_FILE;
}

int del_bad_students(char *filename)
{
    FILE *f = fopen(filename, "rb+");
    if (f == NULL)
        return NO_FILE;
    int size = bin_size(f);
    if (size > 0)
    {
        double s_m[MAXREC];
        double am = 0;
        student student_r;
        for (size_t i = 0; i < (size / sizeof(student)); i++)
        {
            student_r = get_rec_by_pos(f, i);
            s_m[i] = (double)(student_r.marks[0] + student_r.marks[1] + student_r.marks[2]
                + student_r.marks[3])
                / 4;
            am += s_m[i];
        }
        am = am / (size / sizeof(student));
        size_t i = 0;
        size_t k = 0;
        while (i < (size / sizeof(student)))
        {
            if (s_m[k] < am)
            {
                for (size_t j = i; j < (size / sizeof(student)) - 1; j++)
                {
                    student_r = get_rec_by_pos(f, j + 1);
                    put_rec_by_pos(f, student_r, j);
                }
                i -= 1;
                size -= sizeof(student);
            }
            k += 1;
            i += 1;
        }
        fclose(f);
        truncate(filename, size);
        return SUCCESS;
    }
    else
        return size;
}

int find_records(char *filename_in, char *filename_out, char *req)
{
    if (sizeof(req) > sizeof(char) * 26)
        return INCORRECT_SURNAME;
    FILE *f_in = fopen(filename_in, "rb");
    if (f_in == NULL)
        return NO_FILE;
    int size = bin_size(f_in);
    if (size > 0)
    {
        FILE *f_out = fopen(filename_out, "wb");
        student student_r;
        int check = 0;
        for (size_t i = 0; i < size / sizeof(student); i++)
        {
            student_r = get_rec_by_pos(f_in, i);
            if (strstr(student_r.surname, req) == student_r.surname)
            {
                check = 1;
                fwrite(&student_r, sizeof(student), 1, f_out);
            }
        }
        fclose(f_in);
        fclose(f_out);
        if (check == 1)
            return SUCCESS;
        return NOT_FOUND;
    }
    else
    {
        fclose(f_in);
        return size;
    }
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