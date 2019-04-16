/*
** EPITECH PROJECT, 2018
** char_in_str.c
** File description:
** char_in_str.c
*/

int char_in_str(const char *src, char c)
{
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == c)
            return (1);
    }
    return (0);
}