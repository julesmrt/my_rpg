/*
** EPITECH PROJECT, 2018
** my_printf_create_params.c
** File description:
** my_printf_create_params
*/

#include "my.h"
#include <stdlib.h>

my_printf_param_t *my_printf_create_params(const char *format)
{
    my_printf_param_t *params = malloc(sizeof(my_printf_param_t));

    params->i = 0;
    params->width = 0;
    params->flags = 0;
    params->length = 0;
    params->format = format;
    params->precision = 0;
    params->chars_printed = 0;

    return params;
}