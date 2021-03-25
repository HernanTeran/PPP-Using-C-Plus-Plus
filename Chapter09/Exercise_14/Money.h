#ifndef MONEY_H
#define MONEY_H
#pragma once

#include <iostream>
#include <string>

namespace Currency
{
	class Money
	{
	public:
		// constant
		static constexpr long int MAX_VAL{ 2147483647 };

		// exception class
		class Invalid_Amount {};

		// constructors
		Money();
		Money(long int cs);

	public:
		// nonmodifying operation
		long int cents() const { return c; }
		double monetary_value() const { return (double)c / 100; }
		double rounded_value() const;

	private:
		long int c{ 0 };
	};

	// helper functions
	bool is_valid_amount(long int cs);
	long int input(std::istream& is, const std::string& prompt);

	std::ostream& operator<<(std::ostream& os, const Money& money);
	std::istream& operator>>(std::istream& is, Money& money);
}

#endif // MONEY_H
