/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen
*/

#include "stddef.h"
#include <sys/types.h>

size_t my_strlen(const char *str)
{
    size_t i = 0;

    if (str == NULL)
        return 0;
    for ( ; str[i] != '\0'; i++);
    return (i);
}