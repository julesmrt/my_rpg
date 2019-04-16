/*
** EPITECH PROJECT, 2018
** nb_amount_digits.c
** File description:
** nb_amount_digits
*/

int nb_amount_digits(int nb)
{
    int amnt = 0;

    if (nb < 0) {
        nb *= -1;
        amnt++;
    }

    for ( ; nb > 0; nb /= 10) amnt++;

    return amnt;
}