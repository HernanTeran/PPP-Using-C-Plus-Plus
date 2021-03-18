// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 6 Excercise 10
//
// Author: Hernan Teran
// Created: 2021/03/18
//
/*
* Write a program that overloads the ! operator to solve permutations and combinations.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Factorial.h"

long double Factorial::operator!() const
{
	long double factorial{ 1 };
	for (long double i = 1; i <= a; ++i)
		factorial *= i;
	return factorial;
}

std::istream& operator>>(std::istream& is, Factorial& factorial)
{
	long double f{ 0 };
	std::cout << "Input a positive number: ";
	is >> f;
	factorial = Factorial{ f };
	return is;
}
