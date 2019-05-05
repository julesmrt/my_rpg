/*
** EPITECH PROJECT, 2018
** innit_setting.c
** File description:
** my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int j = my_strlen(str) - 1;

    if (str == NULL || my_strlen(str) == 0)
        return NULL;
    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j--] = temp;
    }
    return str;
}

char *integer_to_str(int nb)
{
    char *buffer = malloc(sizeof(char) * 10);
    int i = 0;
    for (; nb != 0; i++) {
        int result = nb % 10;
        buffer[i] = (result + '0');
        nb = nb / 10;
    }
    buffer[i] = '\0';
    return my_revstr(buffer);
}