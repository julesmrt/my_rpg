/*
** EPITECH PROJECT, 2018
** my_memcpy.c
** File description:
** my_memcpy.c
*/

#include "stdio.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    while (n--) {
        *d++ = *s++;
    }
    return dest;
}