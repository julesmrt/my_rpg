/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include "../include/my_rpg.h"
#include <stdlib.h>
#include <stdio.h>

enemy_t *init_enemy(setting_t *setting, graphic_t *graphic)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->attack = 2;
    enemy->health = 15;

    return enemy;
}

hero_t *init_hero(setting_t *setting, graphic_t *graphic)
{
    hero_t *hero = malloc(sizeof(hero_t));

    hero->attack = 3;
    hero->health = 20;
    hero->mana = 15;
    hero->type = -1;

    return hero;
}

fight_t *init_fight(setting_t *setting, graphic_t *graphic)
{
    fight_t *fight = malloc(sizeof(fight_t));
    enemy_t *enemy = init_enemy(setting, graphic);
    hero_t *hero = init_hero(setting, graphic);

    return fight;
}