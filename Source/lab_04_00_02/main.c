
#include "str_handling.h"
#include <stdlib.h>

int main()
{
    char str_in[MAXSTRSIZE+1];
    char words_arr[MAXSTRSIZE+1][MAXWORDSIZE+1];
    size_t words_count;
    if (str_reading(str_in) && (words_count = get_words(str_in, words_arr)))
    {
        print_every_word_count(words_arr, words_count);
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}