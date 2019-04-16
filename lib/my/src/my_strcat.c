/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, const char *src)
{
    size_t i = 0;
    size_t dest_len = my_strlen(dest);

    if (src == NULL || *src == '\0')
        return dest;
    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return (dest);
}