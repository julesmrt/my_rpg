/*
** EPITECH PROJECT, 2018
** add_name_to_level
** File description:
** add_name_to_level
*/

#include "dev.h"
#include "my.h"

void add_name_to_level(const char *line, char *id, level_t *level)
{
    level->name = my_trim(my_strdup(my_strtok(NULL, ":") + 1), "\n");
}