/*
** EPITECH PROJECT, 2018
** str_replace
** File description:
** str_replace
*/

#include "my.h"
#include <stdlib.h>

char *str_replace(const char *src, const char *to_replace, char *new_value)
{
    char *res;
    size_t len = my_strlen(new_value);
    int i = my_str_str(src, to_replace);
    size_t len_to_replace = my_strlen(to_replace);

    if (i <= -1)
        return NULL;
    res = my_empty_char(my_strlen(src) + len + 1);
    res = my_memcpy(res, src, i);
    res = my_strcat(res, new_value);
    res = my_strcat(res, src +  i + len_to_replace);
    return res;
}