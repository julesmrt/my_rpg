/*
** EPITECH PROJECT, 2018
** display_level
** File description:
** display_level
*/

#include "my.h"
#include "my_rpg.h"

void display_level(level_t *level, setting_t *setting)
{
    sfVector2f p_pos;

    if (level == NULL || level->tile == NULL)
        return;
    for (int i = 0; i < level->tile->layers - 1; i++) {
        sfRenderWindow_drawVertexArray(setting->renderWindow,
            level->tile->array[i], &(level->tile->state));
    }
    p_pos.x = sfSprite_getGlobalBounds(setting->hero->sprite).left;
    p_pos.y = sfSprite_getGlobalBounds(setting->hero->sprite).top;
    display_player(setting);
    sfView_setCenter(setting->camera, p_pos);
    sfRenderWindow_setView(setting->renderWindow, setting->camera);
}