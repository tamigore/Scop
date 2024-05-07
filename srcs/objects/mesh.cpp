# define STB_IMAGE_IMPLEMENTATION

# include "../../includes/stb_image.h"

#include "../../includes/objects/mesh.hpp"

using namespace obj;

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

mesh::~mesh() {}

void	mesh::draw(shader &shader)
{
	unsigned int diffuseNr  = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr   = 1;
	unsigned int heightNr   = 1;
	for(unsigned int i = 0; i < m_textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		std::string name = m_textures[i].m_type;
		std::string number;
		if(name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if(name == "texture_specular")
			number = std::to_string(specularNr++);
		else if(name == "texture_normal")
			number = std::to_string(normalNr++);
		else if(name == "texture_height")
			number = std::to_string(heightNr++);

		glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);
		glBindTexture(GL_TEXTURE_2D, m_textures[i].m_id);
	}

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_indices.size()), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	glActiveTexture(GL_TEXTURE0);
}

void mesh::setupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(vertex), &m_vertices[0], GL_STATIC_DRAW);  

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), &m_indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, m_position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, m_normal));
	glEnableVertexAttribArray(2);	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, m_texture));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, m_color));

	glBindVertexArray(0);
}

std::ostream&	obj::operator<<(std::ostream &output, const mesh &input)
{
	output << "Mesh:" << std::endl;
	output << "\rVertex:" << std::endl;
	for (unsigned int i = 0; i < input.m_vertices.size(); i++)
	{
		output << "Position: " << input.m_vertices[i].m_position << "\t";
		output << "Normal: " << input.m_vertices[i].m_normal << "\t";
		output << "Texture: " << input.m_vertices[i].m_texture << std::endl;
		output << "Color: " << input.m_vertices[i].m_color << std::endl;
	}
	output << "\rIndices:" << std::endl;
	for (unsigned int i = 0; i < input.m_indices.size(); i++)
	{
		output << input.m_indices[i] << " ";
	}
	output << std::endl;
	output << "\rTexture:" << std::endl;
	for (unsigned int i = 0; i < input.m_textures.size(); i++)
	{
		output << "\r\rid: " << input.m_textures[i].m_id << std::endl;	
		output << "\r\rtype: " << input.m_textures[i].m_type << std::endl;	
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
	if (this->m_position_indices.size() >= this->m_vertices.size())
		this->m_vertices.push_back(vertex());
	this->m_vertices[this->m_position_indices.size()].m_position = position;
	this->m_vertices[this->m_position_indices.size()].m_normal = math::vec3(0.0);
	this->m_vertices[this->m_position_indices.size()].m_texture = math::vec2(0.0);
	this->m_vertices[this->m_position_indices.size()].m_color = math::vec3(0.0);
	this->m_position_indices.push_back(this->m_position_indices.size());
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
	if (this->m_texture_indices.size() >= this->m_vertices.size())
		this->m_vertices.push_back(vertex());
	this->m_vertices[this->m_texture_indices.size()].m_texture = texture;
	this->m_texture_indices.push_back(this->m_texture_indices.size());
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
	if (this->m_normal_indices.size() >= this->m_vertices.size())
		this->m_vertices.push_back(vertex());
	this->m_vertices[this->m_normal_indices.size()].m_normal = normal;
	this->m_normal_indices.push_back(this->m_normal_indices.size());	
	return true;
}

bool	mesh::add_face(std::string pram)
{
	obj::face face;
	std::vector<std::string> tokens;
	split(pram, tokens, " ");
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		std::vector<std::string> face_tokens;
		if (tokens[i].find("//") != std::string::npos)
		{
			split(tokens[i], face_tokens, "//");
			face.m_vertice_index.push_back(std::stoul(face_tokens[0]));
			face.m_normal_index.push_back(0);
			face.m_texture_index.push_back(std::stoul(face_tokens[1]));
		}
		else if (tokens[i].find("/") != std::string::npos)
		{
			split(tokens[i], face_tokens, "/");
			face.m_vertice_index.push_back(std::stoul(face_tokens[0]));
			face.m_normal_index.push_back(std::stoul(face_tokens[1]));
			if (!face_tokens[2].empty())
				face.m_texture_index.push_back(std::stoul(face_tokens[2]));
			else
				face.m_texture_index.push_back(0);
		}
		else
		{
			face.m_vertice_index.push_back(std::stoul(tokens[i]));
			face.m_normal_index.push_back(0);
			face.m_texture_index.push_back(0);
		}
	}
	this->m_faces.push_back(face);
	for (unsigned int i = 0; i < face.m_vertice_index.size() - 2; i++)
	{
		this->m_indices.push_back(face.m_vertice_index[0] - 1);
		this->m_indices.push_back(face.m_vertice_index[i + 1] - 1);
		this->m_indices.push_back(face.m_vertice_index[i + 2] - 1);
	}
	return true;
}

bool	mesh::add_texture(const char *name, const char *path)
{
	texture texture;
	texture.m_id = TextureFromFile(name, path);
	texture.m_type = "texture_diffuse";
	texture.m_path = std::string(path) + "/" + std::string(path);
	this->m_textures.push_back(texture);
	return true;
}

unsigned int	mesh::TextureFromFile(const char *path, const std::string &directory)
{
	std::string filename = std::string(path);
	filename = directory + '/' + filename;

	std::cout << filename << std::endl;
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

bool	mesh::loadMesh(const char* path)
{
	std::string str_path = path;
	if (str_path.empty() || str_path.size() < 4 || str_path.substr(str_path.size() - 4, 4) != ".obj")
		return false;
	std::ifstream file(str_path);
	if (!file.is_open())
	{
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
		if (prefix == "o")
		{
			this->m_name = param;
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
	}
	center_around_orgin();
	facesDuplicateVertexes();
	setupMesh();
	std::cout << "Mesh Loaded" << std::endl;
	return true;
}

void	mesh::min_max_bounds(math::vec3& min_bound, math::vec3& max_bound)
{
	for (std::vector<obj::vertex>::iterator vert = this->m_vertices.begin(); vert != this->m_vertices.end();) 
	{
		min_bound[0] = std::min(min_bound[0], vert->m_position[0]);
		min_bound[1] = std::min(min_bound[1], vert->m_position[1]);
		min_bound[2] = std::min(min_bound[2], vert->m_position[2]);

		max_bound[0] = std::max(max_bound[0], vert->m_position[0]);
		max_bound[1] = std::max(max_bound[1], vert->m_position[1]);
		max_bound[2] = std::max(max_bound[2], vert->m_position[2]);
		vert++;
	}
}

void	mesh::center_around_orgin()
{
	math::vec3 min_bound = {0, 0, 0};
	math::vec3 max_bound = {0, 0, 0};

	min_max_bounds(min_bound, max_bound);

	math::vec3 center = {0, 0, 0};
	
	center[0] = (min_bound[0] + max_bound[0]) / 2;
	center[1] = (min_bound[1] + max_bound[1]) / 2;
	center[2] = (min_bound[2] + max_bound[2]) / 2;

	for (std::vector<obj::vertex>::iterator vert = this->m_vertices.begin(); vert != this->m_vertices.end(); ++vert)  {
		(vert->m_position)[0] -= center[0];
		(vert->m_position)[1] -= center[1];
		(vert->m_position)[2] -= center[2];
	}
}

void	mesh::facesDuplicateVertexes()
{
	std::map<unsigned int, unsigned int> nbPosIndex;
	math::vec3 color = {0.0, 0.0, 0.0};
	std::vector<math::vec2> textures = {
		{0.0, 0.0},
		{0.0, 1.0},
		{1.0, 0.0},
		{1.0, 1.0}
	};
	int face = 0;
	for (std::vector<unsigned int>::iterator it = this->m_indices.begin(); it != this->m_indices.end(); ++it)
	{
		if (nbPosIndex.find(*it) == nbPosIndex.end())
		{
			nbPosIndex[*it] = 1;
			this->m_vertices[*it].m_color = color;
			this->m_vertices[*it].m_texture = textures[face % 4];
		}
		else
		{
			this->m_vertices.push_back(this->m_vertices[*it]);
			*it = this->m_vertices.size() - 1;
			nbPosIndex[*it] += 1;
			this->m_vertices[*it].m_color = color;
			this->m_vertices[*it].m_texture = textures[face % 4];
		}
		face++;
		if (face % 3 == 0)
		{
			if (color.x >= 1.0)
				color.x = 0.0;
			color.x += 0.1;
		}
		if (face % 6 == 0)
		{
			if (color.y >= 1.0)
				color.y = 0.0;
			color.y += 0.1;
		}
		if (face % 9 == 0)
		{
			if (color.z >= 1.0)
				color.z = 0.0;
			color.z += 0.1;
		}
	}
}