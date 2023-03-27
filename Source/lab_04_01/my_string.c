#include "my_string.h"
char *my_strpbrk(const char *s1, const char *s2)
{
    char *p = NULL;
    for (size_t i = 0; s1[i] != '\0'; i++)
        for (size_t j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
            {
                p = (char*)(s1 + i);
                return p;
            }
    return p;
}
size_t my_strspn(const char *s1, const char *s2)
{
    size_t len, j; 
    for (len = 0; s1[len] != '\0'; len++)
    {
        for (j = 0; s2[j] != '\0'; j++)
            if (s2[j] == s1[len])
                break;
        if (!s2[j])
            break;
    }
    return len;
}
size_t my_strcspn(const char *s1, const char *s2)
{
    size_t len;
    for (len = 0; s1[len] != '\0'; len++)
        for (size_t j = 0; s2[j] != '\0'; j++)
            if (s1[len] == s2[j])
                return len;
    return len;
}
char *my_strchr(const char *str, int c)
{
    char *p = NULL;
    for (size_t i = 0; 1; i++)
    {
        if (str[i] == c)
        {
            p = (char*)(str + i);
            return p;
        }
        if (str[i] == '\0')
            break;
    }
    return p;
}
char *my_strrchr(const char *str, int c)
{
    char *p = NULL;
    for (size_t i = 0; 1; i++)
    {
        if (str[i] == c)
        {
            p = (char*)(str + i);
        }
        if (str[i] == '\0')
            break;
    }
    return p;
}