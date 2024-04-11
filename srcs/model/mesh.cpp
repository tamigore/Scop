#include "../../includes/model/mesh.hpp"

using namespace obj;

#define OBJL_CONSOLE_OUTPUT

mesh::mesh()
{
	m_name = "";
}

mesh::~mesh() {}

bool	mesh::add_vertex_position(std::string curline)
{
	std::vector<std::string> tokens;
	split(curline, tokens, " ");
	if (tokens.size() != 3)
	{
		std::cerr << "Error: Vertex does not have 3 coordinates" << std::endl;
		std::cerr << tokens[0] << tokens[1] << tokens[2] << std::endl;
		return false;
	}
	math::vec3 position;
	position.x = std::stof(tokens[0]);
	position.y = std::stof(tokens[1]);
	position.z = std::stof(tokens[2]);
	this->m_vertices.push_back(position);
	return true;
}

bool	mesh::add_vertex_texture(std::string curline)
{
	std::vector<std::string> tokens;
	split(curline, tokens, " ");
	if (tokens.size() != 2)
	{
		std::cerr << "Error: Texture does not have 2 coordinates" << std::endl;
		return false;
	}
	math::vec2 texture;
	texture.x = std::stof(tokens[0]);
	texture.y = std::stof(tokens[1]);
	this->m_texture.push_back(texture);
	return true;
}

bool	mesh::add_vertex_normal(std::string curline)
{
	std::vector<std::string> tokens;
	split(curline, tokens, " ");
	if (tokens.size() != 3)
	{
		std::cerr << "Error: Normal does not have 3 coordinates" << std::endl;
		std::cerr << tokens[0] << tokens[1] << tokens[2] << std::endl;
		return false;
	}
	math::vec3 normal;
	normal.x = std::stof(tokens[0]);
	normal.y = std::stof(tokens[1]);
	normal.z = std::stof(tokens[2]);
	this->m_normal.push_back(normal);
	return true;
}

bool	mesh::add_face(std::string pram)
{
	obj::face newface;
	std::vector<std::string> tokens;
	split(pram, tokens, " ");
	obj::vertex vertex;
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
	this->m_faces.push_back(newface);
	return true;
}

// std::vector<face> mesh::poli2tris()
// {
// 	std::vector<face> new_face;
// 	for (std::vector<std::vector<unsigned int>>::iterator it = this->base_faces.begin(); it != this->base_faces.end(); ++it)
// 	{
// 		if (it->size() < 3)
// 		{
// 			std::cout << "Error : face with less than 3 vertexes" << std::endl;
// 			exit(1);
// 		}

// 		std::size_t i = 2;
// 		while (i < it->size())
// 		{
// 			t_triangle triangle;
// 			triangle.v[0] = it->at(0) - 1;
// 			triangle.v[1] = it->at(i - 1) - 1;
// 			triangle.v[2] = it->at(i) - 1;
// 			new_triangles.push_back(triangle);
// 			i++;
// 		}
// 	}
// 	return (new_triangles);
// }

std::vector<math::vec3> mesh::faceVertexToTab()
{
	std::vector<math::vec3> triangles;
	for (unsigned int i = 0; i < this->m_faces.size(); i++)
	{
		for (unsigned int j = 0; j < this->m_faces[i].m_vertice_index.size(); j++)
		{
			triangles.push_back(this->m_faces[i].m_vertice_index[j]);
		}
	}
	return (triangles);
}

bool	mesh::load_obj(const char* path)
{
	std::string str_path = path;
	if (str_path.empty() || str_path.size() < 4 || str_path.substr(str_path.size() - 4, 4) != ".obj")
		return false;
	std::ifstream file(str_path);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << str_path << std::endl;
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
			this->m_name = param;
		}
		else if (prefix == "g")
		{
			#ifdef OBJL_CONSOLE_OUTPUT
			std::cout << "g" << std::endl;
			#endif
		}
		else if (prefix == "v")
		{
			add_vertex_position(param);
		}
		else if (prefix == "vt")
		{
			add_vertex_texture(param);
		}
		else if (prefix == "vn")
		{
			add_vertex_normal(param);
		}
		else if (prefix == "f")
		{
			add_face(param);
		}
		else if (prefix == "usemtl")
		{
			#ifdef OBJL_CONSOLE_OUTPUT
			std::cout << "usemtl" << std::endl;
			#endif
		}
		else if (prefix == "mtllib")
		{
			#ifdef OBJL_CONSOLE_OUTPUT
			std::cout << "mtllib" << std::endl;
			#endif
		}
		else if (prefix == "s")
		{
			#ifdef OBJL_CONSOLE_OUTPUT
			if (tail(curline) == "off")
			{
				std::cout << "Smooth shading disabled" << std::endl;
			}
			else
			{
				std::cout << "Smooth shading group" << std::endl;
			}
			#endif
		}
		else if (prefix[0] == '#')
		{
			continue;
		}
		else
		{
			std::cout << "Unknown token: " << prefix << std::endl;
		}
	}
	return true;
}

std::ostream&	obj::operator<<(std::ostream &output, const mesh &input)
{
	output << "Mesh " << input.m_name << "loaded" << std::endl;
	output << "Vertex position" << std::endl;
	for (unsigned int i = 0; i < input.m_vertices.size(); i++)
	{
		output << input.m_vertices[i] << std::endl;
	}
	output << "Vertex Normal" << std::endl;
	for (unsigned int i = 0; i < input.m_normal.size(); i++)
	{
		output << "normal: " << input.m_normal[i] << std::endl;
	}
	output << "Vertex Texture" << std::endl;
	for (unsigned int i = 0; i < input.m_texture.size(); i++)
	{
		output << "texture: " << input.m_texture[i] << std::endl;	
	}
	output << "Faces" << std::endl;
	for (unsigned int i = 0; i < input.m_faces.size(); i++)
	{
		output << "Face Vertex" << std::endl;
		for (unsigned int j = 0; j < input.m_faces[i].m_vertice_index.size(); j++)
		{
			output << "index: " << input.m_faces[i].m_vertice_index[j] << std::endl;	
		}
		// output << "Face Normal" << std::endl;
		// for (unsigned int j = 0; j < input.m_faces[i].m_normal_index.size(); j++)
		// {
		// 	output << "index: "  << input.m_faces[i].m_normal_index[j] << std::endl;
		// }
		// output << "Face Texture" << std::endl;
		// for (unsigned int j = 0; j < input.m_faces[i].m_texture_index.size(); j++)
		// {
		// 	output << "index: "  << input.m_faces[i].m_texture_index[j] << std::endl;	
		// }
	}
	return output;
}
