/*
** EPITECH PROJECT, 2018
** csv_to_lvl
** File description:
** csv_to_lvl
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>

void csv_to_lvl(const char *line, char *id, level_t *level, FILE *file)
{
    int size = 0;
    size_t  x = 0;
    size_t ptr_size;
    char *buf = NULL;
    char **csv = NULL;

    while (getline(&buf, &x, file) > -1) {
        if (my_strcmp("endcsv", buf) >= 0)
            break;
        ptr_size = sizeof(*csv) * size;
        csv = my_realloc(csv, ptr_size, ptr_size * (size + 2));
        csv[size++] = my_trim(buf, "\n");
    }
    if (csv != NULL)
        csv[size] = NULL;
    level->csv = csv;
}