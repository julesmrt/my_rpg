/*
** EPITECH PROJECT, 2018
** load_level
** File description:
** load_level
*/

#include "dev.h"
#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>
#include <stdio.h>

static const level_identifier_t identifiers[] =
    {
        { "name" },
        { "tilesheet" },
        { "enemies" },
        { "map" },
        { NULL }
    };

static const void (*fun[])(const char *line, char *id, level_t *level) =
    {
    add_name_to_level,
    add_tilesheet_to_level,
    add_enemies_to_level,
    add_map_to_level,
    };

static void load_level_line(const char *line, level_t *level)
{
    char *cpy = my_strdup(line);
    char *id = my_strtok(cpy, ":");

    for (int i = 0; identifiers[i].name != NULL; i++) {
        if (my_strcmp(identifiers[i].name, id) == 0) {
            return (*fun[i])(line, id, level);
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

    while ((gtl = getline(&buf, &x, file)) > -1) {
        res->amnt_enemies = 0;
        load_level_line(buf, res);
    }
    res->next = NULL;
    fclose(file);
    return res;
}