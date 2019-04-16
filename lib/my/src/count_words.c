/*
** EPITECH PROJECT, 2018
** count_words.c
** File description:
** count_words.c
*/

#include "my.h"

int count_words(char *src)
{
    int word = 0;
    int words = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (!my_is_alphanum(src[i])) {
            word = 0;
            continue;
        }
        if (!word) {
            words++;
            word = 1;
        }
    }
    return (words);
}