/*
** EPITECH PROJECT, 2018
** get_spawn
** File description:
** get_spawn
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>

#define TILE (level->tile)

sfVector2f *get_spawn(level_t *level)
{
    int i = TILE->layers - 1;
    int j = 0;
    size_t x = 0;
    sfVertex *quad;
    sfVector2f *pos = malloc(sizeof(sfVector2f));

    pos->x = 0;
    pos->y = 0;
    while (j < TILE->height * TILE->width * 4) {
        if (level->tile->t_arr[i][j] == 553) {
            x = (i + j * TILE->width) * 4;
            quad = sfVertexArray_getVertex(TILE->array[i], x);
//            pos->x = quad[0].position.x;
//            pos->y = quad[0].position.y;
            break;
        }
        j++;
    }
    return pos;
}