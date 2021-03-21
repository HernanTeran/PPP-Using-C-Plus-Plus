// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Driver
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
#include "Driver.h"

using namespace std;

namespace Algebra
{
	void driver(const string& menu, const string& message, const string& error)
	{
		for (;;)
		{
			try
			{
				cout << menu;

				Expression expression = get_expression();
				print_calc(expression);

				char a = calc_again("\nEnter 'c' to continue...\n"
					                 "Enter any other key to quit...\n");
				if (a != 'c') { break; }

				cout << endl;
			}
			catch (Rational::Invalid_Input)
			{
				cerr << error;
				char a = calc_again("\nEnter 'c' to continue...\n"
					                  "Enter any other key to quit...\n");
				if (a != 'c') { break; }
			}
			catch (Expression::Invalid_Operator)
			{
				cerr << error;
				char a = calc_again("\nEnter 'c' to continue...\n"
					                  "Enter any other key to quit...\n");
				if (a != 'c') { break; }
			}
			catch (...)
			{
				cerr << error;
				char a = calc_again("\nEnter 'c' to continue...\n"
					                "Enter any other key to quit...\n");
				if (a != 'c') { break; }
			}
		}
		cout << message << endl;
	}

	Expression get_expression()
	{
		Expression expression;
		cin >> expression;
		return expression;
	}

	void print_calc(const Expression& expression)
	{
		cout << expression;
	}

	char calc_again(const string& message)
	{
		cout << message << '\n';
		char a{ '0' };
		cin >> a;
		return a;
	}
}
