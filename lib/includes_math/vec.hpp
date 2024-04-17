#pragma once

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
			return math::functor2<vec, L, T>::call(std::plus<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_sub<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return math::functor2<vec, L, T>::call(std::minus<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_mul<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return math::functor2<vec, L, T>::call(std::multiplies<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_div<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return math::functor2<vec, L, T>::call(std::divides<T>(), a, b);
		}
	};

	template<int L, typename T>
	struct compute_vec_mod<L, T>
	{
		static vec<L, T> call(vec<L, T> const& a, vec<L, T> const& b)
		{
			return math::functor2<vec, L, T>::call(std::modulus<T>(), a, b);
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
				b = b && math::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x);
			return b;
		}
	};

	template<int L, typename T>
	struct compute_vec_nequal<L, T>
	{
		static bool call(vec<4, T> const& v1, vec<4, T> const& v2)
		{
			return !compute_vec_equal<L, T, math::is_int<T>::value, sizeof(T) * 8, math::is_aligned<Q>::value>::call(v1, v2);
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

	template<template<int L, typename T> class vec, int L, typename R, typename T>
	struct functor1{};

	template<template<int L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 1, R, T>
	{
		static vec<1, R> call(R (*Func) (T x), vec<1, T> const& v)
		{
			return vec<1, R>(Func(v.x));
		}
	};

	template<template<int L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 2, R, T>
	{
		static vec<2, R> call(R (*Func) (T x), vec<2, T> const& v)
		{
			return vec<2, R>(Func(v.x), Func(v.y));
		}
	};

	template<template<int L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 3, R, T>
	{
		static vec<3, R> call(R (*Func) (T x), vec<3, T> const& v)
		{
			return vec<3, R>(Func(v.x), Func(v.y), Func(v.z));
		}
	};

	template<template<int L, typename T> class vec, typename R, typename T>
	struct functor1<vec, 4, R, T>
	{
		static vec<4, R> call(R (*Func) (T x), vec<4, T> const& v)
		{
			return vec<4, R>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
		}
	};

	template<template<int L, typename T> class vec, int L, typename T>
	struct functor2{};

	template<template<int L, typename T> class vec, typename T>
	struct functor2<vec, 1, T>
	{
		static vec<1, T> call(T (*Func) (T x, T y), vec<1, T> const& a, vec<1, T> const& b)
		{
			return vec<1, T>(Func(a.x, b.x));
		}

		template<typename Fct>
		static vec<1, T> call(Fct Func, vec<1, T> const& a, vec<1, T> const& b)
		{
			return vec<1, T>(Func(a.x, b.x));
		}
	};

	template<template<int L, typename T> class vec, typename T>
	struct functor2<vec, 2, T>
	{
		static vec<2, T> call(T (*Func) (T x, T y), vec<2, T> const& a, vec<2, T> const& b)
		{
			return vec<2, T>(Func(a.x, b.x), Func(a.y, b.y));
		}

		template<typename Fct>
		static vec<2, T> call(Fct Func, vec<2, T> const& a, vec<2, T> const& b)
		{
			return vec<2, T>(Func(a.x, b.x), Func(a.y, b.y));
		}
	};

	template<template<int L, typename T> class vec, typename T>
	struct functor2<vec, 3, T>
	{
		static vec<3, T> call(T (*Func) (T x, T y), vec<3, T> const& a, vec<3, T> const& b)
		{
			return vec<3, T>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z));
		}

		template<class Fct>
		static vec<3, T> call(Fct Func, vec<3, T> const& a, vec<3, T> const& b)
		{
			return vec<3, T>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z));
		}
	};

	template<template<int L, typename T> class vec, typename T>
	struct functor2<vec, 4, T>
	{
		static vec<4, T> call(T (*Func) (T x, T y), vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w));
		}

		template<class Fct>
		static vec<4, T> call(Fct Func, vec<4, T> const& a, vec<4, T> const& b)
		{
			return vec<4, T>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w));
		}
	};

	template<template<int L, typename T> class vec, int L, typename T>
	struct functor2_vec_sca{};

	template<template<int L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 1, T>
	{
		static vec<1, T> call(T (*Func) (T x, T y), vec<1, T> const& a, T b)
		{
			return vec<1, T>(Func(a.x, b));
		}
		template<class Fct>
		static vec<1, T> call(Fct Func, vec<1, T> const& a, T b)
		{
			return vec<1, T>(Func(a.x, b));
		}
	};

	template<template<int L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 2, T>
	{
		static vec<2, T> call(T (*Func) (T x, T y), vec<2, T> const& a, T b)
		{
			return vec<2, T>(Func(a.x, b), Func(a.y, b));
		}

		template<class Fct>
		static vec<2, T> call(Fct Func, vec<2, T> const& a, T b)
		{
			return vec<2, T>(Func(a.x, b), Func(a.y, b));
		}
	};

	template<template<int L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 3, T>
	{
		static vec<3, T> call(T (*Func) (T x, T y), vec<3, T> const& a, T b)
		{
			return vec<3, T>(Func(a.x, b), Func(a.y, b), Func(a.z, b));
		}

		template<class Fct>
		static vec<3, T> call(Fct Func, vec<3, T> const& a, T b)
		{
			return vec<3, T>(Func(a.x, b), Func(a.y, b), Func(a.z, b));
		}
	};

	template<template<int L, typename T> class vec, typename T>
	struct functor2_vec_sca<vec, 4, T>
	{
		static vec<4, T> call(T (*Func) (T x, T y), vec<4, T> const& a, T b)
		{
			return vec<4, T>(Func(a.x, b), Func(a.y, b), Func(a.z, b), Func(a.w, b));
		}
		template<class Fct>
		static vec<4, T> call(Fct Func, vec<4, T> const& a, T b)
		{
			return vec<4, T>(Func(a.x, b), Func(a.y, b), Func(a.z, b), Func(a.w, b));
		}
	};

	template<int L, typename T>
	struct functor2_vec_int {};

	template<typename T>
	struct functor2_vec_int<1, T>
	{
		static vec<1, int> call(int (*Func) (T x, int y), vec<1, T> const& a, vec<1, int> const& b)
		{
			return vec<1, int>(Func(a.x, b.x));
		}

		template<class Fct>
		static vec<1, int> call(Fct Func, vec<1, T> const& a, vec<1, int> const& b)
		{
			return vec<1, int>(Func(a.x, b.x));
		}
	};

	template<typename T>
	struct functor2_vec_int<2, T>
	{
		static vec<2, int> call(int (*Func) (T x, int y), vec<2, T> const& a, vec<2, int> const& b)
		{
			return vec<2, int>(Func(a.x, b.x), Func(a.y, b.y));
		}
		template<class Fct>
		static vec<2, int> call(Fct Func, vec<2, T> const& a, vec<2, int> const& b)
		{
			return vec<2, int>(Func(a.x, b.x), Func(a.y, b.y));
		}
	};

	template<typename T>
	struct functor2_vec_int<3, T>
	{
		static vec<3, int> call(int (*Func) (T x, int y), vec<3, T> const& a, vec<3, int> const& b)
		{
			return vec<3, int>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z));
		}
		template<class Fct>
		static vec<3, int> call(Fct Func, vec<3, T> const& a, vec<3, int> const& b)
		{
			return vec<3, int>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z));
		}
	};

	template<typename T>
	struct functor2_vec_int<4, T>
	{
		static vec<4, int> call(int (*Func) (T x, int y), vec<4, T> const& a, vec<4, int> const& b)
		{
			return vec<4, int>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w));
		}

		template<class Fct>
		static vec<4, int> call(Fct Func, vec<4, T> const& a, vec<4, int> const& b)
		{
			return vec<4, int>(Func(a.x, b.x), Func(a.y, b.y), Func(a.z, b.z), Func(a.w, b.w));
		}
	};
} //namespace math
