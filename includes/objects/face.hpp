#ifndef __FACE_HPP__
# define __FACE_HPP__

#include <vector>

namespace obj
{

struct face
{
	std::vector<unsigned int>	m_vertice_index;
	std::vector<unsigned int>	m_normal_index;
	std::vector<unsigned int>	m_texture_index;
};

}

#endif