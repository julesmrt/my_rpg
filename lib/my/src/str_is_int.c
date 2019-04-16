/*
** EPITECH PROJECT, 2018
** str_is_int.c
** File description:
** str_is_int
*/

#include "my.h"

int str_is_int(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-')
            continue;
        if (!is_digit(str[i]))
            return (0);
    }
    return (1);
}