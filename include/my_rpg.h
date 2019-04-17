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

typedef struct sprite
{
    sfSprite *sprite_background;
    sfSprite *sprite_rules;

} sprite_t;

typedef struct texture
{
    sfTexture *background;
    sfTexture *rules;

} texture_t;

typedef struct graphic
{
    texture_t *texture;
    sprite_t *sprite;

} graphic_t;

int my_rpg(void);

//init_setting.c
setting_t *init_setting(void);

//event.c
void event(sfEvent event, setting_t *setting);

//destroy.c
void check_quit(setting_t *setting);
void destroy(setting_t *setting);

//sprite.c
sprite_t *create_sprite(graphic_t *graphic);

//texture.c
texture_t *create_texture(void);

//graphic.c
graphic_t *init_graphic(setting_t *setting);

//diplay.c
void display(setting_t *setting, graphic_t *graphic);

#endif
