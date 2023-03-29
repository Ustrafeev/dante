##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles my lib
##

SRC		= $(shell find . -name "*.c")

OBJ		=	$(SRC:.c=.o)

OUT	=	solver

LIB = libmy.a

CFLAGS = -Wall -Wextra \
			-Wno-unused-value

.PHONY: all clean fclean re build

all: $(LIB)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ)
	gcc -o $(OUT) $(SRC) -L. -lmy

clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean:		clean
	rm -f $(LIB)
	rm -f $(OUT)
	rm -f unit_tests

re:		fclean all

build: re
	gcc -o $(OUT) $(SRC) -L. -lmy
