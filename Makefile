##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for my_rpg
##

CC = gcc

CFLAGS += -W -Wall -Wunusedparamater -pedantic -Iinclude/ -Llib -g

LDFLAGS += -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME = my_rpg

SRC = $(wildcard src/*.c) $(wildcard src/**/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

lib:
	$(MAKE) -C lib/my

$(NAME): lib $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) -C lib/my clean
	$(RM) *.o src/**/*.o src/*.o src/**/**/*.gc* src/*.gc*

fclean: clean
	$(MAKE) -C lib/my fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: lib fclean clean re