/*
** EPITECH PROJECT, 2018
** my_rev_str.c
** File description:
** my_rev_str
*/

#include "my.h"
#include <stdlib.h>

void my_rev_str(char *str)
{
    char temp;
    int j = my_strlen(str) - 1;

    if (str == NULL || my_strlen(str) == 0)
        return;
    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j--] = temp;
    }

}