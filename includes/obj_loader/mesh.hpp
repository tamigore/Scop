#ifndef __MESH_HPP__
# define __MESH_HPP__

# include <fstream>
# include <vector>

# include "vertex.hpp"
# include "material.hpp"
# include "face.hpp"
# include "../utils.hpp"

namespace obj
{

class mesh
{
	public:
		std::string					m_name;
		std::vector<math::vec3> 	m_vertices;
		std::vector<math::vec3> 	m_normal;
		std::vector<math::vec2> 	m_texture;
		std::vector<face>			m_faces;
		// material					m_material;

		mesh();
		~mesh();

		bool	add_vertex_position(std::string curline);
		bool	add_vertex_texture(std::string curline);
		bool	add_vertex_normal(std::string curline);
		bool	add_face(std::string curline);
		bool	load_obj(const char* path);
};

std::ostream&	operator<<(std::ostream &o, const mesh &rhs);

}

#endif
