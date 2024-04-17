#pragma once

#include "constants.hpp"
#include "matrix_transform.hpp"
#include "vector_relational.hpp"
#include "quaternion_common.hpp"
#include "quaternion_float.hpp"
#include "quaternion_float_precision.hpp"
#include "quaternion_double.hpp"
#include "quaternion_double_precision.hpp"
#include "quaternion_relational.hpp"
#include "quaternion_geometric.hpp"
#include "quaternion_trigonometric.hpp"
#include "quaternion_transform.hpp"
#include "type_mat3x3.hpp"
#include "type_mat4x4.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"

namespace math
{
	/// Returns euler angles, pitch as x, yaw as y, roll as z.
	/// The result is expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	vec<3, T> eulerAngles(qua<T> const& x);

	/// Returns roll value of euler angles expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	T roll(qua<T> const& x);

	/// Returns pitch value of euler angles expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	T pitch(qua<T> const& x);

	/// Returns yaw value of euler angles expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	T yaw(qua<T> const& x);

	/// Converts a quaternion to a 3 * 3 matrix.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	mat<3, 3, T> mat3_cast(qua<T> const& x);

	/// Converts a quaternion to a 4 * 4 matrix.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	mat<4, 4, T> mat4_cast(qua<T> const& x);

	/// Converts a pure rotation 3 * 3 matrix to a quaternion.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	qua<T> quat_cast(mat<3, 3, T> const& x);

	/// Converts a pure rotation 4 * 4 matrix to a quaternion.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T>
	qua<T> quat_cast(mat<4, 4, T> const& x);

	/// Returns the component-wise comparison result of x < y.
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_relational
	template<typename T>
	vec<4, bool> lessThan(qua<T> const& x, qua<T> const& y);

	/// Returns the component-wise comparison of result x <= y.
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_relational
	template<typename T>
	vec<4, bool> lessThanEqual(qua<T> const& x, qua<T> const& y);

	/// Returns the component-wise comparison of result x > y.
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_relational
	template<typename T>
	vec<4, bool> greaterThan(qua<T> const& x, qua<T> const& y);

	/// Returns the component-wise comparison of result x >= y.
	///
	/// @tparam T Floating-point scalar types
	/// @tparam Q Value from qualifier enum
	///
	/// @see ext_quaternion_relational
	template<typename T>
	vec<4, bool> greaterThanEqual(qua<T> const& x, qua<T> const& y);

	/// Build a look at quaternion based on the default handedness.
	///
	/// @param direction Desired forward direction. Needs to be normalized.
	/// @param up Up vector, how the camera is oriented. Typically (0, 1, 0).
	template<typename T>
	qua<T> quatLookAt(
		vec<3, T> const& direction,
		vec<3, T> const& up);

	/// Build a right-handed look at quaternion.
	///
	/// @param direction Desired forward direction onto which the -z-axis gets mapped. Needs to be normalized.
	/// @param up Up vector, how the camera is oriented. Typically (0, 1, 0).
	template<typename T>
	qua<T> quatLookAtRH(
		vec<3, T> const& direction,
		vec<3, T> const& up);

	/// Build a left-handed look at quaternion.
	///
	/// @param direction Desired forward direction onto which the +z-axis gets mapped. Needs to be normalized.
	/// @param up Up vector, how the camera is oriented. Typically (0, 1, 0).
	template<typename T>
	qua<T> quatLookAtLH(
		vec<3, T> const& direction,
		vec<3, T> const& up);
} //namespace math
