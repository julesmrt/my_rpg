/*
** EPITECH PROJECT, 2018
** my_trim.c
** File description:
** Removes characters from to_remove
*/

#include "my.h"
#include <stdlib.h>

char *my_trim(const char *src, const char *to_remove)
{
    int j = 0;
    char *res = my_empty_char(my_strlen(src));

    for (int i = 0; src[i] != '\0'; i++) {
        if (!char_in_str(to_remove, src[i])) {
            res[j++] = src[i];
        }
    }
    res[j] = '\0';
    return (res);
}