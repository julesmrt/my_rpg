/*
** EPITECH PROJECT, 2018
** load_levels
** File description:
** load_levels
*/

#include "my.h"
#include "dev.h"
#include "my_rpg.h"
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

static const char *dir = "assets/levels";
static const char *extension = ".lvl";

static void add_to_level_list(level_t **head, level_t *new)
{
    level_t *last = *head;

    if (*head == NULL) {
        *head = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}

static const int valid_filename(const char *filename)
{
    size_t len = my_strlen(extension);
    size_t x = my_strlen(filename) - len;

    if (x <= 0)
        return 0;
    return my_strcmp(filename + x, extension) == 0;
}

static char *get_path(const char *filename)
{
    char *res = NULL;

    if (!valid_filename(filename))
        return NULL;
    res = my_empty_char(my_strlen(dir) + my_strlen(filename) + 2);
    if (res == NULL)
        return NULL;
    res = my_strcat(res, dir);
    res = my_strcat(res, "/");
    res = my_strcat(res, filename);
    return res;
}

level_t *load_levels(void)
{
    char *path = NULL;
    DIR *folder = NULL;
    level_t *temp = NULL;
    level_t *list = NULL;
    struct dirent *file = NULL;

    folder = opendir(dir);
    if (folder == NULL) {
        my_puterror("Could not open dir\n");
        return NULL;
    }
    while ((file = readdir(folder)) != NULL) {
        path = get_path(file->d_name);
        if (path == NULL) {
            continue;
        }
        temp = load_level(path);
        if (temp == NULL)
            continue;
        add_to_level_list(&list, temp);
    }
    if (file != NULL)
        free(file);
    closedir(folder);
    return list;
}