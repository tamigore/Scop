NAME = mathlib.so
CC = g++ -Wall -Werror -Wextra
CFLAGS =  -std=c++17

SRCS =	math.cpp	\
		mat4.cpp	\
		mat3.cpp	\
		mat2.cpp	\
		vec4.cpp	\
		vec3.cpp	\
		vec2.cpp	\
		vec1.cpp

srcs =	$(addprefix srcs/, $(SRCS))

objs =	$(srcs:.c=.o)

all: comp_obj

comp_obj: $(srcs)
	$(CC) $(CFLAGS) $(srcs) $(OPENGL) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -f $(objs)

re: fclean all

.PHONY: all clean fclean re