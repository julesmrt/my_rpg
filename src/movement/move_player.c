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
    sfVector2f old_pos = sfSprite_getPosition(setting->hero->sprite);

    switch (code) {
        case sfKeyLeft:
            old_pos.x -= 32;
            break;
        case sfKeyRight:
            old_pos.x += 32;
            break;
        case sfKeyUp:
            old_pos.y -= 32;
            break;
        case sfKeyDown:
            old_pos.y += 32;
            break;
        default: return;
    }
    sfSprite_setPosition(setting->hero->sprite, old_pos);
}