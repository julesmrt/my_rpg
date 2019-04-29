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
#include <stdio.h>
#include <stdlib.h>
#include "../include/my_rpg.h"

void display_game(setting_t *setting, graphic_t *graphic)
{

}

void display_setting(setting_t *setting, graphic_t *graphic)
{
    sfRenderWindow_drawSprite(WINDOW,graphic->sprite->sprite_background, NULL);
    for (int i = 0; i != 4; i++) {
        sfRenderWindow_drawText(WINDOW, graphic->word->text_setting[i], NULL);
    }
    if (setting->setting == GRAPH_MENU) {
        setting->setting = -1;
        setting->screen = GRAPHICS;
    }

    if (setting->setting == OFF) {
        sfMusic_pause(setting->menu_music);
        setting->setting = -1;
    }
    if (setting->setting == ON && sfMusic_getStatus(setting->menu_music) == sfPaused) {
        sfMusic_play(setting->menu_music);
        setting->setting = -1;
    }
    if (setting->setting == LEAVE) {
        setting->setting = -1;
        setting->screen = MENU;
    }
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
    if (setting->screen == GAME)
        display_game(setting, graphic);
    if (setting->screen == SETTING) {
        display_setting(setting, graphic);
    }
    if (setting->screen == LEAVE)
        destroy(setting);
    sfRenderWindow_display(setting->renderWindow);
}