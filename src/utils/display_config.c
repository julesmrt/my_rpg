/*
** EPITECH PROJECT, 2018
** display_config
** File description:
** display_config
*/

#include "my.h"
#include "my_rpg.h"

void display_config(setting_t *setting)
{
    my_printf("Displaying config: \n");
    for (int i = 0; setting->config[i]->name != NULL; i++) {
        my_printf("config: %s\n", setting->config[i]->name);
        for (int j = 0; setting->config[i]->values[j] != NULL; j++) {
            my_printf("%s\n", setting->config[i]->values[j]);
        }
    }
}