#define __USE_MINGW_ANSI_STDIO
#include "my_string.h"
#include <string.h>
#include <stdio.h>


int main()
{
    if (my_strpbrk("MAMA", "PAPA") != strpbrk("MAMA", "PAPA"))
    {
        printf("test my_strpbrk(MAMA, PAPA) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strpbrk("DED\0PAPA", "PAPA") != strpbrk("DED\0PAPA", "PAPA"))
    {
        printf("test my_strpbrk(DED\\0PAPA, PAPA) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strpbrk("", "PAPA") != strpbrk("", "PAPA"))
    {
        printf("test my_strpbrk( , PAPA) is incorrect.");
        return EXIT_FAILURE;
    }


    if (my_strspn("PAPAPAPA", "PA") != strspn("PAPAPAPA", "PA"))
    {
        printf("test my_strspn (PAPAPAPA, PA) is incorrect.");

        return EXIT_FAILURE;
    }
    if (my_strspn("MA", "PA") != strspn("MA", "PA"))
    {
        printf("test my_strspn (MA, PA) is incorrect.");

        return EXIT_FAILURE;
    }


    if (my_strcspn("THE BIGGEST STRING", "ABCDE") != strcspn("THE BIGGEST STRING", "ABCDE"))
    {
        printf("test my_strcspn (THE BIGGEST STRING, ABCDE) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strcspn("THE SMALLEST STRING", "A") != strcspn("THE SMALLEST STRING", "A"))
    {
        printf("test my_strcspn (THE SMALLEST STRING, A) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strcspn("THE NORMAL STRING", "D") != strcspn("THE NORMAL STRING", "D"))
    {
        printf("test my_strcspn (THE NORMAL STRING, D) is incorrect.");
        return EXIT_FAILURE;
    }


    if (my_strchr("EXAMPLE 1", 'A') != strchr("EXAMPLE 1", 'A'))
    {
        printf("test my_strchr (EXAMPLE 1, A ) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strchr("EXAMPLE 2", '\0') != strchr("EXAMPLE 2", '\0'))
    {
        printf("test my_strchr (EXAMPLE 2, \\0 ) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strchr("EXAMPLE 3", 'B') != strchr("EXAMPLE 3", 'B'))
    {
        printf("test my_strchr (EXAMPLE 3, B ) is incorrect.");
        return EXIT_FAILURE;
    }

    if (my_strrchr("EXAMPLE 1A", 'A') != strrchr("EXAMPLE 1A", 'A'))
    {
        printf("test my_strchr (EXAMPLE 1A, A ) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strrchr("EXAMPLE 2", '\0') != strrchr("EXAMPLE 2", '\0'))
    {
        printf("test my_strchr (EXAMPLE 2, \\0 ) is incorrect.");
        return EXIT_FAILURE;
    }
    if (my_strrchr("EXAMPLE 3B", 'B') != strrchr("EXAMPLE 3B", 'B'))
    {
        printf("test my_strchr (EXAMPLE 3B, B ) is incorrect.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
