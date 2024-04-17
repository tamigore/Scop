#pragma once

#include "setup.hpp"

namespace math
{

	template<int L, typename T> struct vec;
	template<int C, int R, typename T> struct mat;
	template<typename T> struct qua;

	struct is_aligned
	{
		static const bool value = false;
	};

	template<int L, typename T, bool is_aligned>
	struct storage
	{
		typedef struct type {
			T data[L];
		} type;
	};

	enum genTypeEnum
	{
		GENTYPE_VEC,
		GENTYPE_MAT,
		GENTYPE_QUAT
	};

	template <typename genType>
	struct genTypeTrait
	{};

	template <int C, int R, typename T>
	struct genTypeTrait<mat<C, R, T> >
	{
		static const genTypeEnum GENTYPE = GENTYPE_MAT;
	};

	template<typename genType, genTypeEnum type>
	struct init_gentype
	{
	};

	template<typename genType>
	struct init_gentype<genType, GENTYPE_QUAT>
	{
		static genType identity()
		{
			return genType(1, 0, 0, 0);
		}
	};

	template<typename genType>
	struct init_gentype<genType, GENTYPE_MAT>
	{
		static genType identity()
		{
			return genType(1);
		}
	};

} //namespace math
