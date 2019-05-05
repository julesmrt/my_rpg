/*
** EPITECH PROJECT, 2018
** csv_to_lvl
** File description:
** csv_to_lvl
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>

static const char *path = "assets/levels/";

void csv_to_lvl(const char *line, char *id, level_t *level, FILE *file)
{
    int size = 0;
    size_t  x = 0;
    size_t ptr_size;
    char *buf = NULL;
    char **csv = NULL;
    char *temp = NULL;

    while (getline(&buf, &x, file) > -1) {
        if (my_strcmp("endcsv\n", buf) >= 0)
            break;
        ptr_size = sizeof(*csv) * size;
        csv = my_realloc(csv, ptr_size, ptr_size * (size + 2));
        temp = my_empty_char(my_strlen(path) + my_strlen(buf) + 1);
        temp = my_strcat(temp, path);
        temp = my_strcat(temp, buf);
        temp = my_trim(temp, "\n");
        csv[size++] = my_strdup(temp);
    }
    if (csv != NULL)
        csv[size] = NULL;
    level->csv = csv;
}