/*
** EPITECH PROJECT, 2018
** map_to_lvl
** File description:
** add_map_to_level
*/

#include "my_rpg.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void map_to_lvl(const char *line, char *id, level_t *level, FILE *file)
{
    int size = 0;
    char **map = NULL;
    ssize_t gtl = 1;
    char *buf = NULL;
    size_t ptr_size;
    size_t  x = 0;

    while ((gtl = getline(&buf, &x, file)) > -1) {
        if (my_strcmp(buf, "endmap") >= 0)
            break;
        ptr_size = sizeof(*map) * size;
        map = my_realloc(map, ptr_size, ptr_size * (size + 2));
        map[size++] = my_trim(buf, "\n");
    }
    if (map != NULL)
        map[size] = NULL;
    level->map = map;
}