/*
** EPITECH PROJECT, 2018
** add_tilesheet_to_level
** File description:
** add_tilesheet_to_level
*/

#include "my.h"
#include "my_rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

static const char *src_path = "assets/tilesheet/";

void tilesheet_to_lvl(setting_t *setting, char *id, level_t *level, FILE *file)
{
    sfTexture *texture = NULL;
    char *filename = my_trim(my_strdup(my_strtok(NULL, ":") + 1), "\n");
    char *path = my_empty_char(my_strlen(src_path) + my_strlen(filename) + 1);

    path = my_strcat(path, src_path);
    path = my_strcat(path, filename);
    texture = sfTexture_createFromFile(path, NULL);
    if (texture == NULL)
        level->texture = NULL;
    else
        level->texture = texture;
    free(filename);
    free(path);
}