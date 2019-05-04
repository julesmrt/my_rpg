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

static my_texture_t *load_single_texture(const char *line)
{
    char *cpy = my_strdup(line);
    char *id = my_strtok(cpy, ": ");
    char *file = my_strtok(NULL, ": ");
    char *complete_path = my_empty_char(my_strlen(file) + my_strlen(path) + 1);
    my_texture_t *res = malloc(sizeof(my_texture_t));

    if (res == NULL) {
        free(cpy);
        free(id);
        return NULL;
    }
    complete_path = my_strcat(complete_path, path);
    complete_path = my_strcat(complete_path, file);
    res->name = my_strdup(id);
    res->ptr = sfTexture_createFromFile(complete_path, NULL);
    return res;
}

my_texture_t **load_textures(config_t *songs_config)
{
    int size = 0;
    size_t ptr_size;
    my_texture_t *temp = NULL;
    my_texture_t **res = NULL;
    char *temp_path = NULL;

    for (int i = 0; songs_config->values[i] != NULL; i++) {
        temp = load_single_texture(songs_config->values[i]);
        if (temp == NULL)
            continue;
        ptr_size = sizeof(*res) * size;
        res = my_realloc(res, ptr_size, ptr_size * (size + 2));
        res[size++] = temp;
    }
    if (res != NULL)
        res[size] = NULL;
    free(temp);
    free(temp_path);
    return res;
}