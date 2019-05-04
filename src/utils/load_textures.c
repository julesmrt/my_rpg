/*
** EPITECH PROJECT, 2018
** load_textures
** File description:
** load_textures
*/

#include "my.h"
#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static const char *path = "assets/tilesheet/";

my_texture_t **load_textures(config_t *songs_config)
{
    int size = 0;
    size_t ptr_size;
    char *temp = NULL;
    my_texture_t **res = NULL;
    char *temp_path = NULL;

    for (int i = 0; songs_config->values[i] != NULL; i++) {
        ptr_size = sizeof(*res) * size;
        res = my_realloc(res, ptr_size, ptr_size * (size + 2));
        temp = my_strdup(songs_config->values[i]);
        res[size] = malloc(sizeof(my_texture_t));
        temp_path = my_empty_char(my_strlen(path) + my_strlen(temp));
        temp_path = my_strcat(temp_path, path);
        temp_path = my_strcat(temp_path, temp);
        res[size++]->ptr = sfTexture_createFromFile(temp_path, NULL);
    }
    if (res != NULL)
        res[size] = NULL;
    free(temp);
    free(temp_path);
    return res;
}