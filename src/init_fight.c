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

const char *hud[] = 
    {"hp", "mana", "hp", NULL};

void place_hud(setting_t *setting, graphic_t *graphic, fight_t *fight)
{
    fight->hud = malloc(sizeof(sfText *) * 4);

    for (int i = 0; hud[i] != NULL; i++) {
        fight->hud[i] = sfText_create();
        sfText_setFont(fight->hud[i], graphic->word->font);
        sfText_setCharacterSize(fight->hud[i], 75.0);
        sfText_setColor(fight->hud[i], sfRed);
    }
    sfText_setString(fight->hud[0], integer_to_str(fight->hero->health));
    sfText_setString(fight->hud[1], integer_to_str(fight->hero->mana));
    sfText_setString(fight->hud[2], integer_to_str(fight->ennemy->health));
    sfText_setPosition(fight->hud[0], (sfVector2f) {100, 855});
    sfText_setPosition(fight->hud[1], (sfVector2f) {250, 855});
    sfText_setPosition(fight->hud[2], (sfVector2f) {1000, 855});
    sfText_setColor(fight->hud[1], sfBlue);
    fight->hud[3] = NULL;
}

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
    fight->ennemy = init_enemy(setting, graphic);
    fight->hero = init_hero(setting, graphic);

    place_hud(setting, graphic, fight);

    return fight;
}