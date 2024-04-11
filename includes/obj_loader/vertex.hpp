#ifndef __VERTEX_HPP__
# define __VERTEX_HPP__

#include "../math/vec3.hpp"
#include "../math/vec2.hpp"
#include "../glad/glad.h"

namespace obj
{

struct vertex
{
	math::vec3	m_position;
	math::vec3	m_normal;
	math::vec2	m_textureCoordinate;

	GLint	m_position_index;
	GLint	m_normal_index;
	GLint	m_textureCoordinate_index;
};

}

#endif
