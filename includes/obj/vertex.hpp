#ifndef __VERTEX_HPP__
# define __VERTEX_HPP__

#include "../math/vec3.hpp"
#include "../math/vec2.hpp"

namespace obj
{

struct vertex
{
    // Position Vector
    math::vec3 Position;

    // Normal Vector
    math::vec3 Normal;

    // Texture Coordinate Vector
    math::vec2 TextureCoordinate;
};

}

#endif
