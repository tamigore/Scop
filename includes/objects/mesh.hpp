#ifndef __MESH_HPP__
# define __MESH_HPP__

# include <fstream>
# include <map>
# include <vector>

# include "vertex.hpp"
# include "face.hpp"
# include "texture.hpp"
# include "shader.hpp"
# include "../utils.hpp"

#include "../glad/glad.h"
#include <GLFW/glfw3.h>

namespace obj
{

class mesh
{
	private:

		void	setupMesh();
		bool	add_vertex_position(std::string curline);
		bool	add_vertex_texture(std::string curline);
		bool	add_vertex_normal(std::string curline);
		bool	add_face(std::string pram);

		unsigned int	TextureFromFile(const char *path, const std::string &directory);

	public:
		unsigned int VAO, VBO, EBO;

		std::string					m_name;
        std::vector<vertex>			m_vertices;
        std::vector<unsigned int>	m_indices;
        std::vector<unsigned int>	m_position_indices;
        std::vector<unsigned int>	m_normal_indices;
        std::vector<unsigned int>	m_texture_indices;
        std::vector<texture>		m_textures;
        std::vector<face>			m_faces;

		mesh();
		mesh(char* path);
		~mesh();

        void	draw(shader &shader);
		bool	loadMesh(const char *path);
		bool	add_texture(const char *name, const char *path);
		void	min_max_bounds(math::vec3& min_bound, math::vec3& max_bound);
		void	center_around_orgin();
		void	facesDuplicateVertexes();
};	

std::ostream&	operator<<(std::ostream &o, const mesh &rhs);

}

#endif
