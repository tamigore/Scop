#ifndef __TEXTURE_HPP__
# define __TEXTURE_HPP__

# include <string>

namespace obj
{

struct texture
{
	unsigned int	m_id;
	std::string		m_type;
	std::string		m_path;
};

}

#endif
