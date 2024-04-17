#pragma once
#include "qualifier.hpp"

namespace math
{

	template<typename T>
	struct vec<3, T>
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef vec<3, T> type;

		/// Return the count of components of the vector
		static int length(){return 3;}

		T & operator[](int i);
		T const& operator[](int i) const;

		// -- Implicit basic constructors --

		vec();

		vec(vec const& v);

		vec(vec<3, T> const& v);

		// -- Explicit basic constructors --

		vec<3, T>::vec(T scalar);

		vec<3, T>::vec(T _x, T _y, T _z);

		// -- Conversion scalar constructors --

		template<typename U>
		vec<3, T>::vec(vec<1, U> const& v);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(X _x, Y _y, Z _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(vec<1, X> const& _x, Y _y, Z _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(X _x, vec<1, Y> const& _y, Z _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(X _x, Y _y, vec<1, Z> const& _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z);

		template<typename X, typename Y, typename Z>
		vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z);

		// -- Conversion vector constructors --

		template<typename A, typename Bualifier P>
		vec<3, T>::vec(vec<2, A> const& _xy, B _z);

		template<typename A, typename Bualifier P>
		vec<3, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z);

		template<typename A, typename Bualifier P>
		vec<3, T>::vec(A _x, vec<2, B> const& _yz);

		template<typename A, typename Bualifier P>
		vec<3, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz);

		template<typename Uualifier P>
		vec<3, T>::vec(vec<3, U> const& v);

		template<typename Uualifier P>
		vec<3, T>::vec(vec<4, U> const& v);

		// -- Explicit basic constructors --

		explicit vec(T scalar);

		// -- Unary arithmetic operators --

		vec<3, T> & operator=(vec const& v);

		template<typename U>
		vec<3, T> & operator=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator+=(U scalar);
		template<typename U>
		vec<3, T> & operator+=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator-=(U scalar);
		template<typename U>
		vec<3, T> & operator-=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator*=(U scalar);
		template<typename U>
		vec<3, T> & operator*=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator/=(U scalar);
		template<typename U>
		vec<3, T> & operator/=(vec<3, U> const& v);

		// -- Increment and decrement operators --

		vec<3, T> & operator++();
		vec<3, T> & operator--();
		vec<3, T> operator++(int);
		vec<3, T> operator--(int);

		// -- Unary bit operators --

		template<typename U>
		vec<3, T> & operator%=(U scalar);
		template<typename U>
		vec<3, T> & operator%=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator&=(U scalar);
		template<typename U>
		vec<3, T> & operator&=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator|=(U scalar);
		template<typename U>
		vec<3, T> & operator|=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator^=(U scalar);
		template<typename U>
		vec<3, T> & operator^=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator<<=(U scalar);
		template<typename U>
		vec<3, T> & operator<<=(vec<3, U> const& v);
		template<typename U>
		vec<3, T> & operator>>=(U scalar);
		template<typename U>
		vec<3, T> & operator>>=(vec<3, U> const& v);
	};

	// -- Unary operators --

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v);

	// -- Binary operators --

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator+(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator-(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator*(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator*(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator/(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator/(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator%(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator%(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator&(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator&(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator|(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator|(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator^(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator^(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator<<(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator<<(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator>>(vec<3, T> const& v, T scalar);

	template<typename T>
	vec<3, T> operator>>(T scalar, vec<3, T> const& v);

	template<typename T>
	vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	vec<3, T> operator~(vec<3, T> const& v);

	// -- Boolean operators --

	template<typename T>
	bool operator==(vec<3, T> const& v1, vec<3, T> const& v2);

	template<typename T>
	bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2);

} //namespace math
