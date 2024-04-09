#ifndef GAME_HPP
# define GAME_HPP

# include "../header.hpp"
# include "../struct.hpp"

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

		int		init(int ac, char **av);
		void	loop();
};

}

#endif
