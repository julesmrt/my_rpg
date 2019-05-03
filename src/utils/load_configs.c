/*
** EPITECH PROJECT, 2018
** load_configs
** File description:
** load_configs
*/

#include "my.h"
#include "my_rpg.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

static const char *path = "assets/config/";
static const char *extension = ".config";

static char **load_value(FILE *file)
{
    ssize_t gtl;
    int size = 0;
    size_t x = 0;
    char *buf = NULL;
    ssize_t ptr_size;
    char **res = NULL;

    while ((gtl = getline(&buf, &x, file)) == -1) {
        ptr_size = sizeof(*res) * size;
        res = my_realloc(res, ptr_size, ptr_size * (size + 2));
        res[size++] = my_trim(buf, "\n");
    }
    if (res != NULL)
        res[size] = NULL;
    free(buf);
    return res;
}

static int valid_filename(const char *filename)
{
    size_t len = my_strlen(extension);
    size_t x = my_strlen(filename) - len;

    if (x <= 0)
        return 0;
    return my_strcmp(filename + x, extension) == 0;
}

static FILE *get_file(struct dirent *file)
{
    FILE *temp = NULL;
    char *pa = my_empty_char(my_strlen(path) + my_strlen(file->d_name) + 1);

    temp = fopen(pa, "r");
    if (temp == NULL || valid_filename(file->d_name)) {
        free(pa);
        return NULL;
    }
    free(pa);
    return temp;
}

config_t **load_configs(void)
{
    int size = 0;
    size_t ptr_size;
    FILE *temp_file = NULL;
    DIR *dir = opendir(path);
    config_t **config = NULL;
    config_t *temp_conf = NULL;
    struct dirent *file_dir = NULL;

    if (dir == NULL)
        return NULL;
    while ((file_dir = readdir(dir)) != NULL) {
        ptr_size = sizeof(*config) * size;
        config = my_realloc(config, ptr_size, ptr_size * (size + 2));
        temp_file = get_file(file_dir);
        if (temp_file == NULL)
            continue;
        temp_conf = malloc(sizeof(config_t));
        temp_conf->values = load_value(temp_file);
        temp_conf->name = my_strdup(my_strtok(file_dir->d_name, "."));
        config[size++] = temp_conf;
        fclose(temp_file);
        config[size] = NULL;
    }
    closedir(dir);
    return config;
}