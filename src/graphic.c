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

void create_setting(setting_t *setting, word_t *word)
{
    const char *text[] = {"back to menu", "sound on", "sound off", "puuuuuteuuuu", NULL};
    word->text_setting = malloc(sizeof(sfText *) * 4);
    word->setting_rect = malloc(sizeof(sfFloatRect) * 4);

    for (int i = 0; text[i] != NULL; i++, word->text_y -= 125) {
        word->text_setting[i] = sfText_create();
        sfText_setString(word->text_setting[i], text[i]);
        sfText_setFont(word->text_setting[i], word->font);
        sfText_setPosition(word->text_setting[i], (sfVector2f) {word->text_x - 100, word->text_y});
        sfText_setCharacterSize(word->text_setting[i], 100.0);
        sfText_setColor(word->text_setting[i], sfRed);
        word->setting_rect[i] = sfText_getGlobalBounds(word->text_setting[i]);
    }
}

word_t *create_word(setting_t *setting)
{
    word_t *word = malloc(sizeof(word_t));
    word->font = sfFont_createFromFile("assets/font/horror.ttf");
    word->text_x = setting->scrwidth / 2.3;
    word->text_y = setting->scrheight / 2;
    const char *text[] = {"leave", "options", "play", NULL};
    word->text = malloc(sizeof(sfText *) * 3);
    word->glob_rect = malloc(sizeof(sfFloatRect) * 3);

    for (int i = 0; text[i] != NULL; i++, word->text_y -= 125) {
        word->text[i] = sfText_create();
        sfText_setString(word->text[i], text[i]);
        sfText_setFont(word->text[i], word->font);
        sfText_setPosition(word->text[i], (sfVector2f) {word->text_x, word->text_y});
        sfText_setCharacterSize(word->text[i], 100.0);
        sfText_setColor(word->text[i], sfRed);
        word->glob_rect[i] = sfText_getGlobalBounds(word->text[i]);
    }
    word->text_y = word->text_y + 125 * 3;
    create_setting(setting, word);
    //create_graphics(setting, word);

    return word;
}

graphic_t *init_graphic(setting_t *setting)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    graphic->word = create_word(setting);
    if (graphic == NULL)
        return NULL;
    graphic->texture = create_texture();
    graphic->sprite = create_sprite(graphic);
    
    return graphic;
}