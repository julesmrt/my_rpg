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
#include "../include/my_rpg.h"

setting_t *init_setting(void)
{
    setting_t *setting = malloc(sizeof(setting_t));
    setting->scrheight = 960;
    setting->scrwidth = 1280;
    sfVideoMode mode = {setting->scrwidth, setting->scrheight, 32};
    WINDOW = sfRenderWindow_create(mode, "Rpg", sfTitlebar , NULL);
    setting->screen = MENU_SCREEN;
    setting->menu_music = sfMusic_createFromFile("assets/musics/menu_music.ogg");
    setting->on_off = ON;
    setting->setting = -1;
    setting->vertical = sfFalse;
    sfRenderWindow_setVerticalSyncEnabled(WINDOW, setting->vertical);
    setting->fps = 60.0;
    setting->music = sfTrue;

    return setting; 
}