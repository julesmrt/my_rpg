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

    if (setting->type_hero == 1)
        hero->texture = get_texture("char1", setting);
    else
        hero->texture = get_texture("char2", setting);
    hero->attack = 100;
    hero->health = 100;
    hero->mana = 100;
    hero->spawn = get_spawn(setting->curr_lvl);
    return hero;
}