/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, const char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return (dest);
}