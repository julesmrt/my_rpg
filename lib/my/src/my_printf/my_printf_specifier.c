/*
** EPITECH PROJECT, 2018
** my_printf_specifier.c
** File description:
** my_printf_specifier
*/

#include "my_printf.h"
#include "my.h"

static const char *specifiers = "disc";
static const void (*ptr[])(my_printf_param_t *par, va_list *ap) =
    {
    my_printf_digit,
    my_printf_digit,
    my_printf_string,
    my_printf_char
    };

void my_printf_specifier(my_printf_param_t *par, va_list *ap)
{
    for (int i = 0; specifiers[i] != '\0'; i++) {
        if (par->format[par->i] == specifiers[i]) {
            return (*ptr[i])(par, ap);
        }
    }
    my_putchar('%');
}