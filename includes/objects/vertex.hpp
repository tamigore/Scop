#ifndef __VERTEX_HPP__
# define __VERTEX_HPP__

#include "../math/vec3.hpp"
#include "../math/vec2.hpp"

#define MAX_BONE_INFLUENCE 10

namespace obj
{

struct vertex
{
	math::vec3	m_position;
	math::vec3	m_normal;
	math::vec2	m_texture;
	// position
    math::vec3 Position;
    // normal
    math::vec3 Normal;
    // texCoords
    math::vec2 TexCoords;
    // tangent
    math::vec3 Tangent;
    // bitangent
    math::vec3 Bitangent;
	//bone indexes which will influence this vertex
	int m_BoneIDs[MAX_BONE_INFLUENCE];
	//weights from each bone
	float m_Weights[MAX_BONE_INFLUENCE];
};

}

#endif
