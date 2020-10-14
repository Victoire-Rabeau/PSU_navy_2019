##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-I./include

SRC		=	src/main.c				\
			src/player.c			\
			src/init/init_struct.c	\
			src/init/init_map.c		\
			src/display_map.c		\
			src/signal.c			\
			src/connection.c		\
			src/update_map.c		\
			src/loop.c

OBJ		=	$(SRC:.c=.o)

NAME		=	navy

CFLAGS		= 	-Wall -Wextra

MAKE		=	make

all: $(NAME)

lib:
	make -C ./lib

clean:
	$(MAKE) -C ./lib clean
	rm -f $(OBJ) vgcore*
	mr_clean

$(NAME):	lib $(OBJ)
		gcc -o $(NAME) $(OBJ) -lmy -L. $(CPPFLAGS)

vg:	CFLAGS += -g3
vg:	$(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all lib

.PHONY: all clean fclean re lib
