// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 5 Excercise 7
//
// Author: Hernan Teran
// Created: 2021/03/18
//
/*
* Solve a quadratic equation using the quadratic formula.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	constexpr double neg_b{ -1 }, qe_four{ 4 }, qe_two{ 2 };

	for (;;)
	{
		double a{ 0 }, b{ 0 }, c{ 0 };
		cout << "x = (-b +/- sqrt(b^2 - 4ac)) / 2a\n"
			<< "enter a, b, c to solve quadratic equation: ";
		cin >> a >> b >> c;

		const double pos_x = ((neg_b * b) + sqrt(pow(b, qe_two) - qe_four * (a * c))) / (qe_two * a);
		const double neg_x = ((neg_b * b) - sqrt(pow(b, qe_two) - qe_four * (a * c))) / (qe_two * a);

		cout << "Results:\n"
			<< "x = " << pos_x << '\n'
			<< "x = " << neg_x << '\n';
	}

	return 0;
}
