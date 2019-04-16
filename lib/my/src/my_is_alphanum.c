/*
** EPITECH PROJECT, 2018
** my_is_alphanum.c
** File description:
** my_is_alphanum.c
*/

#include "my.h"

int my_is_alphanum(char c)
{
    return (my_is_alpha(c) || (c >= '0' && c <= '9'));
}