/*
** EPITECH PROJECT, 2018
** texture.c
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

texture_t *create_texture(void)
{
    texture_t *texture = malloc(sizeof(texture_t));

    texture->background = sfTexture_createFromFile
    ("assets/menu/white_walker.jpg", NULL);
    texture->rules = sfTexture_createFromFile
    ("assets/menu/rules.png", NULL);

    return texture;
}