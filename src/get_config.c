/*
** EPITECH PROJECT, 2018
** get_config
** File description:
** get_config
*/

#include "my_rpg.h"
#include "my.h"

config_t *get_config(const char *name, setting_t *setting)
{
    for (int i = 0; setting->config[i]->name != NULL; i++) {
        if (my_strcmp(setting->config[i]->name, name) == 0)
            return setting->config[i];
    }
    return NULL;
}