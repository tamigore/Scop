#ifndef __VEC3_HPP__
# define __VEC3_HPP__

# include <iostream>

namespace math
{

class vec3
{
	private :
		float x;
		float y;
		float z;

	public :
		vec3();
		~vec3();
		vec3(const float &src);
		vec3(const float &x, const float &y, const float &z);
		vec3(const float* src);

		float*	getFloatTab() const;
		float	getx() const;
		float	gety() const;
		float	getz() const;

		
		vec3&	operator=(const vec3 &rhs);
		vec3&	operator=(const float &rhs);
		vec3&	operator=(const float* rhs);
		vec3	operator+(const vec3 &rhs) const;
		vec3	operator+(const float rhs) const;
		vec3	operator-(const vec3 &rhs) const;
		vec3	operator-(const float rhs) const;
		vec3	operator*(const vec3 &rhs) const;
		vec3	operator*(const float rhs) const;
		vec3	operator/(const vec3 &rhs) const;
		vec3	operator/(const float rhs) const;
		vec3	operator%(const vec3 &rhs) const;
		vec3	operator%(const float rhs) const;
		vec3&	operator+=(const vec3 &rhs);
		vec3&	operator+=(const float rhs);
		vec3&	operator-=(const vec3 &rhs);
		vec3&	operator-=(const float rhs);
		vec3&	operator*=(const vec3 &rhs);
		vec3&	operator*=(const float rhs);
		vec3&	operator/=(const vec3 &rhs);
		vec3&	operator/=(const float rhs);
		bool	operator==(const vec3 &rhs) const;
		bool	operator!=(const vec3 &rhs) const;
		float&	operator[](const int index);
		

};

std::ostream&	operator<<(std::ostream &o, const vec3 &rhs);
vec3			operator*(const float lhs, const vec3 &rhs);
vec3			operator/(const float lhs, const vec3 &rhs);
vec3			operator+(const float lhs, const vec3 &rhs);
vec3			operator-(const float lhs, const vec3 &rhs);
}

#endif