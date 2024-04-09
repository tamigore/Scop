#include "../includes/header.hpp"
#include "../includes/classes/game.hpp"

using namespace scop;

int game::init(int ac, char **av)
{
    (void)ac;
    (void)av;

    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(1000, 1000, "SCOP LE PROJET COOL", NULL, NULL);
    if (this->window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 2;
	}
    glfwMakeContextCurrent(this->window);
    return (1);
}

void game::loop()
{
    while (1)
    {
        
    }
}

game::game(int width, int height): width(width), height(height)
{

}

game::~game()
{
	glfwDestroyWindow(this->window);
    
}
