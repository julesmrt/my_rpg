/*
** EPITECH PROJECT, 2018
** tile_to_lvl
** File description:
** tile_to_lvl
*/

#include "my_rpg.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void tile_to_lvl(const char *line, char *id, level_t *level, FILE *file)
{
    if (level->csv == NULL || level->texture == NULL) {
        level->tile = NULL;
        return;
    }
    level->tile = create_tile(level->csv, level->texture);
}