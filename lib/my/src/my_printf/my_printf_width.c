/*
** EPITECH PROJECT, 2018
** my_printf_width.c
** File description:
** my_printf_width
*/

#include "my.h"

void my_printf_width(my_printf_param_t *par)
{
    for (; is_digit(par->format[par->i]); par->i++) {
        par->width = (par->width * 10) + (par->format[par->i] - '0');
    }
}