/*
** EPITECH PROJECT, 2018
** my_getopt.c
** File description:
** my_getopt
*/

#include "my.h"
#include <stdlib.h>

char *my_getopt(int ac, char **av, const char *param)
{
    for (int i = 0; i < ac; i++) {
        while (*av[i] == '-' && *av[i + 1] != '\0') {
            av[i]++;
        }
        if (my_strcmp(av[i], param) == 0)
            return i + 1 <= ac ? av[i + 1] : NULL;
    }

    return NULL;
}