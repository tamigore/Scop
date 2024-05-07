#ifndef __VERTEX_HPP__
# define __VERTEX_HPP__

#include "../math/vec3.hpp"
#include "../math/vec2.hpp"

// #define MAX_BONE_INFLUENCE 10

namespace obj
{

struct vertex
{
	math::vec3 m_position;
	math::vec3 m_normal;
	math::vec2 m_texture;
	math::vec3 m_color;
};

}

#endif
