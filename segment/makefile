NAME =	segment

SRC =	main.c			\
		error.c			\
		init.c			\
		engine.c		\
		animation.c		\
		params.c		\
		set_buffer.c	\
		draw_buffer.c	\

OBJ =	$(SRC:.c=.o)

FLAGS =	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SRC)
		gcc $(OBJ) -o $(NAME) -lwiringPi -lpthread -lm

noflag: 
		gcc -c -Wall -Wextra $(SRC)
		gcc $(OBJ) -o $(NAME) -lwiringPi -lpthread -lm

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

renoflag: fclean noflag
