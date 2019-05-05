/*
** EPITECH PROJECT, 2018
** load_level
** File description:
** load_level
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>
#include <stdio.h>

static const level_identifier_t identifiers[] =
    {
        { "name" },
        { "texture" },
        { "enemies" },
        { "map" },
        { "song" },
        { "csv" },
        { "tile" },
        { "width" },
        { "height" },
        { NULL }
    };

static const void (*fun[])(const char *line,
    char *id, level_t *level, FILE *file) =
    {
    name_to_lvl,
    tilesheet_to_lvl,
    enemies_to_lvl,
    map_to_lvl,
    song_to_lvl,
    csv_to_lvl,
    tile_to_lvl,
    w_h_to_lvl,
    w_h_to_lvl,
    };

static void load_level_line(const char *line, level_t *level, FILE *file)
{
    char *cpy = my_strdup(line);
    char *id = my_strtok(cpy, ":");

    for (int i = 0; identifiers[i].name != NULL; i++) {
        if (my_strcmp(identifiers[i].name, id) == 0) {
            return (*fun[i])(line, id, level, file);
        }
    }
}

level_t *load_level(const char *path)
{
    ssize_t gtl = 1;
    char *buf = NULL;
    size_t  x = 0;
    level_t *res = malloc(sizeof(level_t));
    FILE *file = fopen(path, "r");

    res->amnt_enemies = 0;
    res->map = NULL;
    res->csv = NULL;
    res->name = NULL;
    res->texture = NULL;
    res->tile = NULL;
    while ((gtl = getline(&buf, &x, file)) > -1) {
        load_level_line(buf, res, file);
    }
    if (res->csv != NULL && res->texture != NULL && my_strcmp(res->name, "test") == 0) {
        res->tile = create_tile(res->csv, res);
        my_printf("tile non null\n");
    }
    res->next = NULL;
    fclose(file);
    return res;
}