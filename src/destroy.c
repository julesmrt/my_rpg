/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_rpg.h"

void destroy(setting_t *setting, sfKeyCode code)
{
    sfRenderWindow_close(setting->renderWindow);
    for (int i = 0; setting->musics[i]->name != NULL; i++) {
        sfMusic_destroy(setting->musics[i]->ptr);
        free(setting->musics[i]->name);
    }
    exit(0);
}