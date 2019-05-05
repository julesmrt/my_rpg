/*
** EPITECH PROJECT, 2018
** get_texture
** File description:
** get_texture
*/

#include "my.h"
#include "my_rpg.h"

sfTexture *get_texture(const char *name, setting_t *setting)
{
    for (int i = 0; setting->textures[i]->name != NULL; i++) {
        if (my_strcmp(name, setting->textures[i]->name) == 0)
            return setting->textures[i]->ptr;
    }
    return NULL;
}