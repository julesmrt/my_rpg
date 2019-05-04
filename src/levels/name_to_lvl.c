/*
** EPITECH PROJECT, 2018
** name_to_lvl
** File description:
**
*/

#include "my_rpg.h"
#include "my.h"

void name_to_lvl(const char *line, char *id, level_t *level, FILE *file)
{
    level->name = my_trim(my_strtok(NULL, ":") + 1, "\n");
}