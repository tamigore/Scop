#include "../includes/header.hpp"
//g++ openGL.cpp -lglut -lGLU -lGL; ./a.out
#include "../includes/stb_image.h"

int zoom = 0;

double fps = 0.0;
bool color = true;

bool rotate_p = false;
bool color_p = false;

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "No argument" << std::endl;
		return 1;
	}
    scop::game games(1000, 1000);
    games.init(ac, av);
    games.loop();
	return 0;
}