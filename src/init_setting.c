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
#include "dev.h"

setting_t *init_setting(void)
{
    setting_t *setting = malloc(sizeof(setting_t));

    setting->scrheight = 960;
    setting->scrwidth = 1280;
    sfVideoMode mode = {setting->scrwidth, setting->scrheight, 32};
    WINDOW = sfRenderWindow_create(mode, "Rpg", sfClose | sfResize, NULL);
    setting->screen = MENU;
    setting->menu_music = sfMusic_createFromFile("assets/musics/menu_music.ogg");
    setting->on_off = ON;
    setting->levels = load_levels();
    if (setting->levels == NULL)
        my_printf("Error loading levels\n");
    else
        display_levels(setting->levels);
    return setting;
}