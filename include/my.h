/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#include "my_printf.h"
#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE 10
#endif

#ifndef LIBMY_MY_H_
#define LIBMY_MY_H_

size_t my_strlen(const char *str);
size_t my_puterror(const char *str);

ssize_t my_getline(char **lineptr, size_t *n, int fd);

int my_ctoi(char c);
int is_digit(char c);
int my_putnbr(int nb);
int my_putchar(char c);
int my_is_alpha(char c);
int count_words(char *src);
int my_is_alphanum(char c);
int nb_amount_digits(int nb);
int my_putstr(const char *str);
int str_is_int(const char *str);
int my_printf(const char *str, ...);
int char_in_str(const char *src, char c);
int my_strcmp(const char *s1, const char *s2);
int my_strcspn(const char *s1, const char *s2);
int my_str_to_word_array(char *src, char ***dest);
int has_paramater(int ac, char **av, char *param);
int my_strspn(const char *src, const char *accept);
int my_str_str(const char *src, const char *token);
int my_strncmp(const char *s1, const char *s2, int n);

long my_strtoi(const char *str);
long my_strtol(const char *src, int base);

void my_rev_str(char *str);
void *my_memset(void *s, int c, size_t n);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);

char *my_empty_char(size_t n);
char *my_strdup(const char *src);
char *my_strncpy(const char *src, int n);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
char *my_strtok(char *str, const char *delim);
char *my_strchr(const char *str, unsigned char c);
char *my_strpbrk(const char *str, const char *accept);
char *my_getopt(int ac, char **av, const char *param);
char *my_trim(const char *str, const char *to_remove);
char *my_strtok_r(char *str, const char *delim, char **ptr);
char *str_replace(const char *src, const char *to_replace, char *new_value);

#endif //LIBMY_MY_H_
