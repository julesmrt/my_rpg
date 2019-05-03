/*
** EPITECH PROJECT, 2018
** load_sounds
** File description:
** load_sounds
*/

#include "my.h"
#include "my_rpg.h"
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>

static const char *song_src = "assets/songs/";

sfMusic **load_sounds(setting_t *settings)
{
    int size = 0;
    size_t ptr_size;
    char *temp = NULL;
    char **config = get_config("songs", settings);
    sfMusic **res = NULL;

    for (int i = 0; config[i] != NULL; i++) {
        temp = my_empty_char(my_strlen(song_src) + my_strlen(config[i]) + 1);
        temp = my_strcat(temp, song_src);
        temp = my_strcat(temp, config[i]);
        ptr_size = sizeof(*res) * size;
        res = my_realloc(res, ptr_size, ptr_size * (size + 2));
        res[size++] = sfMusic_createFromFile(temp);
        res[size] = NULL;
    }
    if (res != NULL)
        res[size] = NULL;
    return res;
}