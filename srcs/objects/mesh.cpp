#include "../../includes/objects/mesh.hpp"
#include "../glad/glad.h"

using namespace obj;

#define OBJL_CONSOLE_OUTPUT

mesh::mesh()
{
}

mesh::~mesh() {}

void mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
  
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);  

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), 
                 &indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, m_normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, m_texture));

    glBindVertexArray(0);
}  

std::ostream&	obj::operator<<(std::ostream &output, const mesh &input)
{
	output << "Mesh:" << std::endl;
	output << "\rVertex:" << std::endl;
	for (unsigned int i = 0; i < input.vertices.size(); i++)
	{
		output << input.vertices[i].m_position << std::endl;
		output << input.vertices[i].m_normal << std::endl;
		output << input.vertices[i].m_texture << std::endl;
	}
	output << "\rIndices:" << std::endl;
	for (unsigned int i = 0; i < input.indices.size(); i++)
	{
		output << "\r" << input.indices[i] << " ";
	}
	output << std::endl;
	output << "\rTexture:" << std::endl;
	for (unsigned int i = 0; i < input.textures.size(); i++)
	{
		output << "\r\rid: " << input.textures[i].id << std::endl;	
		output << "\r\rtype: " << input.textures[i].type << std::endl;	
	}
	return output;
}
