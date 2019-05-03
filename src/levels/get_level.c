/*
** EPITECH PROJECT, 2018
** get_level
** File description:
** get_level
*/

#include "my_rpg.h"
#include "my.h"

level_t *get_level(setting_t *settings, const char *name)
{
    level_t *ref = settings->levels;

    while (ref != NULL) {
        if (my_strcmp(name, ref->name) == 0)
            return ref;
        ref = ref->next;
    }
    return NULL;
}