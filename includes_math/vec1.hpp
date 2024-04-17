#pragma once
#include "qualifier.hpp"

namespace math
{

	template<typename T>
	struct vec<1, T>
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef vec<1, T> type;

		/// Return the count of components of the vector
		static int length(){return 1;}

		T & operator[](int i);
		T const& operator[](int i) const;

		// -- Implicit basic constructors --

		vec();
		vec(vec const& v);
		template<>
		vec(vec<1, T> const& v);

		// -- Explicit basic constructors --

		explicit vec(T scalar);

		template<typename U>
		vec(vec<2, U> const& v);

		template<typename U>
		vec(vec<3, U> const& v);

		template<typename U>
		vec(vec<4, U> const& v);

		template<typename U>
		vec(vec<1, U> const& v);

		// -- Unary arithmetic operators --

		vec<1, T> & operator=(vec const& v);

		template<typename U>
		vec<1, T> & operator=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator+=(U scalar);
		template<typename U>
		vec<1, T> & operator+=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator-=(U scalar);
		template<typename U>
		vec<1, T> & operator-=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator*=(U scalar);
		template<typename U>
		vec<1, T> & operator*=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator/=(U scalar);
		template<typename U>
		vec<1, T> & operator/=(vec<1, U> const& v);

		// -- Increment and decrement operators --

		vec<1, T> & operator++();
		vec<1, T> & operator--();
		vec<1, T> operator++(int);
		vec<1, T> operator--(int);

		// -- Unary bit operators --

		template<typename U>
		vec<1, T> & operator%=(U scalar);
		template<typename U>
		vec<1, T> & operator%=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator&=(U scalar);
		template<typename U>
		vec<1, T> & operator&=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator|=(U scalar);
		template<typename U>
		vec<1, T> & operator|=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator^=(U scalar);
		template<typename U>
		vec<1, T> & operator^=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator<<=(U scalar);
		template<typename U>
		vec<1, T> & operator<<=(vec<1, U> const& v);
		template<typename U>
		vec<1, T> & operator>>=(U scalar);
		template<typename U>
		vec<1, T> & operator>>=(vec<1, U> const& v);
	};

	// -- Unary operators --

	template<typename T>
	vec<1, T> operator+(vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator-(vec<1, T> const& v);

	// -- Binary operators --

	template<typename T>
	vec<1, T> operator+(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator+(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator+(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator-(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator-(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator-(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator*(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator*(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator*(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator/(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator/(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator/(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator%(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator%(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator%(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator&(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator&(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator&(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator|(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator|(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator|(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator^(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator^(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator^(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator<<(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator<<(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator<<(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator>>(vec<1, T> const& v, T scalar);

	template<typename T>
	vec<1, T> operator>>(T scalar, vec<1, T> const& v);

	template<typename T>
	vec<1, T> operator>>(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	vec<1, T> operator~(vec<1, T> const& v);

	// -- Boolean operators --

	template<typename T>
	bool operator==(vec<1, T> const& v1, vec<1, T> const& v2);

	template<typename T>
	bool operator!=(vec<1, T> const& v1, vec<1, T> const& v2);

} //namespace math
