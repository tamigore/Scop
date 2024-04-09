#ifndef __VEC2_HPP__
# define __VEC2_HPP__

# include <iostream>

namespace math
{

class vec2
{
	private :
		float x;
		float y;

	public :
		vec2();
		~vec2();
		vec2(const float &src);
		vec2(const float &x, const float &y);
		vec2(const float* src);

		float*	getFloatTab() const;
		float	getx() const;
		float	gety() const;
		
		vec2&	operator=(const vec2 &rhs);
		vec2&	operator=(const float &rhs);
		vec2&	operator=(const float* rhs);
		vec2	operator+(const vec2 &rhs) const;
		vec2	operator+(const float rhs) const;
		vec2	operator-(const vec2 &rhs) const;
		vec2	operator-(const float rhs) const;
		vec2	operator*(const vec2 &rhs) const;
		vec2	operator*(const float rhs) const;
		vec2	operator/(const vec2 &rhs) const;
		vec2	operator/(const float rhs) const;
		vec2	operator%(const vec2 &rhs) const;
		vec2	operator%(const float rhs) const;
		vec2&	operator+=(const vec2 &rhs);
		vec2&	operator+=(const float rhs);
		vec2&	operator-=(const vec2 &rhs);
		vec2&	operator-=(const float rhs);
		vec2&	operator*=(const vec2 &rhs);
		vec2&	operator*=(const float rhs);
		vec2&	operator/=(const vec2 &rhs);
		vec2&	operator/=(const float rhs);
		bool	operator==(const vec2 &rhs) const;
		bool	operator!=(const vec2 &rhs) const;
		float&	operator[](const int index);
};

std::ostream&	operator<<(std::ostream &o, const vec2 &rhs);
vec2			operator*(const float lhs, const vec2 &rhs);
vec2			operator/(const float lhs, const vec2 &rhs);
vec2			operator+(const float lhs, const vec2 &rhs);
vec2			operator-(const float lhs, const vec2 &rhs);
}

#endif