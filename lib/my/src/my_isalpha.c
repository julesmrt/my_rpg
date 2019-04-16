/*
** EPITECH PROJECT, 2018
** my_isalpha.c
** File description:
** my_isalpha.c
*/

int is_alpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}