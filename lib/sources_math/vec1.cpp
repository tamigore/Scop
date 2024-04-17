#include "../includes/vec1.hpp"

namespace math
{
	// -- Implicit basic constructors --

	template<typename T>
	vec<1, T>::vec(): x(0)
	{}

	template<typename T>
	vec<1, T>::vec(vec<1, T> const& v): x(v.x)
	{}

	template<typename T>
	vec<1, T>::vec(vec<1, T> const& v): x(v.x)
	{}

	// -- Explicit basic constructors --

	template<typename T>
	vec<1, T>::vec(T scalar): x(scalar)
	{}

	// -- Conversion vector constructors --

	template<typename T>
	template<typename U>
	vec<1, T>::vec(vec<1, U> const& v): x(static_cast<T>(v.x))
	{}

	template<typename T>
	template<typename U>
	vec<1, T>::vec(vec<2, U> const& v): x(static_cast<T>(v.x))
	{}

	template<typename T>
	template<typename U>
	vec<1, T>::vec(vec<3, U> const& v): x(static_cast<T>(v.x))
	{}

	template<typename T>
	template<typename U>
	vec<1, T>::vec(vec<4, U> const& v): x(static_cast<T>(v.x))
	{}

	// -- Component accesses --

	template<typename T>
	T & vec<1, T>::operator[](int i)
	{
		return x;
	}

	template<typename T>
	T const& vec<1, T>::operator[](int i) const
	{
		return x;
	}

	// -- Unary arithmetic operators --

	template<typename T>
	vec<1, T> & vec<1, T>::operator=(vec<1, T> const& v)
	{
		this->x = v.x;
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator=(vec<1, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator+=(vec<1, U> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator-=(vec<1, U> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator*=(vec<1, U> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator/=(vec<1, U> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	// -- Increment and decrement operators --

	template<typename T>
	vec<1, T> & vec<1, T>::operator++()
	{
		++this->x;
		return *this;
	}

	template<typename T>
	vec<1, T> & vec<1, T>::operator--()
	{
		--this->x;
		return *this;
	}

	template<typename T>
	vec<1, T> vec<1, T>::operator++(int)
	{
		vec<1, T> Result(*this);
		++*this;
		return Result;
	}

	template<typename T>
	vec<1, T> vec<1, T>::operator--(int)
	{
		vec<1, T> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary bit operators --

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator%=(vec<1, U> const& v)
	{
		this->x %= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator&=(vec<1, U> const& v)
	{
		this->x &= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator|=(vec<1, U> const& v)
	{
		this->x |= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator^=(vec<1, U> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator<<=(vec<1, U> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<1, T> & vec<1, T>::operator>>=(vec<1, U> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		return *this;
	}

	// -- Unary constant operators --

	template<typename T>
	vec<1, T> operator+(vec<1, T> const& v)
	{
		return v;
	}

	template<typename T>
	vec<1, T> operator-(vec<1, T> const& v)
	{
		return vec<1, T>(
			-v.x);
	}

	// -- Binary arithmetic operators --

	template<typename T>
	vec<1, T> operator+(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x + scalar);
	}

	template<typename T>
	vec<1, T> operator+(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar + v.x);
	}

	template<typename T>
	vec<1, T> operator+(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x + v2.x);
	}

	//operator-
	template<typename T>
	vec<1, T> operator-(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x - scalar);
	}

	template<typename T>
	vec<1, T> operator-(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar - v.x);
	}

	template<typename T>
	vec<1, T> operator-(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x - v2.x);
	}

	template<typename T>
	vec<1, T> operator*(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x * scalar);
	}

	template<typename T>
	vec<1, T> operator*(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar * v.x);
	}

	template<typename T>
	vec<1, T> operator*(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x * v2.x);
	}

	template<typename T>
	vec<1, T> operator/(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x / scalar);
	}

	template<typename T>
	vec<1, T> operator/(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar / v.x);
	}

	template<typename T>
	vec<1, T> operator/(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x / v2.x);
	}

	// -- Binary bit operators --

	template<typename T>
	vec<1, T> operator%(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x % scalar);
	}

	template<typename T>
	vec<1, T> operator%(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar % v.x);
	}

	template<typename T>
	vec<1, T> operator%(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x % v2.x);
	}

	template<typename T>
	vec<1, T> operator&(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x & scalar);
	}

	template<typename T>
	vec<1, T> operator&(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar & v.x);
	}

	template<typename T>
	vec<1, T> operator&(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x & v2.x);
	}

	template<typename T>
	vec<1, T> operator|(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x | scalar);
	}

	template<typename T>
	vec<1, T> operator|(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar | v.x);
	}

	template<typename T>
	vec<1, T> operator|(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x | v2.x);
	}

	template<typename T>
	vec<1, T> operator^(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			v.x ^ scalar);
	}

	template<typename T>
	vec<1, T> operator^(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			scalar ^ v.x);
	}

	template<typename T>
	vec<1, T> operator^(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			v1.x ^ v2.x);
	}

	template<typename T>
	vec<1, T> operator<<(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			static_cast<T>(v.x << scalar));
	}

	template<typename T>
	vec<1, T> operator<<(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			static_cast<T>(scalar << v.x));
	}

	template<typename T>
	vec<1, T> operator<<(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			static_cast<T>(v1.x << v2.x));
	}

	template<typename T>
	vec<1, T> operator>>(vec<1, T> const& v, T scalar)
	{
		return vec<1, T>(
			static_cast<T>(v.x >> scalar));
	}

	template<typename T>
	vec<1, T> operator>>(T scalar, vec<1, T> const& v)
	{
		return vec<1, T>(
			static_cast<T>(scalar >> v.x));
	}

	template<typename T>
	vec<1, T> operator>>(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return vec<1, T>(
			static_cast<T>(v1.x >> v2.x));
	}

	template<typename T>
	vec<1, T> operator~(vec<1, T> const& v)
	{
		return vec<1, T>(
			~v.x);
	}

	// -- Boolean operators --

	template<typename T>
	bool operator==(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x);
	}

	template<typename T>
	bool operator!=(vec<1, T> const& v1, vec<1, T> const& v2)
	{
		return !(v1 == v2);
	}

} //namespace math
