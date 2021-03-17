// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
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
#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <iostream>
#include <cmath>

namespace Computation
{
	class Quadratic
	{
	public:
		Quadratic() = default;
		Quadratic(double a_, double b_, double c_);

	public:
		double get_a() const { return a; }
		double get_b() const { return b; }
		double get_c() const { return c; }
		double get_pos_ans() const;
		double get_neg_ans() const;

	private:
		double a{ 0 }, b{ 0 }, c{ 0 };
	};

	std::ostream& operator<<(std::ostream& os, const Quadratic& equation);
	std::istream& operator>>(std::istream& is, Quadratic& equation);
}

#endif // QUADRATIC_EQUATION_H