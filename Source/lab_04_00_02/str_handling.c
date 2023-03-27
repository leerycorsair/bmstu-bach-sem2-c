#include "str_handling.h"
long str_reading(char *str_in)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != '\0' && i < MAXSTRSIZE)
    {
        str_in[i] = ch;
        i++;
    }
    if (((ch == '\n' || ch == EOF || ch == '\0') && i == 0) || i == MAXSTRSIZE)
        return READING_ERROR;
    else
    {
        str_in[i] = '\0';
        return READING_SUCCESS;
    }
}


size_t get_words(char *str, char words_arr[][MAXWORDSIZE + 1])
{
    size_t words_count = 0, j = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ',' && str[i] != ';' && str[i] != ':' && str[i] != '-' && str[i] != '.'
            && str[i] != '!' && str[i] != '?' && str[i] != ' ')
        {
            if (j >= MAXWORDSIZE)
                return READING_ERROR;
            words_arr[words_count][j] = str[i];
            if (str[i + 1] == '\0')
            {
                words_arr[words_count][j + 1] = '\0';
                words_count += 1;
            }
            j += 1;
        }
        else if (j > 0)
        {
            words_arr[words_count][j] = '\0';
            words_count += 1;
            j = 0;
        }
    }
    return words_count;
}


void print_every_word_count(char words_arr[][MAXWORDSIZE + 1], size_t words_count)
{
    printf("Result:");
    long checked_words[MAXSTRSIZE];
    for (size_t i = 0; i < words_count; i++)
        checked_words[i] = 0;
    size_t counter = 1;
    for (size_t i = 0; i < words_count; i++)
    {
        for (size_t j = i + 1; j < words_count; j++)
        {
            if (checked_words[j] == 0 && strcmp(words_arr[i], words_arr[j]) == 0)
            {
                checked_words[j] = 1;
                counter += 1;
            }
        }
        if (checked_words[i] == 0)
            printf("%s %zu\n", words_arr[i], counter);
        counter = 1;
    }
}
