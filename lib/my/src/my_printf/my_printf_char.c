/*
** EPITECH PROJECT, 2018
** my_printf_char.c
** File description:
** my_printf_char.c
*/

#include "my.h"
#include "my_printf.h"

void my_printf_char(struct my_printf_param *par, va_list *ap)
{
    par->chars_printed += my_putchar((char) va_arg(*ap, int));
}