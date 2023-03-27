#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

long reading_array(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (scanf("%ld", &arr[i]) != 1)
            return 0;
    }
    return 1;
}

long printing_array(long arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%ld ", arr[i]);
    }
    return 1;
}

long is_palindrome(long num)
{
    long copy = num;
    long reverse_num = 0;
    while (copy > 0)
    {
        reverse_num = reverse_num * 10 + copy % 10;
        copy = copy / 10;
    }
    if (reverse_num == num)
        return 1;
    else
        return 0;
}

long palindrome_del(long arr[], size_t *size)
{
    long check = 0;
    for (size_t i = 0; i < *size; i++)
        if (is_palindrome(arr[i]) & (arr[i] >= 0))
        {
            check = 1;
            for (size_t j = i; j < *size; j++)
            {
                arr[j] = arr[j + 1];
            }
            *size -= 1;
            i--;
        }
    return check;
}
int main()
{
    size_t size;
    long arr[MAX_SIZE];
    if (scanf("%zu", &size) != 1 || size == 0 || size > MAX_SIZE)
        return EXIT_FAILURE;
    if (reading_array(arr, size) != 1)
    {
        return EXIT_FAILURE;
    }
    palindrome_del(arr, &size);
    if (size == 0)
    {
        return EXIT_FAILURE;
    }
    printing_array(arr, size);
    return EXIT_SUCCESS;
}