#include "../../includes/obj_loader/obj_loader.hpp"

using namespace obj;

obj_loader::obj_loader()
{
	m_valid = false;
}

obj_loader::obj_loader(const char *path)
{
	m_valid = false;
	std::string path_str = path;
	if (path_str.substr(path_str.size() - 4, 4) != ".obj")
		return;

	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << path << std::endl;\
	}
	
}

obj_loader::~obj_loader()
{
	
}
