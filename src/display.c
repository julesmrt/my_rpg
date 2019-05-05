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
#include "my.h"

void display_menu (setting_t *setting, graphic_t *graphic, int j)
{
    sfRenderWindow_drawSprite(setting->renderWindow, graphic->sprite->sprite_background, NULL);
    for (int i = 0; graphic->word->text[j][i] != NULL; i++) {
        sfRenderWindow_drawText(setting->renderWindow, graphic->word->text[j][i], NULL);
    }
}

void display_charracters(setting_t *setting, graphic_t *graphic)
{
    sfRenderWindow_drawSprite(setting->renderWindow, graphic->sprite->sprite_background, NULL);
    sfRenderWindow_drawText(setting->renderWindow, graphic->texture->who, NULL);
    sfRenderWindow_drawSprite(setting->renderWindow, graphic->sprite->sprite_char_man, NULL);
    sfRenderWindow_drawSprite(setting->renderWindow, graphic->sprite->sprite_char_skeleton, NULL);
}

void display(setting_t *setting, graphic_t *graphic, fight_t *fight)
{
    sfRenderWindow_clear(setting->renderWindow, sfBlack);
    switch(setting->screen)
    {
        case(MENU_SCREEN):
            display_menu(setting, graphic, 0);
            check_setting(setting, graphic);
            break;
        case(HOW_TO_PLAY_SCREEN):
            printf("ok");
            break;
        case(OPT_SCREEN):
            display_menu(setting, graphic, 1);
            check_opt(setting, graphic);
            break;
        case(OPT_GRAPH_SCREEN):
            display_menu(setting, graphic, 2);
            check_graph(setting, graphic);
            break;
        case(OPT_SOUND_SCREEN):
            display_menu(setting, graphic, 3);
            check_sound(setting, graphic);
            break;
        case(CHOOSE_SCREEN):
            display_charracters(setting, graphic);
            break;
        case(FIGHT_SCREEN):
            display_fight(setting, graphic, fight);
        case (TEST_LVL):
            display_level(setting->curr_lvl, setting);
            break;
        default:
            break;
    }
    sfRenderWindow_display(setting->renderWindow);
}