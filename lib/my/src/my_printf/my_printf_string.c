/*
** EPITECH PROJECT, 2018
** my_printf_string.c
** File description:
** my_printf_string
*/

#include "my.h"

void my_printf_string(my_printf_param_t *params, va_list *ap)
{
    char *to_print = va_arg(*ap, char *);
    params->width -= my_strlen(to_print);

    my_printf_parsing(params);
    params->chars_printed += my_putstr(to_print);
}