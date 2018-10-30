

LIB_DIR = -L libsoundio/build -L kissfft -L libsoundio/soundio
LIB_NAME = -lsoundio -lkissfft -lm
LIB_HEADER = -I libsoundio -I kissfft -I libsoundio/src
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = sio_record.c	\
	core_function.c

NAME = fft_test


OBJ	= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS)  -o $(NAME) $(OBJ) $(LIB_HEADER)  $(LIB_DIR) $(LIB_NAME) $(FRAMEWORK)


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< $(LIB_HEADER)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

libs:
	@make -C kissfft
	@mkdir -p libsoundio/build
	@cd libsoundio/build && cmake ../ && make && sudo make install
	@sudo cp kissfft/libkissfft.so kissfft/libkissfft.a /usr/local/lib 
	


	
test_export: 
	

#fft_test:
#	rm -f $(NAME_TEST)
#	$(CC) $(FLAGS) $(SRC_TEST)  $(LIB_HEADER) $(LIB_DIR) $(LIB_NAME)   -o $(NAME_TEST)



