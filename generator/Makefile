##
## EPITECH PROJECT, 2022
## BSQ
## File description:
## Makefile
##

SRC =	src/error_management.c \
		src/recursive.c \
		src/display.c \
		main_generator.c \

OBJ = $(SRC:.c=.o)

NAME = generator

LIB = -L./lib -lmy

$(NAME): $(OBJ)
	make -C./lib/my
	gcc -o $(NAME) $(OBJ) $(LIB) -Wall

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C./lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C./lib/my

debug:
	make -C./lib/my
	gcc -o $(NAME) $(SRC) $(LIB) -g3

re: fclean all
