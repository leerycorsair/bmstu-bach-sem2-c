
#include "str_handling.h"
#include <stdlib.h>

int main()
{
    char str_in[MAXSTRSIZE+1];
    char words_arr[MAXSTRSIZE+1][MAXWORDSIZE+1];
    char str_out [MAXSTRSIZE+1];
    size_t words_count;
    if (str_reading(str_in) && (words_count = get_words(str_in, words_arr)))
    {
        form_new_str(words_arr, words_count, str_out);
        if (str_out[0] != '\0')
        {
            printf("Result: %s\n", str_out);
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }          
    }
    else
    {
        return EXIT_FAILURE;
    }
}