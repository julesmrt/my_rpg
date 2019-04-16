/*
** EPITECH PROJECT, 2018
** my_strtoi.c
** File description:
** my_strtoi
*/

#include "my.h"

long my_strtoi(const char *str)
{
    long result = 0;
    int i = 0;
    int neg = 0;

    while (str[i] == '-') {
        neg = 1;
        i++;
    }

    for ( ; is_digit(str[i]) && str[i] != '\0'; i++) {
        result = (result * 10) + (long)my_ctoi(str[i]);
    }
    return (neg ? result * -1 : result);
}