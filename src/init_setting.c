/*
** EPITECH PROJECT, 2018
** my_rpg.c
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

    return setting; 
}