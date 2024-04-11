NAME = scop
CC = g++ -Wall -Werror -Wextra
CFLAGS =  -std=c++11
OPENGL = -lglut -lGLU -lGL -lglfw  

SRCS =	main.cpp	\
		game.cpp	\
		utils.cpp

MATH =	mat4.cpp	\
		vec3.cpp	\
		vec2.cpp

MODEL =	mesh.cpp

srcs =	$(addprefix srcs/, $(SRCS))			\
		$(addprefix srcs/math/, $(MATH))	\
		$(addprefix srcs/model/, $(MODEL))

obj =	$(srcs:.cpp=.o)

all: comp_obj

comp_obj: $(srcs)
	$(CC) $(CFLAGS) $(srcs) $(OPENGL) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -f $(obj)

re: fclean all

.PHONY: all clean fclean re