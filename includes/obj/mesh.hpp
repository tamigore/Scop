#ifndef __MESH_HPP__
# define __MESH_HPP__

#include <vector>
#include "vertex.hpp"
#include "material.hpp"

namespace obj
{

struct mesh
{
	public:
		// Default Constructor
		mesh() {}
		
		// Variable Set Constructor
		mesh(std::vector<vertex>& _Vertices, std::vector<unsigned int>& _Indices)
		{
			Vertices = _Vertices;
			Indices = _Indices;
		}
		// Mesh Name
		std::string MeshName;
		// Vertex List
		std::vector<vertex> Vertices;
		// Index List
		std::vector<unsigned int> Indices;

		// Material
		material MeshMaterial;
};

}

#endif
