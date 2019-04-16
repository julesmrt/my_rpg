##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for pushswap lib
##

CC = gcc

CFLAGS += -W -Wall -pedantic -Iinclude

NAME = ../libmy.a

SRC = $(wildcard src/*.c) $(wildcard src/**/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

lib:
	$(MAKE) -C lib/my

$(NAME): $(OBJ)
	$(AR) rcs $@ $^
	cp include/*.h ../../include/

clean:
	$(RM) *.o src/**/*.o src/*.o ../../include/my.h ../../include/my_printf.h

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re