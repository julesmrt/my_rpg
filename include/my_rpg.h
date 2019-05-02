/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include "dev.h"

#ifndef my_rpg_HEADER_H_
#define my_rpg_HEADER_H_
#define WINDOW  (setting->renderWindow)

typedef enum menu {

    PLAY = 2,
    OPTIONS = 1,
    LEAVE = 0,

} menu_t;

typedef enum game {

    GRAPHICS = 4,
    MENU = 3,
    GAME = 2,
    SETTING = 1,
    EXIT = 0,

} game_t;

typedef enum menu_music {

    GRAPH_MENU = 3,
    OFF = 2,
    ON = 1,
    BACK = 0,

} menu_music_t;


typedef struct sprite
{
    sfSprite *sprite_background;

} sprite_t;

typedef struct texture
{
    sfTexture *background;

} texture_t;

typedef struct word
{

    sfFont *font;
    sfText **text;
    sfText **text_setting;
    float text_x;
    float text_y;
    sfFloatRect *glob_rect;
    sfFloatRect *setting_rect;
    sfFloatRect *graph_rect;

} word_t;

typedef struct graphic
{
    texture_t *texture;
    sprite_t *sprite;
    word_t *word;

} graphic_t;

typedef struct setting
{
    sfRenderWindow *renderWindow;
    int scrwidth;
    int scrheight;
    sfEvent events;
    menu_t *menu;
    int option;
    game_t *game;
    int screen;
    int setting;
    graphic_t *graphic;
    sfVector2i mouse_pos;
    sfMusic *menu_music;
    int on_off;
    int music_is_running;
    menu_music_t *menu_mus;
    level_t *levels;
} setting_t;

int my_rpg(void);

//init_setting.c
setting_t *init_setting(void);

//event.c
void event(sfEvent event, setting_t *setting, graphic_t *graphic);
void mouse_menu(sfEvent event, setting_t *setting, graphic_t *graphic);
void mouse_click(sfEvent event, setting_t *setting, graphic_t *graphic);

//destroy.c
void check_quit(setting_t *setting);
void destroy(setting_t *setting);

//sprite.c
sprite_t *create_sprite(graphic_t *graphic);

//texture.c
texture_t *create_texture(void);

//graphic.c
graphic_t *init_graphic(setting_t *setting);
word_t *create_word(setting_t *setting);

//diplay.c
void display_menu(setting_t *setting, graphic_t *graphic);
void display(setting_t *setting, graphic_t *graphic);
void display_setting(setting_t *setting, graphic_t *graphic);
void mouse_click_setting(sfEvent event, setting_t *setting, graphic_t *graphic);

//sound.c
void menu_music(setting_t *setting);

#endif
