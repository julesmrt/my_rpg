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
        temp = my_strdup(songs_config->values[i]);
        res[size] = malloc(sizeof(music_t));
        res[size]->name = my_strdup(my_strtok(temp, ":") + 1);
        temp_path = my_empty_char(my_strlen(path) + my_strlen(temp));
        temp_path = my_strcat(temp_path, path);
        temp_path = my_strcat(temp_path, temp);
        res[size++]->ptr = sfMusic_createFromFile(temp_path);
    }
    if (res != NULL)
        res[size] = NULL;
    free(temp);
    free(temp_path);
    return res;
}