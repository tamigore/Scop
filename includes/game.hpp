#ifndef GAME_HPP
#include "obj_loader/mesh.hpp"
# define GAME_HPP

namespace scop
{

class game
{
	private:
		int width;
		int height;
		bool isRunning;
		GLFWwindow *window;
		unsigned int shaderProgram;
		unsigned int texture;
		unsigned int VBO, VAO, EBO;
		int initBuffers();
		int initShadder();
		obj::mesh Mesh;

	public:
		~game();
		game(/* args */);
		game(int width, int height);

		int		init(int ac, char **av);
		void	loop();
		void 	setMesh(obj::mesh);
		GLFWwindow *getWindow();
};

}

#endif
