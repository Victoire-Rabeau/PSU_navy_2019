##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make file
##

SRC	=	my_putstr.c	\
		my_strcmp.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_put_nbr.c	\
		my_putchar.c

OBJ	=	$(SRC:.c=.o)

NAME	 =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ) *.a ../*.a

fclean: clean
	rm -f $(NAME)

re:	fclean all
