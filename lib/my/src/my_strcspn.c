/*
** EPITECH PROJECT, 2018
** my_strcspn.c
** File description:
** my_strcspn.c
*/

#include "my.h"

int my_strcspn(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++) {
        if (char_in_str(s2, s1[i]))
            break;
    }
    return (i);
}