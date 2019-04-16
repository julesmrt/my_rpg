/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
    size_t len = my_strlen(src) + 1;
    void *res = malloc(len);

    if (res == NULL)
        return NULL;
    return (char *) my_memcpy(res, src, len);
}