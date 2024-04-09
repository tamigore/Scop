#ifndef GAME_HPP
# define GAME_HPP

# include "../base_header.hpp"
// # include "vec3.hpp"
// # include "mat4.hpp"
// # include "mesh.hpp"
# include "../types.hpp"



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




public:
	~game();
	game(/* args */);
	game(int width, int height);

	int 			init(int ac, char **av);
	void 			loop();
};
}






#endif