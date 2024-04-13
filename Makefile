NAME = scop
CC = g++ -Wall -Werror -Wextra
CFLAGS =  -std=c++17
OPENGL = -lglut -lGLU -lGL -lglfw -lX11

CPPSRCS =	main.cpp
CSRCS =	glad.c

# game.cpp	\
utils.cpp

MATH =	mat4.cpp	\
		vec3.cpp	\
		vec2.cpp

OBJECTS =	shader.cpp

csrcs =	$(addprefix srcs/, $(CSRCS))

cppsrcs =	$(addprefix srcs/, $(CPPSRCS))			\
			$(addprefix srcs/math/, $(MATH))	\
			$(addprefix srcs/objects/, $(OBJECTS))


srcs = $(csrcs)
srcs += $(cppsrcs)

objs =	$(csrcs:.c=.o)
objs += $(cppsrcs:.cpp=.o)

all: comp_obj

comp_obj: $(srcs)
	$(CC) $(CFLAGS) $(srcs) $(OPENGL) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -f $(objs)

re: fclean all

.PHONY: all clean fclean re