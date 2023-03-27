#ifndef BINFILE_H

#define BINFILE_H


#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0

#define INCOR_PARAMS 11
#define UNKNOWN_PARAM_VALUE 12

#define FILE_ALRD_EXISTS 21
#define FILE_NOT_EXISTS 22


#define CORRUPTED_FILE -1
#define EMPTY_FILE -2


int create_random_num_bin_file(char *filename);
int print_bin_file(char *filename);
int sort_bin_file(char *filename);


int get_bin_size(FILE *f);
int get_number_by_pos(FILE *f, size_t pos);
void put_number_by_pos(FILE *f, int num, size_t pos);


#endif