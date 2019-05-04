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
#include <stdio.h>
#include "../include/my_rpg.h"

    const char *text[][5] = {
        {"leave", "options", "how to play", "play", NULL},
        {"back to menu", "sound", "graphical", NULL, NULL},
        {"back to option", "frame", "vertical", NULL, NULL},
        {"back to option", "on off", "intensivity", NULL, NULL}
    };

void give_opt(setting_t *setting, graphic_t *graphic, int i, int j)
{
    graphic->word->text[i][j] = sfText_create();
    sfText_setString(graphic->word->text[i][j], text[i][j]);
    sfText_setFont(graphic->word->text[i][j], graphic->word->font);
    sfText_setPosition(graphic->word->text[i][j], (sfVector2f) {graphic->word->text_x, graphic->word->text_y});
    sfText_setCharacterSize(graphic->word->text[i][j], 100.0);
    sfText_setColor(graphic->word->text[i][j], sfRed);
    graphic->word->glob_rect[i][j] = sfText_getGlobalBounds(graphic->word->text[i][j]);
    graphic->word->text[i][j + 1] = NULL;
}

void create_text(setting_t *setting, graphic_t *graphic)
{
    graphic->word->text = malloc(sizeof(sfText **) * 4);
    graphic->word->glob_rect = malloc(sizeof(sfFloatRect *) * 5);

    for (int i = 0; i != 4; i++) {
        graphic->word->text[i] = malloc(sizeof(sfText *) * 5);
        graphic->word->glob_rect[i] = malloc(sizeof(sfFloatRect) * 5);
        for (int j = 0; text[i][j] != NULL; j++, graphic->word->text_y -= 125) {
            give_opt(setting, graphic, i, j);
        }
        graphic->word->text_y = graphic->word->text_y + 125 * 3;
    }
}

word_t *create_word(setting_t *setting)
{
    word_t *word = malloc(sizeof(word_t));
    word->font = sfFont_createFromFile("assets/font/medieval.ttf");
    word->text_x = setting->scrwidth / 2.3;
    word->text_y = setting->scrheight / 2;

    return word;
}

void init_characters(setting_t *setting, graphic_t *graphic)
{
    sfSprite_setPosition(graphic->sprite->sprite_char_man, (sfVector2f) {graphic->word->text_x -75, graphic->word->text_y});
    sfSprite_setPosition(graphic->sprite->sprite_char_skeleton, (sfVector2f) {graphic->word->text_x +125, graphic->word->text_y});

    graphic->texture->who = sfText_create();
    sfText_setString(graphic->texture->who, "choose your hero");
    sfText_setFont(graphic->texture->who, graphic->word->font);
    sfText_setPosition(graphic->texture->who, (sfVector2f) {graphic->word->text_x - 250, graphic->word->text_y -250});
    sfText_setCharacterSize(graphic->texture->who, 100.0);
    sfText_setColor(graphic->texture->who, sfRed);
}

graphic_t *init_graphic(setting_t *setting)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    graphic->word = create_word(setting);
    if (graphic == NULL)
        return NULL;
    graphic->texture = create_texture();
    graphic->sprite = create_sprite(graphic);
    create_text(setting, graphic);
    init_characters(setting, graphic);
    
    return graphic;
}