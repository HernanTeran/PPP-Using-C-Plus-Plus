// Hernan Teran 2/16/2021
// Chapter 3 Exercise 6
// This program gets three user-input integers,
// sorts them a <= b <= c
// then prints them as a, b, c

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
		int val1{ 0 }, val2{ 0 }, val3{ 0 };
		cin >> val1 >> val2 >> val3;
		if (!cin) { throw std::runtime_error("error"); }
		
		double first{ 0 }, second{ 0 }, third{ 0 };

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
