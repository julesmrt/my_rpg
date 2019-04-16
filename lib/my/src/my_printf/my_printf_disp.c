/*
** EPITECH PROJECT, 2018
** my_printf_disp.c
** File description:
** my_printf_disp
*/

#include "my.h"

void my_printf_disp(my_printf_param_t *params, va_list *ap)
{
    params->flags = 0;
    params->precision = 0;
    params->width = 0;
    params->i++;
    while (my_printf_flags(params)) params->i++;
    my_printf_width(params);
    if (params->format[params->i] == '.') {
        params->i++;
        my_printf_precision(params);
    }
    my_printf_specifier(params, ap);
}