/*
** EPITECH PROJECT, 2018
** my_puterror.c
** File description:
** my_puterror.c
*/

#include "my.h"
#include <unistd.h>

size_t my_puterror(const char *str)
{
    size_t chars = my_strlen(str);

    write(2, str, chars);
    if (str[chars - 1] != '\n') {
        write(2, "\n", 1);
    }
    return (chars);
}