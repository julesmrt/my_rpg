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

static void load_stuff(setting_t *setting)
{
    setting->musics = load_songs(get_config("songs", setting));
    setting->textures = load_textures(get_config("textures", setting));
    setting->type_hero = -1;
    setting->levels = load_levels(setting);
    setting->camera = camera(setting);
    setting->clock = sfClock_create();
}

setting_t *init_setting(void)
{
    setting_t *setting = malloc(sizeof(setting_t));

    setting->scrheight = 960;
    setting->scrwidth = 1280;
    sfVideoMode mode = {setting->scrwidth, setting->scrheight, 32};
    setting->screen = MENU_SCREEN;
    setting->renderWindow = sfRenderWindow_create(mode, "Rpg",
        sfClose | sfResize | sfTitlebar, NULL);
    setting->config = load_configs();
    setting->on_off = ON;
    setting->setting = -1;
    setting->vertical = sfFalse;
    sfRenderWindow_setVerticalSyncEnabled(setting->renderWindow, setting->vertical);
    sfRenderWindow_setFramerateLimit(setting->renderWindow, 60);
    setting->fps = 60.0;
    setting->music = sfTrue;
    load_stuff(setting);
    return setting;
}