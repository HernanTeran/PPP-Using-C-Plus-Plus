// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Quadratic
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 4 Excercise 18
//
// Author: Hernan Teran
// Created: 2021/03/17
//
/*
* Write a program to solve a quadratic equation.
*
* (-b (+/-) sqrt(b^2 -4ac)) / 2a
* ax^2 + bx + c = 0
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Quadratic_Equation.h"

namespace Computation
{
	Quadratic::Quadratic(double a_, double b_, double c_)
		: a{a_}, b{b_}, c{c_}
	{
	}

	double Quadratic::get_pos_ans() const
	{
		return (-1 * b + sqrt(pow(b, 2) - 4 * (a * c))) / (2 * a);
	}

	double Quadratic::get_neg_ans() const
	{
		return (-1 * b - sqrt(pow(b, 2) - 4 * (a * c))) / (2 * a);
	}

	std::ostream& operator<<(std::ostream& os, const Quadratic& equation)
	{
		return os << "Results:\n"
			<< "+\t" << equation.get_pos_ans() << '\n'
			<< "-\t" << equation.get_neg_ans() << '\n';
	}

	std::istream& operator>>(std::istream& is, Quadratic& equation)
	{
		std::cout << "Solve: x = (-b (+/-) sqrt(b^2 - 4ac)) / 2a\n\n"
			      << "Enter a, b, c: ";

		double a{ 0 }, b{ 0 }, c{ 0 };
		is >> a >> b >> c;

		equation = Quadratic{ a, b, c };

		return is;
	}


}
