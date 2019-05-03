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

#ifndef my_rpg_HEADER_H_
#define my_rpg_HEADER_H_
#define WINDOW  (setting->renderWindow)


typedef enum my_screen
{

    PLAY_SCREEN = 5,
    MENU_SCREEN = 4,
    HOW_TO_PLAY_SCREEN = 3,
    OPT_SCREEN = 2,
    OPT_GRAPH_SCREEN = 1,
    OPT_SOUND_SCREEN = 0,

} my_screen_t;

typedef enum menu
{
    PLAY = 3,
    HOW_TO_PLAY = 2,
    OPTIONS = 1,
    LEAVE = 0,

} menu_t;

typedef enum opt
{

    GRAPHIC = 2,
    SOUND = 1,
    BACK_TO_MENU = 0,

} opt_t;

typedef enum graphic_menu
{

    VERTICAL = 2,
    FPS = 1,
    BACK_TO_OPTION_G = 0,

} graphic_menu_t;

typedef enum audio_menu
{

    INTENSITY = 2,
    ON_OFF = 1,
    BACK_TO_OPTION_S = 0,

} audio_menu_t;

typedef enum menu_music {

    OFF = 2,
    ON = 1,

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
    sfText ***text;
    float text_x;
    float text_y;
    sfFloatRect **glob_rect;

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
    int option;
    int screen;
    int setting;
    graphic_t *graphic;
    sfVector2i mouse_pos;
    sfMusic *menu_music;
    int on_off;
    int music_is_running;
    menu_music_t *menu_mus;
    menu_t *menu;
    opt_t *opt;
    graphic_menu_t *graphic_menu;
    audio_menu_t *audio_menu;
    my_screen_t *my_screen;
    sfBool vertical;
    float fps;
    sfBool music;


} setting_t;

int my_rpg(void);

//init_setting.c
setting_t *init_setting(void);

//event.c
void event(sfEvent event, setting_t *setting, graphic_t *graphic);
void mouse_moved(sfEvent event, setting_t *setting, graphic_t *graphic);
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
void display_menu(setting_t *setting, graphic_t *graphic, int j);
void display(setting_t *setting, graphic_t *graphic);
void display_setting(setting_t *setting, graphic_t *graphic);
void mouse_click_setting(sfEvent event, setting_t *setting, graphic_t *graphic);
void display_graph(setting_t *setting, graphic_t *graphic);

//sound.c
void menu_music(setting_t *setting);

void check_setting(setting_t *setting, graphic_t *graphic);
void check_opt(setting_t *setting, graphic_t *graphic);
void check_graph(setting_t *setting, graphic_t *graphic);
void check_sound(setting_t *setting, graphic_t *graphic);

#endif
