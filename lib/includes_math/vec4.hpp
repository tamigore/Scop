#pragma once

#include "qualifier.hpp"

namespace math
{

	template<typename T>
	struct vec<4, T>
	{
		typedef T value_type;
		typedef vec<4, T> type;

		/// Return the count of components of the vector
		
		static int length(){return 4;}

		/// Access to values by index

		T & operator[](int i);
		T const& operator[](int i) const;

		// -- Implicit basic constructors --

		vec();
		
		vec(vec const& v);
		
		vec(vec<4, T> const& v);
		
		vec(T _x, T _y, T _z, T _w);
		
		vec(T scalar);
		
		template<typename U>
		vec(vec<1, U> const& v);
		
		template<typename X, typename Y, typename Z, typename W>
		vec(X _x, Y _y, Z _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec(vec<1, X> const& _x, Y _y, Z _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(X _x, vec<1, Y> const& _y, Z _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(X _x, Y _y, vec<1, Z> const& _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z, W _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, Y _y, Z _z, vec<1, W> const& _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(X _x, vec<1, Y> const& _y, Z _z, vec<1, W> const& _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z, vec<1, W> const& _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(X _x, Y _y, vec<1, Z> const& _z, vec<1, W> const& _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z, vec<1, W> const& _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z, vec<1, W> const& _w);
		
		template<typename X, typename Y, typename Z, typename W>
		vec<4, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z, vec<1, W> const& _w);

		// -- Conversion vector constructors --

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<2, A> const& _xy, B _z, C _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z, C _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<2, A> const& _xy, B _z, vec<1, C> const& _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z, vec<1, C> const& _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(A _x, vec<2, B> const& _yz, C _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz, C _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(A _x, vec<2, B> const& _yz, vec<1, C> const& _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz, vec<1, C> const& _w);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(A _x, B _y, vec<2, C> const& _zw);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<1, A> const& _x, B _y, vec<2, C> const& _zw);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(A _x, vec<1, B> const& _y, vec<2, C> const& _zw);

		template<typename A, typename B, typename C>
		vec<4, T>::vec(vec<1, A> const& _x, vec<1, B> const& _y, vec<2, C> const& _zw);

		template<typename A, typename B>
		vec<4, T>::vec(vec<3, A> const& _xyz, B _w);

		template<typename A, typename B>
		vec<4, T>::vec(vec<3, A> const& _xyz, vec<1, B> const& _w);

		template<typename A, typename B>
		vec<4, T>::vec(A _x, vec<3, B> const& _yzw);

		template<typename A, typename B>
		vec<4, T>::vec(vec<1, A> const& _x, vec<3, B> const& _yzw);

		template<typename A, typename B>
		vec<4, T>::vec(vec<2, A> const& _xy, vec<2, B> const& _zw);

		template<typename U>
		vec<4, T>::vec(vec<4, U> const& v);

		// -- Explicit basic constructors --

		explicit vec(T scalar);

		// -- Unary arithmetic operators --

		vec<4, T> & operator=(vec const& v);

		template<typename U>
		vec<4, T> & operator=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator+=(U scalar);
		
		template<typename U>
		vec<4, T> & operator+=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator-=(U scalar);
		
		template<typename U>
		vec<4, T> & operator-=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator*=(U scalar);
		
		template<typename U>
		vec<4, T> & operator*=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator/=(U scalar);
		
		template<typename U>
		vec<4, T> & operator/=(vec<4, U> const& v);

		// -- Increment and decrement operators --

		vec<4, T> & operator++();
		vec<4, T> & operator--();
		vec<4, T> operator++(int);
		vec<4, T> operator--(int);

		// -- Unary bit operators --

		template<typename U>
		vec<4, T> & operator%=(U scalar);
		
		template<typename U>
		vec<4, T> & operator%=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator&=(U scalar);
		
		template<typename U>
		vec<4, T> & operator&=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator|=(U scalar);
		
		template<typename U>
		vec<4, T> & operator|=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator^=(U scalar);
		
		template<typename U>
		vec<4, T> & operator^=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator<<=(U scalar);
		
		template<typename U>
		vec<4, T> & operator<<=(vec<4, U> const& v);
		
		template<typename U>
		vec<4, T> & operator>>=(U scalar);
		
		template<typename U>
		vec<4, T> & operator>>=(vec<4, U> const& v);
	};

	// -- Unary operators --

	template<typename T>
	vec<4, T> operator+(vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator-(vec<4, T> const& v);

	// -- Binary operators --

	template<typename T>
	vec<4, T> operator+(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator+(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator+(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator-(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator-(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator-(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator*(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator*(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator*(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator/(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator/(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator/(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator%(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator%(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator%(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator&(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator&(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator&(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator|(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator|(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator|(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator^(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator^(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator^(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator<<(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator<<(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator<<(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator>>(vec<4, T> const& v, T scalar);

	template<typename T>
	vec<4, T> operator>>(T scalar, vec<4, T> const& v);

	template<typename T>
	vec<4, T> operator>>(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	vec<4, T> operator~(vec<4, T> const& v);

	// -- Boolean operators --

	template<typename T>
	bool operator==(vec<4, T> const& v1, vec<4, T> const& v2);

	template<typename T>
	bool operator!=(vec<4, T> const& v1, vec<4, T> const& v2);

} //namespace math
