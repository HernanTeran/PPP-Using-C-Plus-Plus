// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Expression
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
#ifndef EXPRESSION_H
#define EXPRESSION_H
#pragma once

#include "Rational.h"

#include <iostream>

namespace Algebra
{
	class Expression
	{
	public:
		// exception class
		class Invalid_Operator{};

		// constructors
		Expression() = default;
		Expression(const Rational& rn1_, const Rational& rn2_, char oper_);

	public:
		// public member functions

		// nonmodifying operations
		Rational get_rn1() const { return rn1; }
		Rational get_rn2() const { return rn2; }
		char get_operator() const { return oper; }
		Rational compute() const;

		// modifying operation
		void set_operator(char oper_);

	private:
		Rational rn1, rn2;
		char oper{ '0' };
	};

	// helper functions
	bool is_valid_operator(char oper);

	std::istream& operator>>(std::istream& is, Expression& expression);
	std::ostream& operator<<(std::ostream& os, const Expression& expression);
}

#endif // EXPRESSION_H
