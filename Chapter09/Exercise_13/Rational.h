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
#ifndef RATIONAL_H
#define RATIONAL_H
#pragma once

#include <iostream>

namespace Algebra
{
	class Rational
	{
	public:
		// exception class
		class Invalid_Input {};

		// constructors
		Rational() = default;
		Rational(int num, int den);

		// assignment operator
		Rational& operator=(const Rational& rn)
		{
			numerator = rn.numerator;
			denominator = rn.denominator;
			return *this;
		}

	public:
		// public member functions

		// nonmodifying operations
		int get_numerator() const { return numerator; }
		int get_denominator() const { return denominator; }
		double num_to_double() const { return static_cast<double>(numerator); }
		double den_to_double() const { return static_cast<double>(denominator); }
		double decimal_val() const { return num_to_double() / den_to_double(); }

		// modifying operations
		void set_numerator(int num) { numerator = num; }
		void set_denominator(int den) { denominator = den; }

	private:
		int numerator{ 0 }, denominator{ 0 };
	};

	// helper functions
	bool is_valid_input(int den);
	Rational simplify(Rational& rn);

	std::ostream& operator<<(std::ostream& os, const Rational& rn);
	std::istream& operator>>(std::istream& is, Rational& rn);

	Rational operator+(const Rational& rn1, const Rational& rn2);
	Rational operator-(const Rational& rn1, const Rational& rn2);
	Rational operator*(const Rational& rn1, const Rational& rn2);
	Rational operator/(const Rational& rn1, const Rational& rn2);

	bool operator==(const Rational& rn1, const Rational& rn2);
	bool operator!=(const Rational& rn1, const Rational& rn2);
	bool operator>=(const Rational& rn1, const Rational& rn2);
	bool operator>(const Rational& rn1, const Rational& rn2);
	bool operator<=(const Rational& rn1, const Rational& rn2);
	bool operator<(const Rational& rn1, const Rational& rn2);
}

#endif // RATIONAL_H
