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
#include "Main.h"

using namespace std;
using namespace Computation;

int main()
{
	for (;;)
	{
		Quadratic equation;
		cin >> equation;
		if (!cin) { break; }
		cout << equation;
	}

	return 0;
}