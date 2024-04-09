NAME = scop
CC = g++ -Wall -Werror -Wextra
CFLAGS =  -std=c++11
OPENGL = -lglut -lGLU -lGL -lglfw  

SRCS =	main.cpp	\
		glad.c
		

CLASS =



srcs = $(addprefix srcs/, $(SRCS)) \
			$(addprefix srcs/classes/, $(CLASS))

all: COMP

COMP: $(srcs)
	$(CC) $(CFLAGS) $(srcs) $(OPENGL) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf srcs/classes/*.o
	rm -rf srcs/*.o


re: fclean all

.PHONY: all clean fclean re