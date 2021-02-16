// Hernan Teran 2/16/2021
// Chapter 3 Exercise 8
// This is a simple program that outputs whether
// an input integer is even or odd

#include <iostream>

using std::cout;
using std::cin;

void run_program();

void run_program()
{
	for (int val{ 0 }; cin >> val;)
	{
		if (val % 2 == 0) { cout << "The value " << val << " is an even number.\n"; }
		else { cout << "The value " << val << " is an odd number.\n"; }
	}
}

int main()
{
	run_program();

	return 0;
}
