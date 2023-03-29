##
## EPITECH PROJECT, 2022
## solostumper02-nelly.pereira-alves
## File description:
## Makefile
##

SRC =	my_putchar.c \
		is_num.c \

NAME =	libmy.a

DEST = ../

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) $(DEST)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(DEST)$(NAME)

re: fclean all
