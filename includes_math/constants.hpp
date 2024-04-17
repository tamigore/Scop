#pragma once

namespace math
{

	/// Return 0.
	template<typename T>
	T zero();

	/// Return 1.
	template<typename T>
	T one();

	/// Return pi * 2.
	template<typename T>
	T two_pi();

	/// Return unit-circle circumference, or pi * 2.
	template<typename T>
	T tau();

	/// Return square root of pi.
	template<typename T>
	T root_pi();

	/// Return pi / 2.
	template<typename T>
	T half_pi();

	/// Return pi / 2 * 3.
	template<typename T>
	T three_over_two_pi();

	/// Return pi / 4.
	template<typename T>
	T quarter_pi();

	/// Return 1 / pi.
	template<typename T>
	T one_over_pi();

	/// Return 1 / (pi * 2).
	template<typename T>
	T one_over_two_pi();

	/// Return 2 / pi.
	template<typename T>
	T two_over_pi();

	/// Return 4 / pi.
	template<typename T>
	T four_over_pi();

	/// Return 2 / sqrt(pi).
	template<typename T>
	T two_over_root_pi();

	/// Return 1 / sqrt(2).
	template<typename T>
	T one_over_root_two();

	/// Return sqrt(pi / 2).
	template<typename T>
	T root_half_pi();

	/// Return sqrt(2 * pi).
	template<typename T>
	T root_two_pi();

	/// Return sqrt(ln(4)).
	template<typename T>
	T root_ln_four();

	/// Return e constant.
	template<typename T>
	T e();

	/// Return Euler's constant.
	template<typename T>
	T euler();

	/// Return sqrt(2).
	template<typename T>
	T root_two();

	/// Return sqrt(3).
	template<typename T>
	T root_three();

	/// Return sqrt(5).
	template<typename T>
	T root_five();

	/// Return ln(2).
	template<typename T>
	T ln_two();

	/// Return ln(10).
	template<typename T>
	T ln_ten();

	/// Return ln(ln(2)).
	template<typename T>
	T ln_ln_two();

	/// Return 1 / 3.
	template<typename T>
	T third();

	/// Return 2 / 3.
	template<typename T>
	T two_thirds();

	/// Return the golden ratio constant.
	template<typename T>
	T golden_ratio();

} // namespace math
