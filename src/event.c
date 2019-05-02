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

void mouse_click_setting(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    int i;
    setting->mouse_pos = sfMouse_getPosition((sfWindow*) WINDOW);

    for (i = 0; i < 4; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            if (sfFloatRect_contains(&graphic->word->setting_rect[i], setting->mouse_pos.x, setting->mouse_pos.y) == sfTrue)
                break;
        }
    }
    setting->setting = i;
}

void mouse_click(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    int i;
    setting->mouse_pos = sfMouse_getPosition((sfWindow*) WINDOW);

    for (i = 0; i < 3; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            if (sfFloatRect_contains(&graphic->word->glob_rect[i], setting->mouse_pos.x, setting->mouse_pos.y) == sfTrue)
                break;
        }
    }
    if (i <= PLAY && i >= LEAVE)
        setting->screen = i;
}

void mouse_menu(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    setting->mouse_pos = sfMouse_getPosition((sfWindow*) WINDOW);

    for (int i = 0; i < 3; i++) {
        if (sfFloatRect_contains(&graphic->word->glob_rect[i], setting->mouse_pos.x, setting->mouse_pos.y)) {
            sfText_setColor(graphic->word->text[i], sfWhite);
        } else
            sfText_setColor(graphic->word->text[i], sfRed);
    }
    for (int i = 0; i < 3; i++) {
        if (sfFloatRect_contains(&graphic->word->setting_rect[i], setting->mouse_pos.x, setting->mouse_pos.y)) {
            sfText_setColor(graphic->word->text_setting[i], sfWhite);
        } else
            sfText_setColor(graphic->word->text_setting[i], sfRed);
    }
}

void event(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    switch(event.type)
    {
        case (sfEvtClosed):
            return destroy(setting);
        case (sfEvtKeyPressed):
            return check_quit(setting);
        case (sfEvtMouseMoved):
            return mouse_menu(event, setting, graphic);
        case (sfEvtMouseButtonPressed):
            if(setting->screen == OPTIONS)
                mouse_click_setting(event, setting, graphic);
            else
                return mouse_click(event, setting, graphic);

        default:
            break;
    }
}