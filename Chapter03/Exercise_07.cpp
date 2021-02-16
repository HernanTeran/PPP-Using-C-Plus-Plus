// Hernan Teran 2/16/2021
// Chapter 3 Exercise 7
// This program is just like exercise 6 but it uses strings instead of integers

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::cout;
using std::cin;
using std::cerr;

void error(const std::string& message);
void run_program();

void run_program()
{
	try
	{
		string val1, val2, val3;
		cin >> val1 >> val2 >> val3;
		if (!cin) { throw std::runtime_error("error"); }
		
		string first{ 0 }, second{ 0 }, third{ 0 };

		if (val1 <= val2 && val1 <= val3)
		{
			first = val1;
			second = val2 <= val3 ? val2 : val3;
			third = second == val2 ? val3 : val2;
		}
		else if (val2 <= val1 && val2 <= val3)
		{
			first = val2;
			second = val1 <= val3 ? val1 : val3;
			third = second == val1 ? val3 : val1;
		}
		else
		{
			first = val3;
			second = val2 <= val1 ? val2 : val1;
			third = second == val2 ? val1 : val2;
		}

		std::cout << first << ", " << second << ", " << third << '\n';
	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}
}

void error(const std::string& message) { throw std::runtime_error(message); }

int main()
{
	run_program();

	return 0;
}
