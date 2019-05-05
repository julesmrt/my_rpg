/*
** EPITECH PROJECT, 2018
** keyboard_events
** File description:
** keyboard_events
*/

#include "my_rpg.h"

static const sfKeyCode keys[] =
    {
        sfKeyEscape,
        sfKeyLeft,
        sfKeyDown,
        sfKeyUp,
        sfKeyRight,
        -1
    };

static const void (*fun[])(setting_t *setting, sfKeyCode key) =
    {
    destroy,
    move_player,
    move_player,
    move_player,
    move_player
    };

void keyboard_events(setting_t *setting, sfKeyEvent key)
{
   for (int i = 0; keys[i] != -1; i++) {
        if (key.code == keys[i]) {
            return (*fun[i])(setting, key.code);
        }
    }
}