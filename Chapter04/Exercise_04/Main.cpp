// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
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
#include "Main.h"

using namespace std;
using namespace Computation;

char cont_calc(const std::string& prompt)
{
	cout << prompt << endl;
	char cont_calc{ 'n' };
	cin >> cont_calc;
	return cont_calc;
}

void driver()
{
	char y_n{ '0' };

	for (;;)
	{
		try
		{
			Calculator calculator;
			cin >> calculator;
			cout << calculator;
		}
		catch (Calculator::Invalid_Oper)
		{
			cerr << "Invalid operation.\n";
			y_n = cont_calc("Calculate again? (y/n): ");
			if (y_n == 'n') { break; }
		}
	}
	cout << "Goodbye!\n";
}

int main()
{
	driver();

	return 0;
}