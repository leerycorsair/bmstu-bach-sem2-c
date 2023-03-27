
#ifndef BINFILE_H
#define BINFILE_H
#define __USE_MINGW_ANSI_STDIO

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"
#include "errorcodes.h"
#include <unistd.h>


int sort_records(char *filename);
int del_bad_students(char *filename);
int find_records(char *filename_in, char *filename_out, char *req);

int bin_size(FILE *f);
student get_rec_by_pos(FILE *f, size_t pos);
void put_rec_by_pos(FILE *f, student rec, size_t pos);

#endif