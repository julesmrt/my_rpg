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

typedef enum my_screen {
    FIGHT_SCREEN = 7,
    PLAY_SCREEN = 6,
    CHOOSE_SCREEN = 5,
    MENU_SCREEN = 4,
    HOW_TO_PLAY_SCREEN = 3,
    OPT_SCREEN = 2,
    OPT_GRAPH_SCREEN = 1,
    OPT_SOUND_SCREEN = 0,
    TEST_LVL = 50,
} my_screen_t;

typedef enum menu {
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

typedef struct sprite {
    sfSprite *sprite_background;
    sfSprite *sprite_char_man;
    sfSprite *sprite_char_skeleton;
} sprite_t;

typedef struct texture {
    sfTexture *background;
    sfTexture *char_man;
    sfTexture *char_skeleton;
    sfText *who;
    sfFloatRect *char_rect;
} texture_t;

typedef struct my_texture {
    sfTexture *ptr;
    char *name;
} my_texture_t;

typedef struct word {
    sfFont *font;
    sfText ***text;
    float text_x;
    float text_y;
    sfFloatRect **glob_rect;
} word_t;

typedef struct graphic {
    texture_t *texture;
    sprite_t *sprite;
    word_t *word;
} graphic_t;

typedef struct enemy {
    unsigned int health;
    unsigned int attack;
    sfVector2i *spawn;
    sfTexture *texture;
    struct enemy *next;
} enemy_t;

typedef struct hero {
    int type;
    unsigned int health;
    unsigned int attack;
    unsigned int mana;
    sfVector2i *spawn;
    sfTexture *texture;
} hero_t;

typedef struct fight {
    enemy_t *ennemy;
    hero_t *hero;
    sfText **hud;
} fight_t;

typedef struct level_identifier {
    char *name;
} level_identifier_t;

typedef struct tile {
    sfTexture *texture;
    sfVertexArray **array;
    sfRenderStates state;
    unsigned int width;
    int layers;
    int *tab;
    int **t_arr;
    int *entities;
    unsigned int height;
    sfVector2u size;
} tiles_t;

typedef struct level {
    char **csv;
    char *name;
    char **map;
    tiles_t *tile;
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

typedef struct music {
    char *name;
    sfMusic *ptr;
} music_t;

typedef struct setting {
    sfRenderWindow *renderWindow;
    int scrwidth;
    int scrheight;
    sfEvent events;
    int option;
    int screen;
    int setting;
    graphic_t *graphic;
    sfVector2i mouse_pos;
    int on_off;
    int music_is_running;
    music_t **musics;
    menu_music_t *menu_mus;
    menu_t *menu;
    opt_t *opt;
    graphic_menu_t *graphic_menu;
    audio_menu_t *audio_menu;
    my_screen_t *my_screen;
    sfBool vertical;
    float fps;
    sfBool music;
    level_t *curr_lvl;
    level_t *levels;
    my_texture_t **textures;
    config_t **config;
    int type_hero;
} setting_t;

level_t *load_levels(void);
level_t *load_level(const char *path);
level_t *get_level(setting_t *settings, const char *name);

char *trim_whitespace(char *src);

int my_rpg(void);

setting_t *init_setting(void);


void destroy(setting_t *setting);
void check_quit(setting_t *setting);
void menu_music(setting_t *setting);
void display_levels(level_t *levels);
void display_config(setting_t *setting);
void display(setting_t *setting, graphic_t *graphic, fight_t *fight);
void check_opt(setting_t *setting, graphic_t *graphic);
void display_level(level_t *level, setting_t *setting);
void check_graph(setting_t *setting, graphic_t *graphic);
void check_sound(setting_t *setting, graphic_t *graphic);
void check_setting(setting_t *setting, graphic_t *graphic);
void display_setting(setting_t *setting, graphic_t *graphic);
void event(sfEvent event, setting_t *setting, graphic_t *graphic);
void csv_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void mouse_moved(sfEvent event, setting_t *setting, graphic_t *graphic);
void mouse_click(sfEvent event, setting_t *setting, graphic_t *graphic);
void map_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void name_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void tile_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void song_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void enemies_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void tilesheet_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void mouse_click_setting(sfEvent event, setting_t *setting, graphic_t *graphic);

tiles_t *create_tile(char **csv, sfTexture *texture);

sprite_t *create_sprite(graphic_t *graphic);

texture_t *create_texture(void);

graphic_t *init_graphic(setting_t *setting);

word_t *create_word(setting_t *setting);

void display_menu(setting_t *setting, graphic_t *graphic, int j);
void display_setting(setting_t *setting, graphic_t *graphic);
void mouse_click_setting(sfEvent event, setting_t *setting, graphic_t *graphic);
void display_charracters(setting_t *setting, graphic_t *graphic);
void display_graph(setting_t *setting, graphic_t *graphic);

config_t **load_configs(void);

sfMusic **load_sounds(setting_t *setting);
sfMusic *get_music(setting_t *setting, const char *name);

fight_t *init_fight(setting_t *setting, graphic_t *graphic);
void display_fight(setting_t *setting, graphic_t *graphic, fight_t *fight);

config_t *get_config(const char *name, setting_t *setting);

music_t **load_songs(config_t *songs_config);

sfMusic *get_song(const char *name, setting_t *setting);

my_texture_t **load_textures(config_t *songs_config);

char *integer_to_str(int nb);

#endif
