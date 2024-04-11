#include "../includes/header.hpp"
#include "../includes/game.hpp"

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

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
		std::cout << "GLFW_KEY_ESCAPE" << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}

void game::loop()
{
	while (!glfwWindowShouldClose(this->window))
	{
		glfwPollEvents();
		processInput(this->window);
	}
}

game::game(int width, int height): width(width), height(height)
{

}

game::~game()
{
	glfwDestroyWindow(this->window);
    
}
