/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>

int my_str_to_word_array(char *src, char ***dest)
{
    int i = 0;
    int letters = 0;
    int res_index = 0;
    int amnt_words = count_words(src);
    char **result = malloc(sizeof(char *) * amnt_words + 1);

    for (i = 0; src[i] != '\0'; i++) {
        if ((src[i] == ' ' || src[i] == '\t') && letters) {
            result[res_index++] = my_strncpy(src + (i - letters), letters);
            letters = 0;
        } else if (src[i] == ' ' || src[i] == '\t') {
            letters = 0;
        } else
            letters++;
    }
    if (letters)
        result[res_index++] = my_strncpy(src + (i - letters), letters);
    result[res_index] = NULL;
    *dest = result;
    return (amnt_words);
}