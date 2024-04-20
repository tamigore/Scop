#include "../../includes/objects/mesh.hpp"
#include "../glad/glad.h"
#include <GLFW/glfw3.h>

using namespace obj;

#define OBJL_CONSOLE_OUTPUT

mesh::mesh() {}

mesh::mesh(char* path)
{
	if (!loadMesh(path))
	{
		std::cout << "Error: Could not load mesh" << std::endl;
		throw std::exception();
	}
	std::cout << *this << std::endl;
	setupMesh();
}

// mesh::mesh(std::vector<vertex> vertices, std::vector<unsigned int> indices, std::vector<texture> textures)
// {
// 	this->vertices = vertices;
// 	this->indices = indices;
// 	this->textures = textures;
// 	setupMesh();
// }

mesh::~mesh() {}

void	mesh::draw(shader &shader)
{
	// bind appropriate textures
	// unsigned int diffuseNr  = 1;
	// unsigned int specularNr = 1;
	// unsigned int normalNr   = 1;
	// unsigned int heightNr   = 1;
	// for(unsigned int i = 0; i < textures.size(); i++)
	// {
	// 	glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
	// 	// retrieve texture number (the N in diffuse_textureN)
	// 	std::string name = textures[i].type;
	// 	std::string number;
	// 	if(name == "texture_diffuse")
	// 		number = std::to_string(diffuseNr++);
	// 	else if(name == "texture_specular")
	// 		number = std::to_string(specularNr++); // transfer unsigned int to string
	// 	else if(name == "texture_normal")
	// 		number = std::to_string(normalNr++); // transfer unsigned int to string
	// 		else if(name == "texture_height")
	// 		number = std::to_string(heightNr++); // transfer unsigned int to string

	// 	// now set the sampler to the correct texture unit
	// 	glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
	// 	// and finally bind the texture
	// 	glBindTexture(GL_TEXTURE_2D, textures[i].id);
	// }
	// glActiveTexture(GL_TEXTURE0); // active proper texture unit before binding
	// glUniform1i(glGetUniformLocation(shader.ID, "texture1"), texture1);
	// glUniform1i(glGetUniformLocation(shader.ID, "texture2"), texture2);
	// glBindTexture(GL_TEXTURE_2D, texture1);
	// glBindTexture(GL_TEXTURE_2D, texture2);

	math::mat4 model = math::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	float angle = glfwGetTime() * 20.0f;
	model = math::rotate(model, math::radians(angle), math::vec3(0.0f, 0.0f, 1.0f));
	shader.setMat4("model", model);
	// draw mesh
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// always good practice to set everything back to defaults once configured.
	glActiveTexture(GL_TEXTURE0);
}

void mesh::setupMesh()
{
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(vertex), &this->vertices[0], GL_STATIC_DRAW);  

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(unsigned int), &this->indices[0], GL_STATIC_DRAW);

	// vertex positions
	glEnableVertexAttribArray(0);	
	std::cout << "Vertex offset Normal : " << offsetof(vertex, Normal) << " vs " << 3 * sizeof(float) << std::endl;
	std::cout << "Vertex offset Texture : " << offsetof(vertex, Texture) << std::endl;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
	// vertex normals
	glEnableVertexAttribArray(1);	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, Normal));
	// vertex texture coords
	glEnableVertexAttribArray(2);	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, Texture));

	glBindVertexArray(0);
}

std::ostream&	obj::operator<<(std::ostream &output, const mesh &input)
{
	output << "Mesh:" << std::endl;
	output << "\rVertex:" << std::endl;
	for (unsigned int i = 0; i < input.vertices.size(); i++)
	{
		output << input.vertices[i].Position << std::endl;
		output << input.vertices[i].Normal << std::endl;
		output << input.vertices[i].Texture << std::endl;
	}
	output << "\rIndices:" << std::endl;
	for (unsigned int i = 0; i < input.indices.size(); i++)
	{
		output << input.indices[i] << " ";
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

bool	mesh::add_vertex_position(std::string curline)
{
	std::vector<std::string> tokens;
	split(curline, tokens, " ");
	if (tokens.size() != 3)
	{
		std::cout << "Error: Vertex does not have 3 coordinates" << std::endl;
		return false;
	}
	math::vec3 position;
	position.x = std::stof(tokens[0]);
	position.y = std::stof(tokens[1]);
	position.z = std::stof(tokens[2]);
	if (this->position_indices.size() >= this->vertices.size())
		this->vertices.push_back(vertex());
	this->vertices[this->position_indices.size()].Position = position;
	this->vertices[this->position_indices.size()].Normal = math::vec3(0.3f, 0.3f, 0.4f);
	this->vertices[this->position_indices.size()].Texture = math::vec2(position.x, position.y);
	this->position_indices.push_back(this->position_indices.size());
	return true;
}

bool	mesh::add_vertex_texture(std::string curline)
{
	std::vector<std::string> tokens;
	split(curline, tokens, " ");
	if (tokens.size() != 2)
	{
		std::cout << "Error: Texture does not have 2 coordinates" << std::endl;
		return false;
	}
	math::vec2 texture;
	texture.x = std::stof(tokens[0]);
	texture.y = std::stof(tokens[1]);
	if (texture.x < 0 || texture.x > 1 || texture.y < 0 || texture.y > 1)
	{
		std::cout << "Error: Texture coordinates are not normalized" << std::endl;
		return false;
	}
	if (this->texture_indices.size() >= this->vertices.size())
	{
		std::cout << "Error: Normal index out of range" << std::endl;
		return false;
	}
	this->vertices[this->texture_indices.size()].Texture = texture;
	this->texture_indices.push_back(this->texture_indices.size());
	return true;
}

bool	mesh::add_vertex_normal(std::string curline)
{
	std::vector<std::string> tokens;
	split(curline, tokens, " ");
	if (tokens.size() != 3)
	{
		std::cout << "Error: Normal does not have 3 coordinates" << std::endl;
		return false;
	}
	math::vec3 normal;
	normal.x = std::stof(tokens[0]);
	normal.y = std::stof(tokens[1]);
	normal.z = std::stof(tokens[2]);
	if (this->normal_indices.size() >= this->vertices.size())
	{
		std::cout << "Error: Normal index out of range" << std::endl;
		return false;
	}
	this->vertices[this->normal_indices.size()].Normal = normal;
	this->normal_indices.push_back(this->normal_indices.size());	
	return true;
}

bool	mesh::add_face(std::string pram)
{
	obj::face newface;
	std::vector<std::string> tokens;
	split(pram, tokens, " ");
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		std::vector<std::string> face_tokens;
		if (tokens[i].find("/") != std::string::npos)
		{
			split(tokens[i], face_tokens, "/");
			newface.m_vertice_index.push_back(std::stoul(face_tokens[0]));
			newface.m_normal_index.push_back(std::stoul(face_tokens[1]));
			if (!face_tokens[2].empty())
				newface.m_texture_index.push_back(std::stoul(face_tokens[2]));
			else
				newface.m_texture_index.push_back(0);
		}
		else if (tokens[i].find("//") != std::string::npos)
		{
			newface.m_vertice_index.push_back(std::stoul(face_tokens[0]));
			newface.m_normal_index.push_back(0);
			newface.m_texture_index.push_back(std::stoul(face_tokens[1]));
		}
		else
		{
			newface.m_vertice_index.push_back(std::stoul(tokens[i]));
			newface.m_normal_index.push_back(0);
			newface.m_texture_index.push_back(0);
		}
	}
	this->faces.push_back(newface);
	for (unsigned int i = 0; i < newface.m_vertice_index.size() - 2; i++)
	{
		this->indices.push_back(newface.m_vertice_index[0] - 1);
		this->indices.push_back(newface.m_vertice_index[i + 1] - 1);
		this->indices.push_back(newface.m_vertice_index[i + 2] - 1);
	}
	return true;
}

bool	mesh::loadMesh(const char* path)
{
	std::string str_path = path;
	if (str_path.empty() || str_path.size() < 4 || str_path.substr(str_path.size() - 4, 4) != ".obj")
		return false;
	std::ifstream file(str_path);
	if (!file.is_open()) {
		std::cout << "Error: Could not open file " << str_path << std::endl;
		return false;
	}

	std::string curline;
	while (std::getline(file, curline))
	{
		if (curline.empty())
			continue;
		std::string prefix = firstToken(curline);
		std::string param = tail(curline);
		#ifdef OBJL_CONSOLE_OUTPUT
		std::cout << "\r- " << prefix << " " << param << std::endl;
		#endif
		if (prefix == "o")
		{
			this->name = param;
		}
		else if (prefix == "v")
		{
			if (!add_vertex_position(param))
				return false;
		}
		else if (prefix == "vt")
		{
			if (!add_vertex_texture(param))
				return false;
		}
		else if (prefix == "vn")
		{
			if (!add_vertex_normal(param))
				return false;
		}
		else if (prefix == "f")
		{
			if (!add_face(param))
				return false;
		}
		// else if (prefix == "g")
		// {
		// 	#ifdef OBJL_CONSOLE_OUTPUT
		// 	std::cout << "g" << std::endl;
		// 	#endif
		// }
		// else if (prefix == "usemtl")
		// {
		// 	#ifdef OBJL_CONSOLE_OUTPUT
		// 	std::cout << "usemtl" << std::endl;
		// 	#endif
		// }
		// else if (prefix == "mtllib")
		// {
		// 	#ifdef OBJL_CONSOLE_OUTPUT
		// 	std::cout << "mtllib" << std::endl;
		// 	#endif
		// }
		// else if (prefix == "s")
		// {
		// 	#ifdef OBJL_CONSOLE_OUTPUT
		// 	if (tail(curline) == "off")
		// 	{
		// 		std::cout << "Smooth shading disabled" << std::endl;
		// 	}
		// 	else
		// 	{
		// 		std::cout << "Smooth shading group" << std::endl;
		// 	}
		// 	#endif
		// }
		// else if (prefix[0] == '#')
		// {
		// 	continue;
		// }
		// else
		// {
		// 	std::cout << "Unknown token: " << prefix << std::endl;
		// }
	}
	setupMesh();
	std::cout << "Mesh Loaded" << std::endl;
	return true;
}