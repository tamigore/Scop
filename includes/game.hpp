#ifndef GAME_HPP
# define GAME_HPP

namespace scop
{

class game
{
	private:
		int				width;
		int				height;
		bool			isRunning;
		unsigned int	shaderProgram;
		unsigned int	texture;

	public:
		GLFWwindow *window;
		~game();
		game(/* args */);
		game(int width, int height);

		int		init(int ac, char **av);
		void	loop();
};

}

#endif
