/*
** EPITECH PROJECT, 2018
** my_str_str
** File description:
** my_str_str
*/

int my_str_str(const char *src, const char *token)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (src[k] != '\0') {
        i = k;
        while (src[i] != '\0' && src[i] == token[j]) {
            i++;
            j++;
        }
        if (token[j] == '\0')
            return k;
        j = 0;
        k++;
    }
    return -1;
}