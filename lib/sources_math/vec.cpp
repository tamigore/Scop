
#pragma once

#include "../includes/vec.hpp"

namespace math
{
	template<int L, typename T>
	struct compute_vec_add {};

	template<int L, typename T>
	struct compute_vec_sub {};

	template<int L, typename T>
	struct compute_vec_mul {};

	template<int L, typename T>
	struct compute_vec_div {};

	template<int L, typename T>
	struct compute_vec_mod {};

	template<int L, typename T>
	struct compute_splat {};

	template<int L, typename T>
	struct compute_vec_and {};

	template<int L, typename T>
	struct compute_vec_or {};

	template<int L, typename T>
	struct compute_vec_xor {};

	template<int L, typename T>
	struct compute_vec_shift_left {};

	template<int L, typename T>
	struct compute_vec_shift_right {};

	template<int L, typename T>
	struct compute_vec_equal {};

	template<int L, typename T>
	struct compute_vec_nequal {};

	template<int L, typename T>
	struct compute_vec_bitwise_not {};

	template<int L, typename T>
	struct compute_vec_add<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return detail::functor2<vec, L, T>::call(std::plus<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_sub<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return detail::functor2<vec, L, T>::call(std::minus<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_mul<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return detail::functor2<vec, L, T>::call(std::multiplies<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_div<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return detail::functor2<vec, L, T>::call(std::divides<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_mod<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return detail::functor2<vec, L, T>::call(std::modulus<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_and<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			vec<L, T> v(a);
			for (int i = 0; i < L; ++i)
				v[i] &= static_cast<T>(b[i]);
			return v;
		}
	};

	template<int L, typename T>
	struct compute_vec_or<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			vec<L, T> v(a);
			for (int i = 0; i < L; ++i)
				v[i] |= static_cast<T>(b[i]);
			return v;
		}
	};

	template<int L, typename T>
	struct compute_vec_xor<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			vec<L, T> v(a);
			for (int i = 0; i < L; ++i)
				v[i] ^= static_cast<T>(b[i]);
			return v;
		}
	};

	template<int L, typename T>
	struct compute_vec_shift_left<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			vec<L, T> v(a);
			for (int i = 0; i < L; ++i)
				v[i] <<= static_cast<T>(b[i]);
			return v;
		}
	};

	template<int L, typename T>
	struct compute_vec_shift_right<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			vec<L, T> v(a);
			for (int i = 0; i < L; ++i)
				v[i] >>= static_cast<T>(b[i]);
			return v;
		}
	};
	
	template<int L, typename T>
	struct compute_vec_equal<L, T>
	{
		static bool call(vec<L, T> const& v1, vec<L, T> const& v2)
		{
			bool b = true;
			for (int i = 0; i < L; ++i)
				b = b && detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x);
			return b;
		}
	};

	template<int L, typename T>
	struct compute_vec_nequal<L, T>
	{
		static bool call(vec<4, T> const& v1, vec<4, T> const& v2)
		{
			return !compute_vec_equal<L, T, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(v1, v2);
		}
	};

	template<int L, typename T>
	struct compute_vec_bitwise_not<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a)
		{
			vec<L, T> v(a);
			for (int i = 0; i < L; ++i)
				v[i] = ~v[i];
			return v;
		}
	};

} //namespace math
