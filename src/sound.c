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
    if (setting->on_off == ON) {
        setting->on_off = OFF;
        sfMusic_pause(setting->menu_music);
    }
    else if (setting->on_off == OFF) {
        setting->on_off = ON;
        sfMusic_play(setting->menu_music);
        sfMusic_setLoop(setting->menu_music, sfTrue);
    }
}