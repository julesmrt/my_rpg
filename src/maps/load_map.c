/*
** EPITECH PROJECT, 2018
** load_map
** File description:
** load_map
*/

#include "my.h"
#include "my_rpg.h"
#include <stdlib.h>
#define WIDTH (tile->width)
#define HEIGHT (tile->height)
#define SI (tile->size)
#define TEXTURET (tile->texture)
#define POST (position)
#define LAYERS (tile->layers)

static void tiles_info(tiles_t *tile, sfVertexArray *ar, const int *tab)
{
    for (unsigned int i = 0; i < WIDTH; i++) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
            int tilenumber = tab[i + j * WIDTH];
            int tu = tilenumber % (sfTexture_getSize(TEXTURET).x / SI.x);
            int tv = tilenumber / (sfTexture_getSize(TEXTURET).x / SI.x);

            if (tilenumber == -1)
                continue;
            sfVertex *quad = sfVertexArray_getVertex(ar, (i + j * WIDTH) * 4);
            quad[0].position = (sfVector2f) {i * SI.x, j * SI.y};
            quad[1].position = (sfVector2f) {(i + 1) * SI.x, j * SI.y};
            quad[2].position = (sfVector2f) {(i + 1) * SI.x, (j + 1) * SI.y};
            quad[3].position = (sfVector2f) {i * SI.x, (j + 1) * SI.y};

            quad[0].texCoords = (sfVector2f) {tu * SI.x, tv * SI.y};
            quad[1].texCoords = (sfVector2f) {(tu + 1) * SI.x, tv * SI.y};
            quad[2].texCoords = (sfVector2f) {(tu + 1) * SI.x, (tv + 1) * SI.y};
            quad[3].texCoords = (sfVector2f) {tu * SI.x, (tv + 1) * SI.y};
        }
    }
}

static int *parsing(int width, int height, char *path)
{
    int *tab = malloc(width * height * (sizeof(int)));
    char *buffer = NULL;
    size_t n = 0;
    FILE *fp = fopen(path, "r");
    int i = 0;

    while (getline(&buffer, &n, fp) > -1) {
        char *token = my_strtok(buffer, ",");
        while (token != NULL) {
            tab[i] = my_strtoi(token);
            token = my_strtok(NULL, ",");
            i++;
        }
    }
    fclose(fp);
    return tab;
}

static void vertex(tiles_t *tile)
{
    tile->array = malloc(sizeof(sfVertexArray *) * LAYERS);

    for (int i = 0; i < LAYERS; i++) {
        tile->array[i] = sfVertexArray_create();
        sfVertexArray_setPrimitiveType(tile->array[i], sfQuads);
        sfVertexArray_resize(tile->array[i], WIDTH * HEIGHT * 4);
        tiles_info(tile, tile->array[i], tile->t_arr[i]);
    }
}

static int **int_array(tiles_t *tile,char **csv)
{
    int **tab = malloc(sizeof(int *) * LAYERS);

    for (int i = 0; csv[i] != NULL; i++) {
        tab[i] = parsing(WIDTH, HEIGHT, csv[i]);
    }
    return tab;
}

static int amnt_layers(char **csv)
{
    int i = 0;

    while (csv[i] != NULL) {
        i++;
    }
    return i;
}

tiles_t *create_tile(char **csv)
{
    tiles_t *tile = malloc(sizeof(tiles_t));

    TEXTURET = sfTexture_createFromFile("lvl2.png", NULL);
    tile->layers = amnt_layers(csv);
    SI.x = 32;
    SI.y = 32;
    WIDTH = 40;
    HEIGHT = 30;
    tile->t_arr = int_array(tile, csv);
    vertex(tile);
    tile->state.blendMode = sfBlendAlpha;
    tile->state.shader = NULL;
    tile->state.transform = sfTransform_Identity;
    tile->state.texture = TEXTURET;

    return tile;
}