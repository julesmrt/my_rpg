/*
** EPITECH PROJECT, 2018
** my_printf_precision.c
** File description:
** my_printf_precision
*/

#include "my.h"

void my_printf_precision(my_printf_param_t *par)
{
    for (; is_digit(par->format[par->i]); par->i++) {
        par->precision = par->precision * 10 + par->format[par->i] - '0';
    }
}