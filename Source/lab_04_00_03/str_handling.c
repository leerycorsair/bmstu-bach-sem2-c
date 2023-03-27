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


void form_new_str(char words_arr[][MAXWORDSIZE + 1], size_t words_count, char str[])
{
    size_t str_len = 0;
    long i = words_count - 1;
    while (i >= 0)
    {
        if (strcmp(words_arr[i], words_arr[words_count - 1]) != 0)
        {
            for (size_t j = 0; words_arr[i][j] != '\0'; j++)
                if (words_arr[i][j] != words_arr[i][0] || j == 0)
                {
                    str[str_len] = words_arr[i][j];
                    str_len += 1;
                }
            str[str_len] = ' ';
            str_len += 1;
        }
        if (i == 0)
            break;
        i -= 1;
    }
    if (str[str_len - 1] == ' ')
        str_len -= 1;
    str[str_len] = '\0';
}
