#ifndef __MAT4_HPP__
# define __MAT4_HPP__

# include <math.h>
# include <iostream>
# include "vec3.hpp"

namespace math
{

class mat4
{
	public:
		mat4();
		~mat4();
		mat4(const mat4 &src);
		mat4(float diag);

		mat4&	translate(float x, float y, float z);
		mat4&	rotate(float angle, float x, float y, float z);
		mat4&	rotate(float angle, const vec3 &vec);
		mat4&	perspective(float fov, float aspect, float near, float far);
		mat4&	scale(const vec3 &vec);

		float*	getValue();

		mat4&	operator=(const mat4 &rhs);
		mat4&	operator=(const float &rhs);
		mat4&	operator=(const float* rhs);
		mat4	operator+(const mat4 &rhs) const;
		mat4	operator+(const float rhs) const;
		mat4	operator-(const mat4 &rhs) const;
		mat4	operator-(const float rhs) const;
		mat4	operator*(const mat4 &rhs) const;
		mat4	operator*(const float rhs) const;
		mat4	operator/(const mat4 &rhs) const;
		mat4	operator/(const float rhs) const;
		mat4&	operator+=(const mat4 &rhs);
		mat4&	operator+=(const float rhs);
		mat4&	operator-=(const mat4 &rhs);
		mat4&	operator-=(const float rhs);
		mat4&	operator*=(const mat4 &rhs);
		mat4&	operator*=(const float rhs);
		mat4&	operator/=(const mat4 &rhs);
		mat4&	operator/=(const float rhs);
		bool	operator==(const mat4 &rhs) const;
		bool	operator!=(const mat4 &rhs) const;
		float*	operator[](const int index);

	private:
		float	value[4][4];
};

std::ostream&	operator<<(std::ostream &o, const mat4 &rhs);
// mat4			operator*(const mat4 lhs, const mat4 &rhs);
// mat4			operator*(const float lhs, const mat4 &rhs);
// mat4			operator/(const mat4 lhs, const mat4 &rhs);
// mat4			operator/(const float lhs, const mat4 &rhs);
// mat4			operator+(const mat4 lhs, const mat4 &rhs);
// mat4			operator+(const float lhs, const mat4 &rhs);
// mat4			operator-(const mat4 lhs, const mat4 &rhs);
// mat4			operator-(const float lhs, const mat4 &rhs);

}

#endif
