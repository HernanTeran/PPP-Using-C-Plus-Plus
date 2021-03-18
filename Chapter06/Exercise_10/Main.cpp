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
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Main.h"

using namespace std;

int main()
{
	for (;;)
	{
		cout << "Would you like to calculate a permutation or a combination?\n"
			<< "Enter 'done' to exit.\n\n"
			<< "> ";
		string answer;
		cin >> answer;
		cout << endl;

		Factorial f1, f2;

		if (answer == "permutation")
		{
			cin >> f1 >> f2;
			f2.set_b(f1.get());
			cout << "Result: " << fixed << setprecision(0) << !f1 / !f2 << "\n\n";
		}
		if (answer == "combination")
		{
			Factorial f3;
			cin >> f1 >> f2;
			f3 = f2;
			f3.set_b(f1.get());
			long double p = !f1 / !f3;
			cout << "Result: " << fixed << setprecision(0) << p / !f2 << "\n\n";
		}
		if (answer == "done") 
		{ 
			cout << "Goodbye!" << endl;
			break; 
		}
	}

	return 0;
}