/*
** EPITECH PROJECT, 2018
** my_strtok_r.c
** File description:
** my_strtok_r.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strtok_r(char *str, const char *delim, char **ptr)
{
    char *token;

    if (str == NULL)
        str = *ptr;
    if (*str == '\0') {
        *ptr = str;
        return NULL;
    }
    str += my_strspn(str, delim);
    token = str + my_strcspn(str, delim);
    if (*token == '\0') {
        *ptr = token;
        return (str);
    }
    *token = '\0';
    *ptr = token + 1;
    return (str);
}