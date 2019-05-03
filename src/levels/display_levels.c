/*
** EPITECH PROJECT, 2018
** display_levels
** File description:
** display_levels
*/

#include "dev.h"
#include "my.h"

void display_levels(level_t *levels)
{
    level_t *ref = levels;

    while (ref != NULL) {
        my_printf("Level:\nname: %s\n", ref->name);
        my_printf("enemies: %d\n", ref->amnt_enemies);
        my_printf("has_texture: %s\n", ref->texture == NULL ? "no" : "yes");
        if (ref->map == NULL)
            my_printf("map: no\n");
        else {
            my_printf("map:\n");
            for (int i = 0; ref->map[i] != NULL; i++) {
                my_printf("%s\n", ref->map[i]);
            }
        }
        ref = ref->next;
    }
}