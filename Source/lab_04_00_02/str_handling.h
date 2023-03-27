#ifndef STR_HANDLING_H
#define __USE_MINGW_ANSI_STDIO
#define STR_HANDLING_H
#define MAXSTRSIZE 256
#define MAXWORDSIZE 16


#define READING_ERROR 0
#define READING_SUCCESS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long str_reading(char *str_in);
size_t get_words(char *str_in, char words_arr[][MAXWORDSIZE + 1]);
void print_every_word_count(char words_arr[][MAXWORDSIZE + 1], size_t words_count);

#endif