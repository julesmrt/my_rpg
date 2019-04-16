/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

int my_printf(const char *format, ...)
{
    va_list ap;
    my_printf_param_t *params = my_printf_create_params(format);

    va_start(ap, format);
    for (params->i = 0; format[params->i] != '\0'; params->i++) {
        if (format[params->i] != '%') {
            my_putchar(format[params->i]);
            params->chars_printed++;
            continue;
        }
        if (format[params->i] == '%') {
            my_printf_disp(params, &ap);
        }
    }
    va_end(ap);
    return params->chars_printed;
}