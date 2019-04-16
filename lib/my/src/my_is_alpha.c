/*
** EPITECH PROJECT, 2018
** my_is_alpha.c
** File description:
** my_is_alpha.c
*/

int my_is_alpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}