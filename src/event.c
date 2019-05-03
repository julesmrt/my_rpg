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
    setting->mouse_pos = sfMouse_getPosition((sfWindow*) WINDOW);

    for (int i = 0; i != 4; i++) {
        for (int j = 0; graphic->word->text[i][j]; j++) {
            if (sfFloatRect_contains(&graphic->word->glob_rect[i][j], setting->mouse_pos.x, setting->mouse_pos.y)) {
                sfText_setColor(graphic->word->text[i][j], sfWhite);
            } else
                sfText_setColor(graphic->word->text[i][j], sfRed);
        }
    }
}

void mouse_clicked(sfEvent event, setting_t *setting, graphic_t *graphic, int o)
{
    int i;
    setting->mouse_pos = sfMouse_getPosition((sfWindow *) WINDOW);

    for (i = 0; graphic->word->text[o][i] != NULL; i++) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            if (sfFloatRect_contains(&graphic->word->glob_rect[o][i], setting->mouse_pos.x, setting->mouse_pos.y) == sfTrue) {
                setting->setting = i;
                break;
            }
    }
}

void event(sfEvent event, setting_t *setting, graphic_t *graphic)
{
    switch(event.type)
    {
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
