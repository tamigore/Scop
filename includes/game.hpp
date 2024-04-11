#ifndef GAME_HPP
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

	public:
		GLFWwindow *window;
		~game();
		game(/* args */);
		game(int width, int height);

		int		init(int ac, char **av);
		void	loop();
		GLFWwindow *getWindow();
};

}

#endif
