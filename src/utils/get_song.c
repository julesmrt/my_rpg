/*
** EPITECH PROJECT, 2018
** get_song
** File description:
** get_song
*/

#include "my.h"
#include "my_rpg.h"

sfMusic *get_song(const char *name, setting_t *setting)
{
    for (int i = 0; setting->musics[i]->name != NULL; i++) {
        if (my_strcmp(name, setting->musics[i]->name) == 0)
            return setting->musics[i]->ptr;
    }
    return NULL;
}