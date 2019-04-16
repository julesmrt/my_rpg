/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** my_putnbr
*/

#include "my.h"
#include "unistd.h"

int my_putnbr(int nb)
{
    char buffer[11];
    int printed = 0;
    int neg = nb < 0 ? 1 : 0;
    int i = 0;

    if (neg) {
        nb *= -1;
        my_putchar('-');
        printed++;
    }
    if (nb == 0)
        return my_putchar('0');
    while (nb > 0) {
        buffer[i] = nb % 10 + '0';
        i++;
        nb /= 10;
    }
    buffer[i] = '\0';
    my_rev_str(buffer);
    return (printed + my_putstr(buffer));
}