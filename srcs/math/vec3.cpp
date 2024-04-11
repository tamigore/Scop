#include "../../includes/math/vec3.hpp"

using namespace math;

vec3::vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

vec3::vec3(const vec3 &src)
{
	this->x = src.x;
	this->y = src.y;
	this->z = src.z;
}

vec3::vec3(const float &src)
{
	this->x = src;
	this->y = src;
	this->z = src;
}

vec3::vec3(const float &x, const float &y, const float &z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3::vec3(const float* src)
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	if (!src)
		return ;
	try
	{
		this->x = src[0];
		this->y = src[1];
		this->z = src[2];
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

vec3::~vec3() {}

float*	vec3::getTab() const
{
	float* tab = new float(3);
	tab[0] = this->x;
	tab[1] = this->y;
	tab[2] = this->z;
	return (tab);
}

vec3&	vec3::operator=(const vec3 &rhs) 
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return (*this);
}

vec3&	vec3::operator=(const float &rhs) 
{
	this->x = rhs;
	this->y = rhs;
	this->z = rhs;
	return (*this);
}

vec3&	vec3::operator=(const float* rhs) 
{
	if (!rhs)
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		return (*this);
	}
	this->x = rhs[0];
	this->y = rhs[1];
	this->z = rhs[2];
	return (*this);
}

vec3	vec3::operator+(const vec3 &rhs) const
{
	return (vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z));
}

vec3	vec3::operator+(const float rhs) const
{
	return (vec3(this->x + rhs, this->y + rhs, this->z + rhs));
}

vec3	vec3::operator-(const vec3 &rhs) const
{
	return (vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z));
}

vec3	vec3::operator-(const float rhs) const
{
	return (vec3(this->x - rhs, this->y - rhs, this->z - rhs));
}

vec3	vec3::operator*(const vec3 &rhs) const
{
	return (vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z));
}

vec3	vec3::operator*(const float rhs) const
{
	return (vec3(this->x * rhs, this->y * rhs, this->z * rhs));
}

vec3	vec3::operator/(const vec3 &rhs) const
{
	return (vec3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z));
}

vec3	vec3::operator/(const float rhs) const
{
	return (vec3(this->x / rhs, this->y / rhs, this->z / rhs));
}

vec3&	vec3::operator+=(const vec3 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return (*this);
}

vec3&	vec3::operator+=(const float rhs)
{
	this->x += rhs;
	this->y += rhs;
	this->z += rhs;
	return (*this);
}

vec3&	vec3::operator-=(const vec3 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return (*this);
}

vec3&	vec3::operator-=(const float rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	this->z -= rhs;
	return (*this);
}

vec3&	vec3::operator*=(const vec3 &rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	return (*this);
}

vec3&	vec3::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return (*this);
}

vec3&	vec3::vec3::operator/=(const vec3 &rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
	this->z /= rhs.z;
	return (*this);
}

vec3&	vec3::operator/=(const float rhs)
{
	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	return (*this);
}

bool	vec3::operator==(const vec3 &rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
}
bool	vec3::operator!=(const vec3 &rhs) const
{
	return (this->x != rhs.x || this->y != rhs.y || this->z != rhs.z);
}

float&	vec3::operator[](const int index)
{
	if (index == 0)
		return (this->x);
	else if (index == 1)
		return (this->y);
	else if (index == 2)
		return (this->z);
	else
		throw std::out_of_range("vec3 index out of range");
}

vec3	vec3::normalize()
{
	float mag = vec3::magnitude(*this);
	return vec3(this->x / mag, this->y / mag, this->z / mag);
}

vec3	vec3::cross(const vec3 a, const vec3 b)
{
	return vec3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

float	vec3::magnitude(const vec3 vec)
{
	return (sqrtf(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2)));
}

float	vec3::dot(const vec3 a, const vec3 b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float	vec3::angle(const vec3 a, const vec3 b)
{
	float angle = dot(a, b);
	angle /= (magnitude(a) * magnitude(b));
	return angle = acosf(angle);
}

vec3	vec3::projection(const vec3 a, const vec3 b)
{
	vec3 bn = b / magnitude(b);
	return bn * dot(a, bn);
}

namespace math
{
	std::ostream&	operator<<(std::ostream &out, const vec3 &rhs)
	{
		out << "vec3(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
		return (out);
	}

	vec3			operator*(const float lhs, const vec3 &rhs)
	{
		return (vec3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs));
	}
	
	vec3			operator/(const float lhs, const vec3 &rhs)
	{
		return (vec3(rhs.x / lhs, rhs.y / lhs, rhs.z / lhs));
	}

	vec3			operator+(const float lhs, const vec3 &rhs)
	{
		return (vec3(rhs.x + lhs, rhs.y + lhs, rhs.z + lhs));
	}

	vec3			operator-(const float lhs, const vec3 &rhs)
	{
		return (vec3(rhs.x - lhs, rhs.y - lhs, rhs.z - lhs));
	}
}