/*
** EPITECH PROJECT, 2018
** move_player
** File description:
** move_player
*/

#include "my.h"
#include "my_rpg.h"

static const float MOVE = 64.0f;
void move_player(setting_t *setting, sfKeyCode code)
{
    sfTime time = sfClock_getElapsedTime(setting->clock);
    float deltatime = sfTime_asSeconds(time) * MOVE;
    sfVector2f direction = { 0.f, 0.f };

    switch (code) {
        case sfKeyLeft:
            direction.x -= MOVE * deltatime;
            break;
        case sfKeyRight:
            direction.x += MOVE * deltatime;
            break;
        case sfKeyUp:
            direction.y -= MOVE * deltatime;
            break;
        case sfKeyDown:
            direction.y += MOVE * deltatime;
            break;
        default: return;
    }
    sfSprite_move(setting->hero->sprite, direction);
    printf("x: %f, y: %f, move * deltatime: %f\n", sfSprite_getPosition(setting->hero->sprite).x, sfSprite_getPosition(setting->hero->sprite).y, MOVE * deltatime);
}