#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

namespace Currency
{
	struct Conversions
	{
		const double danish_kroner{ 6.13 };
		const double peruvian_soles{ 3.65 };
		const double usd{ 1 };
		const double dkk_to_usd{ 0.16 };
		const double soles_to_usd{ 0.27 };
		const double soles_to_dkk{ 1.68 };
		const double dkk_to_soles{ 0.60 };
		std::vector<std::string> symbols{ "USD", "DKK", "SOL" };
	};

	enum class Symbols { USD, DKK, SOL };

	class Money
	{
	public:
		// static value used to establish invariant
		static constexpr long int max_value{ 999999 };

		// exception class
		class Invalid_amount {};

		// default constructor
		Money();

		// constructor
		Money(long int cents_, std::string symbol_, double currency_);

		// nonmodifying operations
		long int get_cents() const { return cents; }
		std::string get_symbol() const { return symbol; }
		double get_currency() const { return currency; }
		Symbols get_valid_symbol() const { return valid_symbol; }

		// rounding
		double get_monetary_value() const { return (double)cents / 100; }
		double get_rounded_value(double value) const;

		// conversions
		double usd_to_dkk(const Conversions conversions) const
		{ 
			const double conversion = currency * conversions.danish_kroner;
			return get_rounded_value(conversion); 
		}

		double usd_to_soles(const Conversions conversions) const
		{ 
			const double conversion = currency * conversions.peruvian_soles; 
			return get_rounded_value(conversion);
		}

		double dkk_to_usd(const Conversions conversions) const
		{
			const double conversion = currency * conversions.dkk_to_usd;
			return get_rounded_value(conversion);
		}

		double dkk_to_soles(const Conversions conversions) const
		{
			const double conversion = currency * conversions.dkk_to_soles;
			return get_rounded_value(conversion);
		}

		double soles_to_dkk(const Conversions conversions) const
		{
			const double conversion = currency * conversions.soles_to_dkk;
			return get_rounded_value(conversion);
		}

		double soles_to_usd(const Conversions conversions) const
		{
			const double conversion = currency * conversions.soles_to_usd;
			return get_rounded_value(conversion);
		}

	private:
		long int cents{ 0 };
		double currency{ 0 };
		std::string symbol;
		Symbols valid_symbol{ Symbols::USD };
	};

	// helper functions
	bool is_valid_amount(long int cents_, const std::string& symbol_, double currency_);

	std::ostream& operator<<(std::ostream& os, const Money& money);
	std::istream& operator>>(std::istream& is, Money& money);
}
