// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Rational
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Excercise 13
//
// Author: Hernan Teran
// Created: 2021/03/21
//
/*
* Design and implement a rational number class, Rational.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Rational.h"

using namespace std;

namespace Algebra
{
	Rational::Rational(int num, int den) : numerator{ num }, denominator{ den }
	{
		if (!is_valid_input(den)) { throw Invalid_Input{}; }
	}

	bool is_valid_input(int den)
	{
		if (den == 0) { return false; }
		return true;
	}

	Rational simplify(Rational& rn)
		// use the modulo operator to find common integer to simplify by
	{
		constexpr int MAX_DIVISOR{ 100 };

		for (int i{ 2 }; i != MAX_DIVISOR; ++i)
		{
			if (rn.get_numerator() % i == 0 && rn.get_denominator() % i == 0)
			{
				rn.set_numerator(rn.get_numerator() / i);
				rn.set_denominator(rn.get_denominator() / i);
			}
		}

		return rn;
	}

	ostream& operator<<(ostream& os, const Rational& rn)
	{
		if (rn.get_denominator() == 1)
			return os << rn.get_numerator();
		if (rn.get_numerator() == 0)
			return os << rn.get_numerator();
		return os << rn.get_numerator() << '/' << rn.get_denominator();
	}

	istream& operator>>(istream& is, Rational& rn)
	{
		cout << "[Input a rational number: numerator/denominator]\n\n"
		     << "[Numerator]: ";
		int num{ 0 };
		is >> num;

		if (is.eof())
		{
			is.clear();
			throw Rational::Invalid_Input{};
		}

		if (!is)
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			throw Rational::Invalid_Input{};
		}

		cout << "[Denominator]: ";
		int den{ 0 };
		is >> den;

		if (is.eof())
		{
			is.clear();
			throw Rational::Invalid_Input{};
		}

		if (!is || den == 0)
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			throw Rational::Invalid_Input{};
		}

		rn = Rational{ num, den };

		return is;
	}

	Rational operator+(const Rational& rn1, const Rational& rn2)
		// if the denominators are not equal then:
		// multiply each numerator by the other rational number's denominator
		// then add the numerators and return
	{
		int num{ 0 };

		if (rn1.get_denominator() == rn2.get_denominator())
			// simply add numerators and return
		{
			num = static_cast<int>(rn1.num_to_double() + rn2.num_to_double());
			return simplify(Rational{ num, rn1.get_denominator() });
		}

		num = static_cast<int>(rn1.num_to_double() * rn2.den_to_double());
		int num2 = static_cast<int>(rn2.num_to_double() * rn1.den_to_double());
		num += num2;

		int den = static_cast<int>(rn1.den_to_double() * rn2.den_to_double());

		if (num < 0 && den < 0)
		{
			num = abs(num);
			den = abs(den);
		}

		return simplify(Rational{ num, den });
	}

	Rational operator-(const Rational& rn1, const Rational& rn2)
		// if the denominators are not equal then:
		// multiply each numerator by the other rational number's denominator
		// then subtract the numerators and return
	{
		int num{ 0 };

		if (rn1.get_denominator() == rn2.get_denominator())
			// simply subtract numerators and return
		{
			num = static_cast<int>(rn1.num_to_double() - rn2.num_to_double());
			return simplify(Rational{ num, rn1.get_denominator() });
		}

		num = static_cast<int>(rn1.num_to_double() * rn2.den_to_double());
		int num2 = static_cast<int>(rn2.num_to_double() * rn1.den_to_double());
		num -= num2;

		int den = static_cast<int>(rn1.den_to_double() * rn2.den_to_double());

		if (num < 0 && den < 0)
		{
			num = abs(num);
			den = abs(den);
		}

		return simplify(Rational{ num, den });
	}

	Rational operator*(const Rational& rn1, const Rational& rn2)
		// multiply straight across
	{
		int num = static_cast<int>(rn1.num_to_double() * rn2.num_to_double());
		int den = static_cast<int>(rn1.den_to_double() * rn2.den_to_double());

		return simplify(Rational{ num, den });
	}

	Rational operator/(const Rational& rn1, const Rational& rn2)
		// multiply by reciprocal
	{
		int num = static_cast<int>(rn1.num_to_double() * rn2.den_to_double());
		int den = static_cast<int>(rn1.den_to_double() * rn2.num_to_double());

		return simplify(Rational{ num, den });
	}

	bool operator==(const Rational& rn1, const Rational& rn2)
	{
		return (rn1.num_to_double() / rn1.den_to_double()) == (rn2.num_to_double() / rn2.den_to_double());
	}

	bool operator!=(const Rational& rn1, const Rational& rn2)
	{
		return (rn1.num_to_double() / rn1.den_to_double()) != (rn2.num_to_double() / rn2.den_to_double());
	}

	bool operator>=(const Rational& rn1, const Rational& rn2)
	{
		return (rn1.num_to_double() / rn1.den_to_double()) >= (rn2.num_to_double() / rn2.den_to_double());
	}

	bool operator>(const Rational& rn1, const Rational& rn2)
	{
		return (rn1.num_to_double() / rn1.den_to_double()) > (rn2.num_to_double() / rn2.den_to_double());
	}

	bool operator<=(const Rational& rn1, const Rational& rn2)
	{
		return (rn1.num_to_double() / rn1.den_to_double()) <= (rn2.num_to_double() / rn2.den_to_double());
	}

	bool operator<(const Rational& rn1, const Rational& rn2)
	{
		return (rn1.num_to_double() / rn1.den_to_double()) < (rn2.num_to_double() / rn2.den_to_double());
	}
}
