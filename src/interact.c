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

void check_sound(setting_t *setting, graphic_t *graphic)
{
    switch(setting->setting)
    {
        case(INTENSITY):
        printf("ok");
        setting->setting = -1;
        break;
        case(ON_OFF):
        menu_music(setting);
        setting->setting = -1;
        break;
        case(BACK_TO_OPTION_S):
        setting->screen = OPT_SCREEN;
        setting->setting = -1;
    }
}

void check_graph(setting_t *setting, graphic_t *graphic)
{
    switch(setting->setting)
    {
        case(VERTICAL):
        if (setting->vertical == sfFalse) {
            setting->vertical = sfTrue;
        }
        else if (setting->vertical == sfTrue)
            setting->vertical = sfFalse;
        sfRenderWindow_setVerticalSyncEnabled(setting->renderWindow, setting->vertical);
        setting->setting = -1;
        break;
        case(FPS):
        if (setting->fps == 60.0)
            setting->fps = 120.0;
        else if (setting->fps == 120.0)
            setting->fps = 30.0;
        else if (setting->fps == 30.0)
            setting->fps = 60.0;
        setting->setting = -1;
        break;
        case(BACK_TO_OPTION_G):
        setting->screen = OPT_SCREEN;
        setting->setting = -1;
        break;
    }
}

void check_opt(setting_t *setting, graphic_t *graphic)
{
    switch(setting->setting)
    {
        case(GRAPHIC):
        setting->screen = OPT_GRAPH_SCREEN;
        setting->setting = -1;
        break;
        case(SOUND):
        setting->screen = OPT_SOUND_SCREEN;
        setting->setting = -1;
        break;
        case(BACK_TO_MENU):
        setting->screen = MENU_SCREEN;
        setting->setting = -1;
        break;
    }
}

void check_setting(setting_t *setting, graphic_t *graphic)
{
    switch(setting->setting) {
        case(LEAVE):
            destroy(setting);
            break;
        case(OPTIONS):
            setting->screen = OPT_SCREEN;
            setting->setting = -1;
            break;
        case(HOW_TO_PLAY):
            break;
        case(PLAY):
            setting->screen = PLAY_SCREEN;
            setting->setting = -1;
            break;
    }
}