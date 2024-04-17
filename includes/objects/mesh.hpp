#ifndef __MESH_HPP__
# define __MESH_HPP__

# include <fstream>
# include <vector>

# include "vertex.hpp"
# include "material.hpp"
# include "texture.hpp"
# include "shader.hpp"

namespace obj
{

class mesh
{
	private:
		unsigned int VAO, VBO, EBO;

		void	setupMesh();

	public:
        std::vector<vertex>			vertices;
        std::vector<unsigned int>	indices;
        std::vector<texture>		textures;
		// material					m_material;

		mesh();
		mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures);
		~mesh();

        void	draw(shader &shader);
};

std::ostream&	operator<<(std::ostream &o, const mesh &rhs);

}

#endif
