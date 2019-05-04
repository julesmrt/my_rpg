/*
** EPITECH PROJECT, 2018
** load_songs
** File description:
** load_songs
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>

static const char *path = "assets/musics/";

static char *get_path(const char *line)
{
    char *res = my_empty_char(my_strlen(line) + 1 + my_strlen(path));

    res = my_strcat(res, path);
    res = my_strcat(res, line);
    return res;
}

music_t **load_songs(config_t *songs_config)
{
    int size = 0;
    size_t ptr_size;
    char *temp = NULL;
    music_t **res = NULL;
    char *temp_path = NULL;

    for (int i = 0; songs_config->values[i] != NULL; i++) {
        ptr_size = sizeof(*res) * size;
        res = my_realloc(res, ptr_size, ptr_size * (size + 2));
        res[size] = malloc(sizeof(music_t));
        temp = my_strdup(songs_config->values[i]);
        res[size]->name = my_strdup(my_strtok(temp, ": "));
        temp_path = get_path(my_strtok(NULL, ": "));
        res[size++]->ptr = sfMusic_createFromFile(temp_path);
    }
    if (res != NULL) {
        res[size] = malloc(sizeof(music_t));
        res[size]->name = NULL;
        res[size]->ptr = NULL;
    }
    free(temp_path);
    return res;
}