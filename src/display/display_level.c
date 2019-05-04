/*
** EPITECH PROJECT, 2018
** display_level
** File description:
** display_level
*/

#include "my.h"
#include "my_rpg.h"

void display_level(level_t *level, setting_t *setting)
{
    if (level == NULL || level->tile == NULL) {
        my_printf("no level\n");
        return;
    }
    for (int i = 0; i < level->tile->layers; i++) {
        sfRenderWindow_drawVertexArray(setting->renderWindow,
            level->tile->array[i], &(level->tile->state));
    }
}