// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 5 Excercise 11
//
// Author: Hernan Teran
// Created: 2021/03/18
//
/*
* Write a program that writes out the first so many values of the Fibonacci series.
* Find the largest Fibonacci number that fits in an int.
* 
* Largest I found: 1836311903
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include <iostream>

using namespace std;

int fibonacci(int x);

int main()
{
	int fib{ 1 };
	
	for (;;)
	{
		cout << fibonacci(fib) << '\n';
		++fib;
	}

	return 0;
}

int fibonacci(int x)
{
	if (x <= 1) { return x; }
	return fibonacci(x - 1) + fibonacci(x - 2);
}
