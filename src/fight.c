/*
** EPITECH PROJECT, 2018
** innit_setting.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

void display_fight(setting_t *setting, graphic_t *graphic, fight_t *fight)
{
    sfRenderWindow_drawSprite(setting->renderWindow, graphic->sprite->sprite_background, NULL);
    for (int i = 0; fight->hud[i] != NULL; i++) {
        sfRenderWindow_drawText(setting->renderWindow, fight->hud[i], NULL);
    }
}