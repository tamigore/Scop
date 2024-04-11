#include "../includes/header.hpp"
//g++ openGL.cpp -lglut -lGLU -lGL; ./a.out
#include "../includes/stb_image.h"
#include "../includes/obj_loader/mesh.hpp"

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
	
	obj::mesh mesh;
	mesh.load_obj(av[1]);
	std::cout << "Mesh loaded" << std::endl;
	std::cout << mesh << std::endl;
	scop::game game(1000, 1000);
    game.init(ac, av);
	game.loop();
	return 0;
}