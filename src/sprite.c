/*
** EPITECH PROJECT, 2018
** sprite.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include "../include/my_rpg.h"
#include <stdio.h>
#include <stdlib.h>

sprite_t *create_sprite(graphic_t *graphic)
{
    sprite_t *sprite = malloc(sizeof(texture_t));

    sprite->sprite_background = sfSprite_create();
    sprite->sprite_char_man = sfSprite_create();
    sprite->sprite_char_skeleton = sfSprite_create();

    sfSprite_setTexture(sprite->sprite_background, graphic->texture->background, sfTrue);
    sfSprite_setTexture(sprite->sprite_char_man, graphic->texture->char_man, sfTrue);
    sfSprite_setTexture(sprite->sprite_char_skeleton, graphic->texture->char_skeleton, sfTrue);

    return sprite;
}