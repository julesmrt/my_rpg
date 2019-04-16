/*
** EPITECH PROJECT, 2018
** my_strpbrk.c
** File description:
** my_strpbrk.c
*/

#include "my.h"
#include <string.h>

char *my_strpbrk(const char *str, const char *accept)
{
    str += my_strspn(str, accept);
    return *str ? (char *)str : NULL;
}