#include "../../includes/math/vec2.hpp"

using namespace math;

vec2::vec2()
{
	this->x = 0;
	this->y = 0;
}

vec2::~vec2() {}

vec2::vec2(const float &src)
{
	this->x = src;
	this->y = src;
}

vec2::vec2(const float &x, const float &y)
{
	this->x = x;
	this->y = y;
}

vec2::vec2(const float* src)
{
	if (!src)
	{
		this->x = 0;
		this->y = 0;
		return ;
	}
	this->x = src[0];
	this->y = src[1];
}

float*	vec2::getFloatTab() const
{
	float* tab = new float[3];
	tab[0] = this->x;
	tab[1] = this->y;
	return (tab);
}

float	vec2::getx() const
{
	return (this->x);
}

float	vec2::gety() const
{
	return (this->y);
}

vec2&	vec2::operator=(const vec2 &rhs) 
{
	this->x = rhs.x;
	this->y = rhs.y;
	return (*this);
}

vec2&	vec2::operator=(const float &rhs) 
{
	this->x = rhs;
	this->y = rhs;
	return (*this);
}

vec2&	vec2::operator=(const float* rhs) 
{
	if (!rhs)
	{
		this->x = 0;
		this->y = 0;
		return (*this);
	}
	this->x = rhs[0];
	this->y = rhs[1];
	return (*this);
}

vec2	vec2::operator+(const vec2 &rhs) const
{
	return (vec2(this->x + rhs.x, this->y + rhs.y));
}

vec2	vec2::operator+(const float rhs) const
{
	return (vec2(this->x + rhs, this->y + rhs));
}

vec2	vec2::operator-(const vec2 &rhs) const
{
	return (vec2(this->x - rhs.x, this->y - rhs.y));
}

vec2	vec2::operator-(const float rhs) const
{
	return (vec2(this->x - rhs, this->y - rhs));
}

vec2	vec2::operator*(const vec2 &rhs) const
{
	return (vec2(this->x * rhs.x, this->y * rhs.y));
}

vec2	vec2::operator*(const float rhs) const
{
	return (vec2(this->x * rhs, this->y * rhs));
}

vec2	vec2::operator/(const vec2 &rhs) const
{
	return (vec2(this->x / rhs.x, this->y / rhs.y));
}

vec2	vec2::operator/(const float rhs) const
{
	return (vec2(this->x / rhs, this->y / rhs));
}

vec2&	vec2::operator+=(const vec2 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return (*this);
}

vec2&	vec2::operator+=(const float rhs)
{
	this->x += rhs;
	this->y += rhs;
	return (*this);
}

vec2&	vec2::operator-=(const vec2 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return (*this);
}

vec2&	vec2::operator-=(const float rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	return (*this);
}

vec2&	vec2::operator*=(const vec2 &rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	return (*this);
}

vec2&	vec2::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	return (*this);
}

vec2&	vec2::vec2::operator/=(const vec2 &rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	return (*this);
}

vec2&	vec2::operator/=(const float rhs)
{
	this->x /= rhs;
	this->y /= rhs;
	return (*this);
}

bool	vec2::operator==(const vec2 &rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);
}
bool	vec2::operator!=(const vec2 &rhs) const
{
	return (this->x != rhs.x || this->y != rhs.y);
}

float&	vec2::operator[](const int index)
{
	if (index == 0)
		return (this->x);
	else if (index == 1)
		return (this->y);
	else
		throw std::out_of_range("vec2 index out of range");
}

namespace math
{
	std::ostream&	operator<<(std::ostream &out, const vec2 &rhs)
	{
		float* tab = rhs.getFloatTab();
		out << tab[0]<< " " << tab[1] << " " << tab[2];
		delete[] tab;
		return (out);
	}

	vec2			operator*(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.getx() * lhs, rhs.gety() * lhs));
	}
	
	vec2			operator/(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.getx() / lhs, rhs.gety() / lhs));
	}

	vec2			operator+(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.getx() + lhs, rhs.gety() + lhs));
	}

	vec2			operator-(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.getx() - lhs, rhs.gety() - lhs));
	}
}