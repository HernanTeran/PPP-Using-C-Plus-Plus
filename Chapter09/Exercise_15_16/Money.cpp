#include "Money.h"

namespace Currency
{
	// constructors ------------------------------------------------------------------------------------

	Money::Money() : cents{ 0 }, currency{ 0 }, valid_symbol{ Symbols::USD } {}

	Money::Money(long int cents_, std::string symbol_, double currency_) 
		: cents{ cents_ }, symbol {symbol_}, currency{ currency_ }, valid_symbol{Symbols::USD}
	{
		if (!is_valid_amount(cents_, symbol_, currency_)) { throw Invalid_amount{}; }

		Conversions conversions;
		if (symbol_ == conversions.symbols.at(1)) { valid_symbol = Symbols::DKK; }
		if (symbol_ == conversions.symbols.at(2)) { valid_symbol = Symbols::SOL; }
	}

	// invariant ---------------------------------------------------------------------------------------

	bool is_valid_amount(long int cents_, const std::string& symbol_, double currency_)
	{
		if (cents_ < 0 || cents_ > Money::max_value) { return false; }

		Conversions conversions;
		auto it = std::find(conversions.symbols.begin(), conversions.symbols.end(), symbol_);
		if (it == conversions.symbols.end()) { return false; }

		if (currency_ < 0 || (long int)currency_ > Money::max_value) { return false; }

		return true;
	}

	// operators ---------------------------------------------------------------------------------------

	std::ostream& operator<<(std::ostream& os, const Money& money)
	{
		Conversions conversions;

		os << money.get_symbol() << money.get_monetary_value() << '\n'
			<< money.get_symbol() << " rounded: " << money.get_rounded_value(money.get_monetary_value()) << "\n\n";

		switch (money.get_valid_symbol())
		{
		case Symbols::USD:
			os << "$ -> kr." << money.usd_to_dkk(conversions) << '\n'
				<< "$ -> S/" << money.usd_to_soles(conversions) << "\n\n";
			break;
		case Symbols::DKK:
			os << "kr. -> $" << money.dkk_to_usd(conversions) << '\n'
				<< "kr. -> S/" << money.dkk_to_soles(conversions) << "\n\n";
			break;
		case Symbols::SOL:
			os << "S/ -> $" << money.soles_to_usd(conversions) << '\n'
				<< "S/ -> kr." << money.soles_to_dkk(conversions) << "\n\n";
			break;
		default:
			std::cerr << "error\n";
			break;
		}

		return os;
	}

	std::istream& operator>>(std::istream& is, Money& money)
	{
		std::cout << "{Enter a monetary value in cents}\n"
			<< "{Followed by a currency value to convert}:\n";
		long int cents{ 0 };
		std::string symbol;
		double currency{ 0 };
		is >> cents >> symbol >> currency;

		if (!is)
			// return with previous value if is.fail()
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		money = Money{ cents, symbol, currency };

		return is;
	}

	// helper function ---------------------------------------------------------------------------------------

	double Money::get_rounded_value(double value) const
		// round monetary_value
		// subtract monetary_value from the rounded value
		// then divide that value by 0.1
		// then subtract that value by its rounded counterpart
		// then divide by 10 to get the difference to properly round up or down
		// e.g. 14.56, difference = 0.04 to round up to 14.60
		// return monetary_value - (+/-) rounded_difference
	{
		const double rounded_amount = round(value);
		const double rounded_decimal = (value - rounded_amount) / 0.1;
		const double rounded_difference = (rounded_decimal - round(rounded_decimal)) / 10;

		return value - rounded_difference;
	}
}
