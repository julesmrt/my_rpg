/*
** EPITECH PROJECT, 2018
** get_spawn
** File description:
** get_spawn
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>

sfVector2i *get_spawn(level_t *level)
{
    int i = level->tile->layers - 1;
    int j = 0;
    sfVertexArray *array = level->tile->array[i];
    sfVector2i *pos = malloc(sizeof(sfVector2i));

    for (j = 0; level->tile->t_arr[i][j]; j++) {
        if (level->tile->t_arr[i][j] == 553) {
            my_printf("Found spawn: %d\n", j);
        }
    }
    return pos;
}