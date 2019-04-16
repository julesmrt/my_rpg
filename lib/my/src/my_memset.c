/*
** EPITECH PROJECT, 2018
** my_memset.c
** File description:
** my_memset
*/

#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *temp = s;

    for (size_t i = 0; i < n; i++) {
        *temp = (unsigned char)c;
        temp++;
    }
    return s;
}