#include "../includes/vec3.hpp"

namespace math
{
	// -- Implicit basic constructors --

	template<typename T>
	vec<3, T>::vec(): x(0), y(0), z(0)
	{}

	template<typename T>
	vec<3, T>::vec(vec<3, T> const& v): x(v.x), y(v.y), z(v.z)
	{}

	template<typename T>
	vec<3, T>::vec(vec<3, T> const& v): x(v.x), y(v.y), z(v.z)
	{}

	// -- Explicit basic constructors --

	template<typename T>
	vec<3, T>::vec(T scalar): x(scalar), y(scalar), z(scalar)
	{}

	template <typename T>
	vec<3, T>::vec(T _x, T _y, T _z): x(_x), y(_y), z(_z)
	{}

	// -- Conversion scalar constructors --

	template<typename T>
	template<typename U>
	vec<3, T>::vec(vec<1, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.x))
		, z(static_cast<T>(v.x))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(X _x, Y _y, Z _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(vec<1, X> const& _x, Y _y, Z _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(X _x, vec<1, Y> const& _y, Z _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, Z _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(X _x, Y _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z.x))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(vec<1, X> const& _x, Y _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z.x))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(X _x, vec<1, Y> const& _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z.x))
	{}

	template<typename T>
	template<typename X, typename Y, typename Z>
	vec<3, T>::vec(vec<1, X> const& _x, vec<1, Y> const& _y, vec<1, Z> const& _z)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_y.x))
		, z(static_cast<T>(_z.x))
	{}

	// -- Conversion vector constructors --

	template<typename T>
	template<typename A>
	vec<3, T>::vec(vec<2, A> const& _xy, B _z)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_z))
	{}

	template<typename T>
	template<typename A>
	vec<3, T>::vec(vec<2, A> const& _xy, vec<1, B> const& _z)
		: x(static_cast<T>(_xy.x))
		, y(static_cast<T>(_xy.y))
		, z(static_cast<T>(_z.x))
	{}

	template<typename T>
	template<typename A>
	vec<3, T>::vec(A _x, vec<2, B> const& _yz)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_yz.x))
		, z(static_cast<T>(_yz.y))
	{}

	template<typename T>
	template<typename A>
	vec<3, T>::vec(vec<1, A> const& _x, vec<2, B> const& _yz)
		: x(static_cast<T>(_x.x))
		, y(static_cast<T>(_yz.x))
		, z(static_cast<T>(_yz.y))
	{}

	template<typename T>
	template<typename Uualifier P>
	vec<3, T>::vec(vec<3, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
	{}

	template<typename T>
	template<typename Uualifier P>
	vec<3, T>::vec(vec<4, U> const& v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
	{}

	// -- Component accesses --

	template<typename T>
	T & vec<3, T>::operator[](typename vec<3, T>::length_type i)
	{
		GLM_ASSERT_LENGTH(i, this->length());
		switch(i)
		{
		default:
			case 0:
		return x;
			case 1:
		return y;
			case 2:
		return z;
		}
	}

	template<typename T>
	T const& vec<3, T>::operator[](typename vec<3, T>::length_type i) const
	{
		GLM_ASSERT_LENGTH(i, this->length());
		switch(i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}
	}

	// -- Unary arithmetic operators --

#	if GLM_CONFIG_DEFAULTED_FUNCTIONS == GLM_DISABLE
		template<typename T>
		vec<3, T>& vec<3, T>::operator=(vec<3, T> const& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return *this;
		}
#	endif

	template<typename T>
	template<typename U>
	vec<3, T>& vec<3, T>::operator=(vec<3, U> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		return *this;
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator+=(U scalar)
	{
		return (*this = detail::compute_vec_add<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator+=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_add<3, T, detail::is_aligned<Q>::value>::call(*this, vec<1, T>(v.x)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator+=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_add<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator-=(U scalar)
	{
		return (*this = detail::compute_vec_sub<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator-=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_sub<3, T, detail::is_aligned<Q>::value>::call(*this, vec<1, T>(v.x)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator-=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_sub<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator*=(U scalar)
	{
		return (*this = detail::compute_vec_mul<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(static_cast<T>(scalar))));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator*=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_mul<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v.x)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator*=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_mul<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator/=(U v)
	{
		return (*this = detail::compute_vec_div<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator/=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_div<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v.x)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator/=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_div<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	// -- Increment and decrement operators --

	template<typename T>
	vec<3, T> & vec<3, T>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template<typename T>
	vec<3, T> & vec<3, T>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template<typename T>
	vec<3, T> vec<3, T>::operator++(int)
	{
		vec<3, T> Result(*this);
		++*this;
		return Result;
	}

	template<typename T>
	vec<3, T> vec<3, T>::operator--(int)
	{
		vec<3, T> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary bit operators --

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator%=(U scalar)
	{
		return (*this = detail::compute_vec_mod<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator%=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_mod<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator%=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_mod<3, T, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator&=(U scalar)
	{
		return (*this = detail::compute_vec_and<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator&=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_and<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator&=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_and<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator|=(U scalar)
	{
		return (*this = detail::compute_vec_or<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator|=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_or<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator|=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_or<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator^=(U scalar)
	{
		return (*this = detail::compute_vec_xor<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator^=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_xor<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v.x)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator^=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_xor<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator<<=(U scalar)
	{
		return (*this = detail::compute_vec_shift_left<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator<<=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_shift_left<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<1, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator<<=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_shift_left<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator>>=(U scalar)
	{
		return (*this = detail::compute_vec_shift_right<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(scalar)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator>>=(vec<1, U> const& v)
	{
		return (*this = detail::compute_vec_shift_right<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));
	}

	template<typename T>
	template<typename U>
	vec<3, T> & vec<3, T>::operator>>=(vec<3, U> const& v)
	{
		return (*this = detail::compute_vec_shift_right<3, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<3, T>(v)));

	}

	// -- Unary arithmetic operators --

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v)
	{
		return v;
	}

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v)
	{
		return vec<3, T>(0) -= v;
	}

	// -- Binary arithmetic operators --

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) += scalar;
	}

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v1, vec<1, T> const& v2)
	{
		return vec<3, T>(v1) += v2;
	}

	template<typename T>
	vec<3, T> operator+(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(v) += scalar;
	}

	template<typename T>
	vec<3, T> operator+(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) += v;
	}

	template<typename T>
	vec<3, T> operator+(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) += v2;
	}

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) -= scalar;
	}

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) -= scalar.x;
	}

	template<typename T>
	vec<3, T> operator-(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) -= v;
	}

	template<typename T>
	vec<3, T> operator-(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) -= v;
	}

	template<typename T>
	vec<3, T> operator-(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) -= v2;
	}

	template<typename T>
	vec<3, T> operator*(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) *= scalar;
	}

	template<typename T>
	vec<3, T> operator*(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) *= scalar.x;
	}

	template<typename T>
	vec<3, T> operator*(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(v) *= scalar;
	}

	template<typename T>
	vec<3, T> operator*(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(v) *= scalar.x;
	}

	template<typename T>
	vec<3, T> operator*(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) *= v2;

	}

	template<typename T>
	vec<3, T> operator/(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) /= scalar;
	}

	template<typename T>
	vec<3, T> operator/(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) /= scalar.x;
	}

	template<typename T>
	vec<3, T> operator/(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) /= v;
	}

	template<typename T>
	vec<3, T> operator/(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) /= v;
	}

	template<typename T>
	vec<3, T> operator/(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) /= v2;
	}

	// -- Binary bit operators --

	template<typename T>
	vec<3, T> operator%(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) %= scalar;
	}

	template<typename T>
	vec<3, T> operator%(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) %= scalar.x;
	}

	template<typename T>
	vec<3, T> operator%(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) %= v;
	}

	template<typename T>
	vec<3, T> operator%(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar.x) %= v;
	}

	template<typename T>
	vec<3, T> operator%(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) %= v2;
	}

	template<typename T>
	vec<3, T> operator&(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) &= scalar;
	}

	template<typename T>
	vec<3, T> operator&(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) &= scalar.x;
	}

	template<typename T>
	vec<3, T> operator&(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) &= v;
	}

	template<typename T>
	vec<3, T> operator&(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar.x) &= v;
	}

	template<typename T>
	vec<3, T> operator&(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) &= v2;
	}

	template<typename T>
	vec<3, T> operator|(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) |= scalar;
	}

	template<typename T>
	vec<3, T> operator|(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) |= scalar.x;
	}

	template<typename T>
	vec<3, T> operator|(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) |= v;
	}

	template<typename T>
	vec<3, T> operator|(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar.x) |= v;
	}

	template<typename T>
	vec<3, T> operator|(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) |= v2;
	}

	template<typename T>
	vec<3, T> operator^(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) ^= scalar;
	}

	template<typename T>
	vec<3, T> operator^(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) ^= scalar.x;
	}

	template<typename T>
	vec<3, T> operator^(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) ^= v;
	}

	template<typename T>
	vec<3, T> operator^(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar.x) ^= v;
	}

	template<typename T>
	vec<3, T> operator^(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) ^= v2;
	}

	template<typename T>
	vec<3, T> operator<<(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) <<= scalar;
	}

	template<typename T>
	vec<3, T> operator<<(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) <<= scalar.x;
	}

	template<typename T>
	vec<3, T> operator<<(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) << v;
	}

	template<typename T>
	vec<3, T> operator<<(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar.x) << v;
	}

	template<typename T>
	vec<3, T> operator<<(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) <<= v2;
	}

	template<typename T>
	vec<3, T> operator>>(vec<3, T> const& v, T scalar)
	{
		return vec<3, T>(v) >>= scalar;
	}

	template<typename T>
	vec<3, T> operator>>(vec<3, T> const& v, vec<1, T> const& scalar)
	{
		return vec<3, T>(v) >>= scalar.x;
	}

	template<typename T>
	vec<3, T> operator>>(T scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar) >>= v;
	}

	template<typename T>
	vec<3, T> operator>>(vec<1, T> const& scalar, vec<3, T> const& v)
	{
		return vec<3, T>(scalar.x) >>= v;
	}

	template<typename T>
	vec<3, T> operator>>(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return vec<3, T>(v1) >>= v2;
	}

	template<typename T>
	vec<3, T> operator~(vec<3, T> const& v)
	{
		return vec<3, T>(
			~v.x,
			~v.y,
			~v.z);
	}

	// -- Boolean operators --

	template<typename T>
	bool operator==(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.y, v2.y) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.z, v2.z);
	}

	template<typename T>
	bool operator!=(vec<3, T> const& v1, vec<3, T> const& v2)
	{
		return !(v1 == v2);
	}

	template<qualifier Q>
	vec<3, bool> operator&&(vec<3, bool> const& v1, vec<3, bool> const& v2)
	{
		return vec<3, bool>(v1.x && v2.x, v1.y && v2.y, v1.z && v2.z);
	}

	template<qualifier Q>
	vec<3, bool> operator||(vec<3, bool> const& v1, vec<3, bool> const& v2)
	{
		return vec<3, bool>(v1.x || v2.x, v1.y || v2.y, v1.z || v2.z);
	}
} //namespace math
