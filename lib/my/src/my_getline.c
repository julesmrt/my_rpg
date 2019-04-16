/*
** EPITECH PROJECT, 2018
** my_getline.c
** File description:
** my_getline.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static char *trim_new_line(const char *str, ssize_t *size_read)
{
    int i = 0;
    char *res = malloc(my_strlen(str) + 1);

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        res[i] = str[i];
        (*size_read)++;
    }
    res[i] = '\0';
    (*size_read)++;
    return res;
}

static char *my_read_line(int fd, char *buffer, ssize_t *amnt_read)
{
    *amnt_read = read(fd, buffer, READ_SIZE);
    buffer[*amnt_read] = '\0';
    return buffer;
}

static void my_getnextline(char **buffer, int fd)
{
    size_t size = 0;
    char temp[READ_SIZE + 1];
    ssize_t amnt_read = 0;

    while (my_strchr(*buffer, '\n') == NULL) {
        size = my_strlen(*buffer);
        *buffer = my_realloc(*buffer, size, size + amnt_read + 1);
        *buffer = my_strcat(*buffer, my_read_line(fd, temp, &amnt_read));
        if (amnt_read <= 0)
            break;
    }
}

ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
    static char *buffer = NULL;
    ssize_t amnt_read_total = 0;

    if (buffer == NULL)
        buffer = my_empty_char(READ_SIZE + 1);
    my_getnextline(&buffer, fd);
    *lineptr = trim_new_line(buffer, &amnt_read_total);
    if (*lineptr[0] == '\0' && buffer[0] == '\0') {
        buffer = NULL;
        *lineptr = NULL;
        return 0;
    }
    buffer = my_strdup(buffer + amnt_read_total);
    return amnt_read_total;
}