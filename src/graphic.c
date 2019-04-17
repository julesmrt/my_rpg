/*
** EPITECH PROJECT, 2018
** graphic.c
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

graphic_t *init_graphic(setting_t *setting)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    graphic->texture = create_texture();
    graphic->sprite = create_sprite(graphic);

    return graphic;
}