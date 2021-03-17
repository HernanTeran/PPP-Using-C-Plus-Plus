// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Calculator
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 4 Excercise 5
//
// Author: Hernan Teran
// Created: 2021/03/17
//
/*
* Write a program that performs a very simple calculator.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef CALCULATOR_H
#define CALCULATOR_H
#pragma once

#include <iostream>
#include <string>

namespace Computation
{
	class Calculator
	{
	public:
		// exception class
		class Invalid_Oper {};

		// constructors
		Calculator() = default;
		Calculator(double oper1_, double oper2_, char arith_oper_);

	public:
		// public member functions
		double get_oper1() const { return oper1; }
		double get_oper2() const { return oper2; }
		char get_operator() const { return arith_operator; }
		double get_sum() const { return oper1 + oper2; }
		double get_difference() const { return oper1 - oper2; }
		double get_product() const { return oper1 * oper2; }
		double get_quotient() const { return oper1 / oper2; }

	private:
		double oper1{ 0 }, oper2{ 0 };
		char arith_operator{ '0' };
	};

	// helper functions
	bool is_valid_oper(char arith_oper);

	std::ostream& operator<<(std::ostream& os, const Calculator& calculation);
	std::istream& operator>>(std::istream& is, Calculator& calculation);
}

#endif // CALCULATOR_H