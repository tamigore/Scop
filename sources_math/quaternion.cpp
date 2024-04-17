#include "../trigonometric.hpp"
#include "../geometric.hpp"
#include "../exponential.hpp"
#include "epsilon.hpp"
#include <limits>

namespace glm
{
	template<typename T>
	vec<3, T> eulerAngles(qua<T> const& x)
	{
		return vec<3, T>(pitch(x), yaw(x), roll(x));
	}

	template<typename T>
	T roll(qua<T> const& q)
	{
		T const y = static_cast<T>(2) * (q.x * q.y + q.w * q.z);
		T const x = q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z;

		if(all(equal(vec<2, T>(x, y), vec<2, T>(0), epsilon<T>())))
			return static_cast<T>(0);

		return static_cast<T>(atan(y, x));
	}

	template<typename T>
	T pitch(qua<T> const& q)
	{
		T const y = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
		T const x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

		if(all(equal(vec<2, T>(x, y), vec<2, T>(0), epsilon<T>())))
			return static_cast<T>(static_cast<T>(2) * atan(q.x, q.w));

		return static_cast<T>(atan(y, x));
	}

	template<typename T>
	T yaw(qua<T> const& q)
	{
		return asin(clamp(static_cast<T>(-2) * (q.x * q.z - q.w * q.y), static_cast<T>(-1), static_cast<T>(1)));
	}

	template<typename T>
	mat<3, 3, T> mat3_cast(qua<T> const& q)
	{
		mat<3, 3, T> Result(T(1));
		T qxx(q.x * q.x);
		T qyy(q.y * q.y);
		T qzz(q.z * q.z);
		T qxz(q.x * q.z);
		T qxy(q.x * q.y);
		T qyz(q.y * q.z);
		T qwx(q.w * q.x);
		T qwy(q.w * q.y);
		T qwz(q.w * q.z);

		Result[0][0] = T(1) - T(2) * (qyy +  qzz);
		Result[0][1] = T(2) * (qxy + qwz);
		Result[0][2] = T(2) * (qxz - qwy);

		Result[1][0] = T(2) * (qxy - qwz);
		Result[1][1] = T(1) - T(2) * (qxx +  qzz);
		Result[1][2] = T(2) * (qyz + qwx);

		Result[2][0] = T(2) * (qxz + qwy);
		Result[2][1] = T(2) * (qyz - qwx);
		Result[2][2] = T(1) - T(2) * (qxx +  qyy);
		return Result;
	}

	template<typename T>
	mat<4, 4, T> mat4_cast(qua<T> const& q)
	{
		return mat<4, 4, T>(mat3_cast(q));
	}

	template<typename T>
	qua<T> quat_cast(mat<3, 3, T> const& m)
	{
		T fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
		T fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
		T fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
		T fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

		int biggestIndex = 0;
		T fourBiggestSquaredMinus1 = fourWSquaredMinus1;
		if(fourXSquaredMinus1 > fourBiggestSquaredMinus1)
		{
			fourBiggestSquaredMinus1 = fourXSquaredMinus1;
			biggestIndex = 1;
		}
		if(fourYSquaredMinus1 > fourBiggestSquaredMinus1)
		{
			fourBiggestSquaredMinus1 = fourYSquaredMinus1;
			biggestIndex = 2;
		}
		if(fourZSquaredMinus1 > fourBiggestSquaredMinus1)
		{
			fourBiggestSquaredMinus1 = fourZSquaredMinus1;
			biggestIndex = 3;
		}

		T biggestVal = sqrt(fourBiggestSquaredMinus1 + static_cast<T>(1)) * static_cast<T>(0.5);
		T mult = static_cast<T>(0.25) / biggestVal;

		switch(biggestIndex)
		{
		case 0:
			return qua<T>::wxyz(biggestVal, (m[1][2] - m[2][1]) * mult, (m[2][0] - m[0][2]) * mult, (m[0][1] - m[1][0]) * mult);
		case 1:
			return qua<T>::wxyz((m[1][2] - m[2][1]) * mult, biggestVal, (m[0][1] + m[1][0]) * mult, (m[2][0] + m[0][2]) * mult);
		case 2:
			return qua<T>::wxyz((m[2][0] - m[0][2]) * mult, (m[0][1] + m[1][0]) * mult, biggestVal, (m[1][2] + m[2][1]) * mult);
		case 3:
			return qua<T>::wxyz((m[0][1] - m[1][0]) * mult, (m[2][0] + m[0][2]) * mult, (m[1][2] + m[2][1]) * mult, biggestVal);
		default:
			assert(false);
			return qua<T>::wxyz(1, 0, 0, 0);
		}
	}

	template<typename T>
	qua<T> quat_cast(mat<4, 4, T> const& m4)
	{
		return quat_cast(mat<3, 3, T>(m4));
	}

	template<typename T>
	vec<4, bool> lessThan(qua<T> const& x, qua<T> const& y)
	{
		vec<4, bool> Result(false, false, false, false);
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] < y[i];
		return Result;
	}

	template<typename T>
	vec<4, bool> lessThanEqual(qua<T> const& x, qua<T> const& y)
	{
		vec<4, bool> Result(false, false, false, false);
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] <= y[i];
		return Result;
	}

	template<typename T>
	vec<4, bool> greaterThan(qua<T> const& x, qua<T> const& y)
	{
		vec<4, bool> Result(false, false, false, false);
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] > y[i];
		return Result;
	}

	template<typename T>
	vec<4, bool> greaterThanEqual(qua<T> const& x, qua<T> const& y)
	{
		vec<4, bool> Result(false, false, false, false);
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] >= y[i];
		return Result;
	}

	template<typename T>
	qua<T> quatLookAt(vec<3, T> const& direction, vec<3, T> const& up)
	{
		return quatLookAtRH(direction, up);
	}

	template<typename T>
	qua<T> quatLookAtRH(vec<3, T> const& direction, vec<3, T> const& up)
	{
		mat<3, 3, T> Result;

		Result[2] = -direction;
		vec<3, T> const& Right = cross(up, Result[2]);
		Result[0] = Right * inversesqrt(max(static_cast<T>(0.00001), dot(Right, Right)));
		Result[1] = cross(Result[2], Result[0]);

		return quat_cast(Result);
	}

	template<typename T>
	qua<T> quatLookAtLH(vec<3, T> const& direction, vec<3, T> const& up)
	{
		mat<3, 3, T> Result;

		Result[2] = direction;
		vec<3, T> const& Right = cross(up, Result[2]);
		Result[0] = Right * inversesqrt(max(static_cast<T>(0.00001), dot(Right, Right)));
		Result[1] = cross(Result[2], Result[0]);

		return quat_cast(Result);
	}
} //namespace math
