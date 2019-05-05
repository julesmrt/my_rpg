/*
** EPITECH PROJECT, 2018
** camera
** File description:
** camera
*/

#include "my_rpg.h"

sfView *camera(setting_t *setting)
{
    float x = sfRenderWindow_getSize(setting->renderWindow).x;
    float y = sfRenderWindow_getSize(setting->renderWindow).y;
    sfView *view = NULL;

    view = sfView_createFromRect((sfFloatRect){ x / 2, y / 2, x, y });
    return view;
}