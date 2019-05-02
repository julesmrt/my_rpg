/*
** EPITECH PROJECT, 2018
** trim_whitespace
** File description:
** trim_whitespace
*/

char *trim_whitespace(char *src)
{
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == ' ')
            src[i] = src[i + 1];
    }
    return src;
}