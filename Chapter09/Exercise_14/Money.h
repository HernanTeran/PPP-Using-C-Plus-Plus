#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

namespace Currency
{
	class Money
	{
	public:
		// exception class
		class Invalid_amount{};

		// default constructor
		Money();

		// constructor
		Money(long int cents_);

		// nonmodifying operation
		long int get_cents() const { return cents; }
		double get_monetary_value() const { return (double)cents / 100; }
		double get_rounded_value() const;

	private:
		long int cents{ 0 };
	};

	// helper functions
	bool is_valid_amount(long int cents_);

	std::ostream& operator<<(std::ostream& os, const Money& money);
	std::istream& operator>>(std::istream& is, Money& money);
}
