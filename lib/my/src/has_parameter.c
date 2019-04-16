/*
** EPITECH PROJECT, 2018
** has_parameter.c
** File description:
** has_parameter
*/

#include "my.h"

int has_paramater(int ac, char **av, char *param)
{
    for (int i = 0; i < ac; i++) {
        while (*av[i] == '-')
            av[i]++;
        if (my_strcmp(av[i], param) == 0)
            return (1);
    }

    return (0);
}