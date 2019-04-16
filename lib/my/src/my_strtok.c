/*
** EPITECH PROJECT, 2018
** my_strtok.c
** File description:
** my_strtok.c
*/

#include "my.h"
#include <stdio.h>

char *my_strtok(char *str, const char *delim)
{
    static char *olds = NULL;

    return my_strtok_r(str, delim, &olds);
}