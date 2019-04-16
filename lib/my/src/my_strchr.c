/*
** EPITECH PROJECT, 2018
** my_strchr.c
** File description:
** my_strchr.c
*/

#include "my.h"

char *my_strchr(const char *str, unsigned char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c) {
        i++;
    }
    if (str[i] == '\0')
        return NULL;

    return my_strdup(str + i);
}