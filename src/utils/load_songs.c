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

static music_t *load_single_song(const char *line)
{
    char *cpy = my_strdup(line);
    char *id = my_strtok(cpy, ": ");
    char *file = my_strtok(NULL, ": ");
    char *complete_path = my_empty_char(my_strlen(file) + my_strlen(path) + 1);
    music_t *res = malloc(sizeof(music_t));

    if (res == NULL) {
        free(cpy);
        free(id);
        return NULL;
    }
    complete_path = my_strcat(complete_path, path);
    complete_path = my_strcat(complete_path, file);
    res->name = my_strdup(id);
    res->ptr = sfMusic_createFromFile(complete_path);
    return res;
}

music_t **load_songs(config_t *songs_config)
{
    int size = 0;
    size_t ptr_size;
    music_t *temp = NULL;
    music_t **res = NULL;

    for (int i = 0; songs_config->values[i] != NULL; i++) {
        temp = load_single_song(songs_config->values[i]);
        if (temp == NULL)
            continue;
        ptr_size = sizeof(*res) * size;
        res = my_realloc(res, ptr_size, ptr_size * (size + 2));
        res[size++] = temp;
    }
    if (res != NULL) {
        res[size] = malloc(sizeof(music_t));
        res[size]->name = NULL;
        res[size]->ptr = NULL;
    }
    return res;
}