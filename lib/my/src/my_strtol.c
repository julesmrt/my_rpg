/*
** EPITECH PROJECT, 2018
** my_strtol.c
** File description:
** my_strtol.c
*/

#include "my.h"

static int my_src(char c)
{
    if (is_digit(c))
        return my_ctoi(c);
    else
        return (int)c - 'A' + 10;
}

long my_strtol(const char *src, int base)
{
    long strtoi = my_strtoi(src);
    long result = 0;
    int neg = strtoi < 0;

    if (neg)
        strtoi *= -1;
    while (strtoi != 0) {
        result = (result * 10) + (strtoi % base);
        strtoi /= base;
    }
    return (neg ? result * -1 : result);
}
