#include "Money.h"

using namespace std;

namespace Currency
{
	Money::Money() : c{0}
	{
	}

	Money::Money(long int cs) : c{cs}
	{
		if (!is_valid_amount(cs)) { throw Invalid_Amount{}; }
	}

	bool is_valid_amount(long int cs)
	{
		if (cs < 0 && cs >= Money::MAX_VAL) { return false; }
		return true;
	}

	double Money::rounded_value() const
		// round monetary_value
		// subtract monetary_value from the rounded value
		// then divide that value by 0.1
		// then subtract that value by its rounded counterpart
		// then divide by 10 to get the difference to properly round up or down
		// e.g. 14.56, difference = 0.04 to round up to 14.60
		// return monetary_value - (+/-) rounded_difference
	{
		const double rounded_amount = round(monetary_value());
		const double rounded_decimal = (monetary_value() - rounded_amount) / 0.1;
		const double rounded_difference = (rounded_decimal - round(rounded_decimal)) / 10;

		return monetary_value() - rounded_difference;
	}

	ostream& operator<<(ostream& os, const Money& money)
	{
		return os << "Actual: $" << money.monetary_value() << '\n'
			<< "Rounded: $" << money.rounded_value() << "\n\n";
	}

	istream& operator>>(istream& is, Money& money)
	{
		long int cents = input(is, "Enter a monetary value in cents: ");
		money = Money{ cents };
		return is;
	}

	long int input(istream& is, const string& prompt)
	{
		cout << prompt;
		long int c{ 0 };
		is >> c;
		cout << endl;

		if (is.eof())
		{
			is.clear();
			throw Money::Invalid_Amount{};
		}

		if (!is)
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			throw Money::Invalid_Amount{};
		}

		return c;
	}
}
