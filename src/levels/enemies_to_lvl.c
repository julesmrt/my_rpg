/*
** EPITECH PROJECT, 2018
** enemies_to_lvl
** File description:
**
*/

#include "my_rpg.h"
#include "my.h"

void enemies_to_lvl(const char *line, char *id, level_t *level, FILE *file)
{
    level->amnt_enemies = my_strtoi(my_trim(my_strtok(NULL, ":") + 1, "\n"));
}