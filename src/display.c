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

void display_game(setting_t *setting, graphic_t *graphic)
{

}

void display_menu(setting_t *setting, graphic_t *graphic)
{
    sfRenderWindow_drawSprite(WINDOW,graphic->sprite->sprite_background, NULL);
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawText(WINDOW, graphic->word->text[i], NULL);
    }
}

void display(setting_t *setting, graphic_t *graphic)
{
    sfRenderWindow_clear(setting->renderWindow, sfBlack);
    if (setting->screen == MENU)
        display_menu(setting, graphic);
    sfRenderWindow_display(setting->renderWindow);
    if (setting->screen == GAME)
        display_game(setting, graphic);
}