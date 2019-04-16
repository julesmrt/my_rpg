/*
** EPITECH PROJECT, 2018
** my_strspn.c
** File description:
** my_strspn.c
*/

#include "my.h"

int my_strspn(const char *src, const char *accept)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        if (!char_in_str(accept, src[i]))
            break;
    }
    return (i);
}