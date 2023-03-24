##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC		=		$(wildcard src/*.c)

OBJ    =		$(SRC:.c=.o)

LIB    =		-L ./lib

NAME    = 		mysh

MY    =			my_proj.h	\
				my.h

INCLUDE    =	-I./include

CFLAGS = 		-g3

all:     $(NAME)

$(NAME):    $(OBJ)
				make -C lib/my
				gcc -o $(NAME) $(OBJ) -g3 $(INCLUDE) $(LIB) -lmy
				@echo "|| compilation done => ${NAME} ||"
				rm -f $(OBJ)
				rm -f lib/my/*.o

clean:
				rm -f $(OBJ)
				rm -f *~

fclean:			clean
				rm -f $(NAME)
				make fclean -C lib/my

re:				fclean all

.PHONY: all clean fclean re
