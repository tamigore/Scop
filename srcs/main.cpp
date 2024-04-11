#include "../includes/header.hpp"
//g++ openGL.cpp -lglut -lGLU -lGL; ./a.out
#include "../includes/stb_image.h"
#include "../includes/obj_loader/mesh.hpp"

int zoom = 0;

double fps = 0.0;
bool color = true;

bool rotate_p = false;
bool color_p = false;



int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "No argument" << std::endl;
		return 1;
	}
	
	obj::mesh mesh;
	mesh.load_obj(av[1]);
	std::cout << "Mesh " << mesh.m_name << "loaded" << std::endl;
	std::cout << "Vertex position" << std::endl;
	for (unsigned int i = 0; i < mesh.m_vertices.size(); i++)
	{
		std::cout << mesh.m_vertices[i] << std::endl;
	}
	std::cout << "Vertex Normal" << std::endl;
	for (unsigned int i = 0; i < mesh.m_normal.size(); i++)
	{
		std::cout << "normal: " << mesh.m_normal[i] << std::endl;
	}
	std::cout << "Vertex Texture" << std::endl;
	for (unsigned int i = 0; i < mesh.m_texture.size(); i++)
	{
		std::cout << "texture: " << mesh.m_texture[i] << std::endl;	
	}
	std::cout << "Faces" << std::endl;
	for (unsigned int i = 0; i < mesh.m_faces.size(); i++)
	{
		std::cout << "Face Vertex" << std::endl;
		for (unsigned int j = 0; j < mesh.m_faces[i].m_vertice_index.size(); j++)
		{
			std::cout << "index: "  << mesh.m_faces[i].m_vertice_index[i] << std::endl;	
		}
		std::cout << "Face Normal" << std::endl;
		for (unsigned int j = 0; j < mesh.m_faces[i].m_normal_index.size(); j++)
		{
			std::cout << "index: "  << mesh.m_faces[i].m_normal_index[i] << std::endl;
		}
		std::cout << "Face Texture" << std::endl;
		for (unsigned int j = 0; j < mesh.m_faces[i].m_texture_index.size(); j++)
		{
			std::cout << "index: "  << mesh.m_faces[i].m_texture_index[i] << std::endl;	
		}
	}
	
	scop::game game(1000, 1000);
    game.init(ac, av);
	game.loop();
	return 0;
}