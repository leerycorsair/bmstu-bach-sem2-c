#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAXSTRSIZE 1024

#define SUCCESS 0
#define READING_ERROR -1

/** 
 * \brief Функция для чтения строки
 * \param[in\out] str - строка для чтения
 * \param[out] - код ошибки
 */
long str_reading(char *str)
{
    printf("Enter the string:\n");
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != '\0' && i < MAXSTRSIZE)
    {
        str[i] = ch;
        i++;
    }
    if (((ch == '\n' || ch == EOF || ch == '\0') && i == 0) || i == MAXSTRSIZE)
        return READING_ERROR;
    else
    {
        str[i] = '\0';
        return SUCCESS;
    }
}

/** 
 * \brief Функция для подсчета количества строчных букв
 * \param[in] str - строка для счета
 * \param[out] counter - количество букв
 */
size_t get_lowers(char str[])
{
    size_t counter = 0;
    for (size_t i = 0; str[i]!= '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            counter += 1;
    return counter;
}

/** 
 * \brief Основная программа
 */
int main()
{
    char str[MAXSTRSIZE + 1];
    size_t lower_count;
    if (!str_reading(str))
    {
        lower_count = get_lowers(str);
        if (lower_count > 0)
            printf("Lower count = %zu", lower_count);
        else
            printf("No lowers");
        return SUCCESS;
    }
    else
    {
        return READING_ERROR;
    }
    
}