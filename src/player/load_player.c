/*
** EPITECH PROJECT, 2018
** load_player
** File description:
** load_player
*/

#include "my_rpg.h"
#include <stdlib.h>

hero_t *load_hero(setting_t *setting)
{
    hero_t *hero = malloc(sizeof(hero_t));
    sfIntRect rect = { 0, 0, 64, 64};

    if (setting->type_hero == 1)
        hero->texture = get_texture("char1", setting);
    else
        hero->texture = get_texture("char2", setting);
    hero->attack = 100;
    hero->health = 100;
    hero->mana = 100;
    hero->spawn = get_spawn(setting->curr_lvl);
    hero->sprite = sfSprite_create();
    sfSprite_setTexture(hero->sprite, hero->texture, sfFalse);
    sfSprite_setTextureRect(hero->sprite, rect);
    sfSprite_setPosition(hero->sprite, (sfVector2f){ 1280 / 2, 960 / 2 });
    return hero;
}