/*
** EPITECH PROJECT, 2018
** my_printf.h
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_MY_PRINTF_H
#define MY_MY_PRINTF_H

enum FLAGS {
    POUND = 1 << 0,
    ZERO_PADDED = 1 << 1,
    LEFT_ADJUSTED = 1 << 2,
    SPACE = 1 << 3,
    SIGN = 1 << 4,
};

typedef struct my_printf_param {
    int i;
    int width;
    int flags;
    int precision;
    const char *format;
    unsigned int length;
    unsigned int chars_printed;
} my_printf_param_t;

int my_printf_flags(my_printf_param_t *par);

void my_printf_width(my_printf_param_t *par);
void my_printf_parsing(my_printf_param_t *par);
void my_printf_precision(my_printf_param_t *par);
void my_printf_char(my_printf_param_t *par, va_list *ap);
void my_printf_disp(my_printf_param_t *params, va_list *ap);
void my_printf_digit(my_printf_param_t *params, va_list *ap);
void my_printf_string(my_printf_param_t *params, va_list *ap);
void my_printf_specifier(my_printf_param_t *params, va_list *ap);

my_printf_param_t *my_printf_create_params(const char *format);

#endif //MY_MY_PRINTF_H
