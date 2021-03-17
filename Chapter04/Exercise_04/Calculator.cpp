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
#include "Calculator.h"

namespace Computation
{
	Calculator::Calculator(double oper1_, double oper2_, char arith_oper_)
		: oper1{oper1_}, oper2{oper2_}, arith_operator{arith_oper_}
	{
		if (!is_valid_oper(arith_oper_)) { throw Invalid_Oper{}; }
	}

	bool is_valid_oper(char arith_oper)
	{
		switch (arith_oper)
		{
		case '+': case '-': case '*': case '/':
			break;
		default:
			return false;
		}
		return true;
	}

	std::ostream& operator<<(std::ostream& os, const Calculator& calculation)
	{
		switch (calculation.get_operator())
		{
		case '+':
			os << "The sum of " << calculation.get_oper1() << " and " << calculation.get_oper2()
				<< " is " << calculation.get_sum() << ".\n";
			break;
		case '-':
			os << "The difference of " << calculation.get_oper1() << " and " << calculation.get_oper2()
				<< " is " << calculation.get_difference() << ".\n";
			break;
		case '*':
			os << "The product of " << calculation.get_oper1() << " and " << calculation.get_oper2()
				<< " is " << calculation.get_product() << ".\n";
			break;
		case '/':
			os << "The quotient of " << calculation.get_oper1() << " and " << calculation.get_oper2()
				<< " is " << calculation.get_quotient() << ".\n";
			break;
		default:
			os << "Invalid operator.\n";
			break;
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Calculator& calculation)
	{
		using std::cout;

		double oper1{ 0 }, oper2{ 0 };
		char arith_operator{ '0' };

		cout << "Enter an expression (operand operand operator):" << std::endl;
		is >> oper1 >> oper2 >> arith_operator;

		calculation = Calculator{ oper1, oper2, arith_operator };

		return is;
	}
}