/*
** EPITECH PROJECT, 2018
** display.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include "../include/my_rpg.h"

void display(setting_t *setting, graphic_t *graphic)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawSprite(WINDOW,graphic->sprite->sprite_background, NULL);
    sfRenderWindow_display(WINDOW);
}