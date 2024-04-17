namespace math
{
	template<typename genType>
	genType zero()
	{
		return genType(0);
	}

	template<typename genType>
	genType one()
	{
		return genType(1);
	}

	template<typename genType>
	genType two_pi()
	{
		return genType(6.28318530717958647692528676655900576);
	}

	template<typename genType>
	genType tau()
	{
		return two_pi<genType>();
	}

	template<typename genType>
	genType root_pi()
	{
		return genType(1.772453850905516027);
	}

	template<typename genType>
	genType half_pi()
	{
		return genType(1.57079632679489661923132169163975144);
	}

	template<typename genType>
	genType three_over_two_pi()
	{
		return genType(4.71238898038468985769396507491925432);
	}

	template<typename genType>
	genType quarter_pi()
	{
		return genType(0.785398163397448309615660845819875721);
	}

	template<typename genType>
	genType one_over_pi()
	{
		return genType(0.318309886183790671537767526745028724);
	}

	template<typename genType>
	genType one_over_two_pi()
	{
		return genType(0.159154943091895335768883763372514362);
	}

	template<typename genType>
	genType two_over_pi()
	{
		return genType(0.636619772367581343075535053490057448);
	}

	template<typename genType>
	genType four_over_pi()
	{
		return genType(1.273239544735162686151070106980114898);
	}

	template<typename genType>
	genType two_over_root_pi()
	{
		return genType(1.12837916709551257389615890312154517);
	}

	template<typename genType>
	genType one_over_root_two()
	{
		return genType(0.707106781186547524400844362104849039);
	}

	template<typename genType>
	genType root_half_pi()
	{
		return genType(1.253314137315500251);
	}

	template<typename genType>
	genType root_two_pi()
	{
		return genType(2.506628274631000502);
	}

	template<typename genType>
	genType root_ln_four()
	{
		return genType(1.17741002251547469);
	}

	template<typename genType>
	genType e()
	{
		return genType(2.71828182845904523536);
	}

	template<typename genType>
	genType euler()
	{
		return genType(0.577215664901532860606);
	}

	template<typename genType>
	genType root_two()
	{
		return genType(1.41421356237309504880168872420969808);
	}

	template<typename genType>
	genType root_three()
	{
		return genType(1.73205080756887729352744634150587236);
	}

	template<typename genType>
	genType root_five()
	{
		return genType(2.23606797749978969640917366873127623);
	}

	template<typename genType>
	genType ln_two()
	{
		return genType(0.693147180559945309417232121458176568);
	}

	template<typename genType>
	genType ln_ten()
	{
		return genType(2.30258509299404568401799145468436421);
	}

	template<typename genType>
	genType ln_ln_two()
	{
		return genType(-0.3665129205816643);
	}

	template<typename genType>
	genType third()
	{
		return genType(0.3333333333333333333333333333333333333333);
	}

	template<typename genType>
	genType two_thirds()
	{
		return genType(0.666666666666666666666666666666666666667);
	}

	template<typename genType>
	genType golden_ratio()
	{
		return genType(1.61803398874989484820458683436563811);
	}

} // namespace math
