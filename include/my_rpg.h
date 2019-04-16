/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>

#ifndef my_rpg_HEADER_H_
#define my_rpg_HEADER_H_
#define WINDOW  (setting->renderWindow)

typedef struct setting
{
    sfRenderWindow *renderWindow;
    int scrwidth;
    int scrheight;
    sfEvent events;
    
} setting_t;

int my_rpg(void);

//init_setting.c
setting_t *init_setting(void);

//event.c
void event(sfEvent event, setting_t *setting);

#endif
