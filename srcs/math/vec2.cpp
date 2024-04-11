#include "../../includes/math/vec2.hpp"

using namespace math;

vec2::vec2()
{
	this->x = 0;
	this->y = 0;
}

vec2::vec2(const vec2 &src)
{
	this->x = src.x;
	this->y = src.y;
}

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

vec2::~vec2() {}

float*	vec2::getFloatTab() const
{
	float* tab = new float(2);
	tab[0] = this->x;
	tab[1] = this->y;
	return (tab);
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

vec2	vec2::normalize()
{
	float mag = vec2::magnitude(*this);
	return vec2(this->x / mag, this->y / mag);
}

float	vec2::cross(const vec2 a, const vec2 b)
{
	return (a.x * b.y - a.y * b.x);
}

float	vec2::magnitude(const vec2 vec)
{
	return (sqrtf(powf(vec.x, 2) + powf(vec.y, 2)));
}

float	vec2::dot(const vec2 a, const vec2 b)
{
	return (a.x * b.x) + (a.y * b.y);
}

float	vec2::angle(const vec2 a, const vec2 b)
{
	float angle = dot(a, b);
	angle /= (magnitude(a) * magnitude(b));
	return angle = acosf(angle);
}

vec2	vec2::projection(const vec2 a, const vec2 b)
{
	vec2 bn = b / magnitude(b);
	return bn * dot(a, bn);
}

namespace math
{
	std::ostream&	operator<<(std::ostream &out, const vec2 &rhs)
	{
		out << "vec2(" << rhs.x << ", " << rhs.y << ")";
		return (out);
	}

	vec2			operator*(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.x * lhs, rhs.y * lhs));
	}
	
	vec2			operator/(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.x / lhs, rhs.y / lhs));
	}

	vec2			operator+(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.x + lhs, rhs.y + lhs));
	}

	vec2			operator-(const float lhs, const vec2 &rhs)
	{
		return (vec2(rhs.x - lhs, rhs.y - lhs));
	}
}