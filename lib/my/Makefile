##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC    =        my_put_nbr_long.c       \
                my_putchar.c            \
                my_putstr.c             \
                my_revstr.c             \
                my_strcmp.c             \
                my_strlen.c             \
                my_strcpy.c             \
                my_strcat_mal.c         \
                my_str_to_word_array.c  \
                my_isalphanum.c         \
                my_strrchr.c            \
                my_strncmp.c            \
                my_strdup.c

OBJ  = $(SRC:.c=.o)

NAME = libmy.a

MY = my.h

DIRECTORY = ../../include

all: $(NAME)

$(NAME):        $(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:		fclean all
