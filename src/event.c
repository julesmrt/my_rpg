/*
** EPITECH PROJECT, 2018
** my_rpg.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include "../include/my_rpg.h"
#include <stdio.h>

int get_screen(setting_t *setting, graphic_t *graphic)
{
    int i;
    setting->mouse_pos = sfMouse_getPosition((sfWindow*) setting->renderWindow);

    switch(setting->screen)
    {
        case(MENU_SCREEN):
        i = 0;
        break;
        case(OPT_SCREEN):
        i = 1;
        break;
        case(OPT_GRAPH_SCREEN):
        i = 2;
        break;
        case(OPT_SOUND_SCREEN):
        i = 3;
        break;
    }

    return i;
}

void mouse_moved(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    setting->mouse_pos = sfMouse_getPosition((sfWindow*) setting->renderWindow);

    for (int i = 0; i != 4; i++) {
        for (int j = 0; graphic->word->text[i][j]; j++) {
            if (sfFloatRect_contains(&graphic->word->glob_rect[i][j], setting->mouse_pos.x, setting->mouse_pos.y)) {
                sfText_setColor(graphic->word->text[i][j], sfWhite);
            } else
                sfText_setColor(graphic->word->text[i][j], sfRed);
        }
    }
    if (sfFloatRect_contains(&graphic->texture->char_rect[0], setting->mouse_pos.x, setting->mouse_pos.y)) {
        sfSprite_setColor(graphic->sprite->sprite_char_man, sfRed);
    } else
        sfSprite_setColor(graphic->sprite->sprite_char_man, sfWhite);
    if (sfFloatRect_contains(&graphic->texture->char_rect[1], setting->mouse_pos.x, setting->mouse_pos.y)) {
        sfSprite_setColor(graphic->sprite->sprite_char_skeleton, sfRed);
    } else
        sfSprite_setColor(graphic->sprite->sprite_char_skeleton, sfWhite);
}

void mouse_clicked(sfEvent event, setting_t *setting, graphic_t *graphic, int o)
{
    int i;
    setting->mouse_pos = sfMouse_getPosition((sfWindow *) setting->renderWindow);

    for (i = 0; graphic->word->text[o][i] != NULL; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            if (sfFloatRect_contains(&graphic->word->glob_rect[o][i], setting->mouse_pos.x, setting->mouse_pos.y) == sfTrue) {
                setting->setting = i;
                break;
            }
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        if (sfFloatRect_contains(&graphic->texture->char_rect[0], setting->mouse_pos.x, setting->mouse_pos.y)) {
            setting->type_hero = 1;
            setting->screen = FIGHT_SCREEN;
        }
        if(sfFloatRect_contains(&graphic->texture->char_rect[1], setting->mouse_pos.x, setting->mouse_pos.y)) {
            setting->type_hero = 2;
            setting->screen = FIGHT_SCREEN;
        }
}

void event(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    switch(event.type)
    {
        case (sfEvtClosed):
            return destroy(setting);
        case (sfEvtKeyPressed):
            check_quit(setting);
        break;
        case (sfEvtMouseMoved):
            mouse_moved(event, setting, graphic);
        break;
        case (sfEvtMouseButtonPressed):
            mouse_clicked(event, setting, graphic, get_screen(setting, graphic));
        break;
        default:
            break;
    }
}
