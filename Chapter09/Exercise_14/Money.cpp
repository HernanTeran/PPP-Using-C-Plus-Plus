#include "Money.h"

namespace Currency
{
	Money::Money() : cents{0} {}

	Money::Money(long int cents_) : cents{ cents_ }
	{
		if (!is_valid_amount(cents_)) { throw Invalid_amount{}; }
	}

	bool is_valid_amount(long int cents_)
	{
		constexpr long int max_value{ 2147483647 };
		return cents_ >= 0 && cents_ <= max_value;
	}

	std::ostream& operator<<(std::ostream& os, const Money& money)
	{
		return os << "In dollars: $" << money.get_monetary_value() << '\n'
		          << "Rounded: $" << money.get_rounded_value() << '\n';
	}

	std::istream& operator>>(std::istream& is, Money& money)
	{
		std::cout << "Enter a a monetary value in cents:\n";
		long int cents{ 0 };
		is >> cents;

		if (!is)
			// return with original value if is.fail()
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		money = Money{ cents };

		return is;
	}

	double Money::get_rounded_value() const
		// round monetary_value
		// subtract monetary_value from the rounded value
		// then divide that value by 0.1
		// then subtract that value by its rounded counterpart
		// then divide by 10 to get the difference to properly round up or down
		// e.g. 14.56, difference = 0.04 to round up to 14.60
		// return monetary_value - (+/-) rounded_difference
	{
		const double rounded_amount = round(get_monetary_value());
		const double rounded_decimal = (get_monetary_value() - rounded_amount) / 0.1;
		const double rounded_difference = (rounded_decimal - round(rounded_decimal)) / 10;

		return get_monetary_value() - rounded_difference;
	}
}
