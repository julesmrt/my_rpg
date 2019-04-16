/*
** EPITECH PROJECT, 2018
** my_printf_digit.c
** File description:
** my_printf_digit
*/

#include "my.h"
#include "my_printf.h"
#include <stdlib.h>
#include "unistd.h"

void my_printf_digit(my_printf_param_t *par, va_list *ap)
{
    int nb = va_arg(*ap, int);
    int neg = nb < 0;
    int amnt_digits = nb_amount_digits(nb);

    if (neg) {
        par->chars_printed += my_putchar('-');
        nb *= -1;
    }
    par->width -= amnt_digits + (par->precision);
    par->precision -= par->width < 0 ? 0 : par->width;
    my_printf_parsing(par);
    par->chars_printed += my_putnbr(nb);
}