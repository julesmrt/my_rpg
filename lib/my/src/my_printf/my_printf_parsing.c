/*
** EPITECH PROJECT, 2018
** my_printf_parsing.c
** File description:
** my_printf_parsing
*/

#include "my.h"

void my_printf_parsing(my_printf_param_t *par)
{
    if (par->flags & SPACE && par->width > 0) {
        for ( ; par->width > 0; par->width--) {
            par->chars_printed += my_putchar(' ');
        }
    }
    while (par->width > 0) {
        par->chars_printed += my_putchar(' ');
        par->width--;
    }
    while (par->precision > 0) {
        par->chars_printed += my_putchar('0');
        par->precision--;
    }
}