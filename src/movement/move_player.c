/*
** EPITECH PROJECT, 2018
** move_player
** File description:
** move_player
*/

#include "my.h"
#include "my_rpg.h"

void move_player(setting_t *setting, sfKeyCode code)
{
    sfVector2f offset = { 0.f, 0.f };

    if (setting->camera == NULL) {
        my_printf("Error fuck off\n");
        return;
    }

    switch (code) {
        case sfKeyLeft:
            offset.x = -1000;
            break;
        case sfKeyRight:
            offset.x = 1000;
            break;
        case sfKeyUp:
            offset.y = -1000;
            break;
        case sfKeyDown:
            offset.y = 1000;
            break;
        case sfKeySpace:
            sfView_zoom(setting->camera, 1.5f);
            return;
        default: return;
    }
    sfView_move(setting->camera, offset);
}