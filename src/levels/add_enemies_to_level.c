/*
** EPITECH PROJECT, 2018
** add_enemies_to_level
** File description:
** add_enemies_to_level
*/

#include "dev.h"
#include "my.h"

void add_enemies_to_level(const char *line, char *id, level_t *level)
{
    int enemies = my_strtoi(my_trim(my_strtok(NULL, ":") + 1, "\n"));

    level->amnt_enemies = enemies;
}