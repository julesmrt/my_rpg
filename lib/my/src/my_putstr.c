/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr
*/

#include "my.h"
#include <unistd.h>

int my_putstr(const char *str)
{
    return ((int)write(1, str, (size_t)my_strlen(str)));
}