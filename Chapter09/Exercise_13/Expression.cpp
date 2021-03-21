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
#include "Expression.h"

using namespace std;

namespace Algebra
{
	Expression::Expression(const Rational& rn1_, const Rational& rn2_, char oper_)
		: rn1{ rn1_ }, rn2{ rn2_ }, oper{ oper_ }
	{
		if (!is_valid_operator(oper_)) { throw Invalid_Operator{}; }
	}

	bool is_valid_operator(char oper)
	{
		switch (oper)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			break;
		default:
			return false;
		}
		return true;
	}

	void Expression::set_operator(char oper_)
	{
		if (!is_valid_operator(oper_)) { return; }
		oper = oper_;
	}

	Rational Expression::compute() const
	{
		Rational result;

		switch (oper)
		{
		case '+':
			result = rn1 + rn2;
			break;
		case '-':
			result = rn1 - rn2;
			break;
		case '*':
			result = rn1 * rn2;
			break;
		case '/':
			result = rn1 / rn2;
			break;
		default:
			break;
		}
		return result;
	}

	istream& operator>>(istream& is, Expression& expression)
	{
		Rational rn1;
		is >> rn1;

		cout << "\n[Input + - * /]: ";
		char oper{ '0' };
		is >> oper;

		if (!is || is.eof() || !is_valid_operator(oper))
		{
			is.clear();
			throw Expression::Invalid_Operator{};
		}

		cout << '\n';

		Rational rn2;
		is >> rn2;

		cout << '\n';

		expression = Expression{ rn1, rn2, oper };

		return is;
	}

	ostream& operator<<(ostream& os, const Expression& expression)
	{
		return os << "[Exact Form]: " << expression.get_rn1() << ' ' 
			<< expression.get_operator() << ' ' << expression.get_rn2() << " = " << expression.compute()
			<< "\n[Decimal Form]: " << expression.compute().decimal_val() << '\n';
	}
}
