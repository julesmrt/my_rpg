/*
** EPITECH PROJECT, 2018
** my_empty_charc
** File description:
** my_empty_char.c
*/

#include "my.h"
#include <stdlib.h>

char *my_empty_char(size_t n)
{
    char *res = NULL;

    if (n == 0)
        return res;
    res = malloc(n + 1);
    res = my_memset(res, '\0', n);
    return res;
}
