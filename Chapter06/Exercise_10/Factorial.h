#ifndef FACTORIAL_H
#define FACTORIAL_H
#pragma once

#include <iostream>

class Factorial
{
	friend std::istream& operator>>(std::istream& is, Factorial& factorial);
public:
	Factorial() = default;
	Factorial(long double a_) : a{ a_ } {}

	long double get() const { return a; }
	void set_b(long double b) { a = b - a; }

	long double operator!() const;

private:
	long double a{ 0 };
};

#endif // FACTORIAL_H