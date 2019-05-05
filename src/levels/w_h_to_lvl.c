/*
** EPITECH PROJECT, 2018
** w_h_to_lvl
** File description:
** w_h_to_lvl
*/

#include "my_rpg.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

void w_h_to_lvl(setting_t *setting, char *id, level_t *level, FILE *file)
{
    if (my_strcmp(id, "width") == 0) {
        level->width = my_strtoi(my_trim(my_strtok(NULL, ":") + 1, "\n"));
        return;
    }
    if (my_strcmp(id, "height") == 0) {
        level->height = my_strtoi(my_trim(my_strtok(NULL, ":") + 1, "\n"));
        return;
    }
}