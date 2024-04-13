#ifndef __SHADER_HPP__
# define __SHADER_HPP__

# include "../glad/glad.h"

# include <string>
# include <fstream>
# include <sstream>
# include <iostream>

namespace obj
{

class shader
{
	private:
		void	checkCompileErrors(unsigned int shader, std::string type);

	public:
		// the program ID
		unsigned int	ID;
	
		shader(const char* vertexPath, const char* fragmentPath);

		void	use();
		void	setBool(const std::string &name, bool value) const;
		void	setInt(const std::string &name, int value) const;
		void	setFloat(const std::string &name, float value) const;
};

}

#endif
