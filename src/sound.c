/*
** EPITECH PROJECT, 2018
** sound.c
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

void menu_music(setting_t *setting)
{
    sfMusic *menu_music = get_song("menu", setting);
    
    if (setting->on_off == ON) {
        setting->on_off = OFF;
    }
    else if (setting->on_off == OFF && menu_music != NULL) {
        setting->on_off = ON;
        sfMusic_play(menu_music);
        sfMusic_setLoop(menu_music, sfTrue);
    }
}
