/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include "../include/my_rpg.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char *av[])
{
    setting_t *setting = init_setting();
    graphic_t *graphic = init_graphic(setting);
    setting->music_is_running = OFF;

    while (sfRenderWindow_isOpen(WINDOW)) {
        while (sfRenderWindow_pollEvent(setting->renderWindow, &setting->events)) {
            event(setting->events, setting, graphic);
            if (setting->music_is_running == OFF) {
                menu_music(setting);          
            }
        }
        display(setting, graphic);
    }
    destroy(setting);
    return 0;
}
