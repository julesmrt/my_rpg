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
#include <stdio.h>

#ifndef my_rpg_HEADER_H_
#define my_rpg_HEADER_H_

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

typedef struct sprite {
    sfSprite *sprite_background;
} sprite_t;

typedef struct texture {
    sfTexture *background;
} texture_t;

typedef struct word {
    sfFont *font;
    sfText **text;
    sfText **text_setting;
    float text_x;
    float text_y;
    sfFloatRect *glob_rect;
    sfFloatRect *setting_rect;
    sfFloatRect *graph_rect;
} word_t;

typedef struct graphic {
    texture_t *texture;
    sprite_t *sprite;
    word_t *word;
} graphic_t;

typedef struct enemy {
    int health;
    int attack;
    sfVector2i *spawn;
    sfTexture *texture;
    struct enemy *next;
} enemy_t;

typedef struct level_identifier {
    char *name;
} level_identifier_t;

typedef struct level {
    char *name;
    char **map;
    sfVector2i *exit;
    enemy_t *enemies;
    int amnt_enemies;
    sfVector2i *spawn;
    sfTexture *texture;
    struct level *next;
} level_t;

typedef struct config {
    char *name;
    char **values;
} config_t;

typedef struct my_music {
    char *name;
    sfMusic *ptr;
} music_t;

typedef struct setting {
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
    int on_off;
    int music_is_running;
    music_t **musics;
    menu_music_t *menu_mus;
    level_t *levels;
    config_t **config;
} setting_t;

level_t *load_levels(void);
level_t *load_level(const char *path);
level_t *get_level(setting_t *settings, const char *name);

char *trim_whitespace(char *src);

char **get_config(const char *name, setting_t *setting);

int my_rpg(void);

setting_t *init_setting(void);

void destroy(setting_t *setting);
void check_quit(setting_t *setting);
void menu_music(setting_t *setting);
void display_levels(level_t *levels);
void display(setting_t *setting, graphic_t *graphic);
void display_menu(setting_t *setting, graphic_t *graphic);
void display_setting(setting_t *setting, graphic_t *graphic);
void event(sfEvent event, setting_t *setting, graphic_t *graphic);
void mouse_menu(sfEvent event, setting_t *setting, graphic_t *graphic);
void mouse_click(sfEvent event, setting_t *setting, graphic_t *graphic);
void map_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void name_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void song_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void enemies_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void tilesheet_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void mouse_click_setting(sfEvent event, setting_t *setting, graphic_t *graphic);

sprite_t *create_sprite(graphic_t *graphic);

texture_t *create_texture(void);

graphic_t *init_graphic(setting_t *setting);

word_t *create_word(setting_t *setting);

config_t **load_configs(void);

sfMusic **load_sounds(setting_t *setting);
sfMusic *get_music(setting_t *setting, const char *name);

#endif
