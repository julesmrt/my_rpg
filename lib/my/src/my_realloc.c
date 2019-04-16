/*
** EPITECH PROJECT, 2018
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my.h"
#include <stdlib.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new;

    if (ptr == NULL) {
        new = malloc(new_size);
        if (new == NULL)
            return NULL;
        return new;
    } else {
        new = malloc(new_size);
        if (new == NULL)
            return NULL;
        my_memcpy(new, ptr, old_size);
        free(ptr);
    }
    return new;
}