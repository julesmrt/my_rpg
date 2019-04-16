/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include <stdlib.h>

char *my_strncpy(const char *src, int n)
{
    int i = 0;
    char *result = malloc(sizeof(char) * n + 1);

    for (i = 0; src[i] != '\0' && i < n; i++) {
        result[i] = src[i];
    }
    result[i] = '\0';

    return (result);
}