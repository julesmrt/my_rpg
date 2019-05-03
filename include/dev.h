/*
** EPITECH PROJECT, 2018
** dev.h
** File description:
** dev function
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#ifndef dev_H_
#define dev_H_

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

level_t *load_levels(void);
level_t *load_level(const char *path);

char *trim_whitespace(char *src);

void display_levels(level_t *levels);
void map_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void name_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void song_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void enemies_to_lvl(const char *line, char *id, level_t *level, FILE *file);
void tilesheet_to_lvl(const char *line, char *id, level_t *level, FILE *file);

#endif