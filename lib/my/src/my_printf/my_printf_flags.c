/*
** EPITECH PROJECT, 2018
** my_printf_flags.c
** File description:
** my_printf_flags
*/

#include "my_printf.h"

int my_printf_flags(my_printf_param_t *par)
{
    switch (par->format[par->i]) {
        case '#':
            par->flags |= POUND;
            return (1);
        case '0':
            par->flags |= ZERO_PADDED;
            return (1);
        case ' ':
            par->flags |= SPACE;
            return (1);
        case '-':
            par->flags |= LEFT_ADJUSTED;
            return (1);
        case '+':
            par->flags |= SIGN;
            return (1);
        default:
            return (0);
    }
}