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
	void driver()
	{
		for (;;)
		{
			try
			{
				cout << "==============================\n"
					<< "[Compute Rational Expressions]\n"
					<< "==============================\n"
					<< "[Input + for addition]\n"
					<< "[Input - for subtraction]\n"
					<< "[Input * for multiplication]\n"
					<< "[Input / for division]\n"
					<< "==============================\n\n";

				Expression expression;
				cin >> expression;
				cout << expression;

				Rational result = expression.compute();
				cout << result << endl;

				char a = calc_again("\nEnter 'c' to continue...");
				if (a != 'c') { break; }
				cout << "\n";
			}
			catch (Rational::Invalid_Input)
			{
				cin.clear();
				cin.ignore();
				cerr << "\nI am unable to solve this problem.\n\n";
				char a = calc_again("Enter 'c' to continue...");
				if (a != 'c') { break; }
			}
			catch (Expression::Invalid_Operator)
			{
				cin.clear();
				cin.ignore();
				cerr << "\nI am unable to solve this problem.\n\n";
				char a = calc_again("Enter 'c' to continue...");
				if (a != 'c') { break; }
			}
		}
		cout << "\nGoodbye!" << endl;
	}

	char calc_again(const string& message)
	{
		cout << message << '\n';
		char a{ '0' };
		cin >> a;
		return a;
	}
}