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

void destroy(setting_t *setting)
{
    sfRenderWindow_close(setting->renderWindow);
    exit(0);
}

void check_quit(setting_t *setting)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(setting->renderWindow);
    }
}