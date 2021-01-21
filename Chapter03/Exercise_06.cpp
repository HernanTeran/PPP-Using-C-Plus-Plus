#include <iostream>

void run_program();
double get_input();

int main()
{
	run_program();

	return 0;
}

double get_input()
{
	std::cout << "Enter a value:\n";

	double val{ 0 };
	std::cin >> val;

	return val;
}

void run_program()
{
	double val1{ 0 };
	val1 = get_input();

	double val2{ 0 };
	val2 = get_input();

	double val3{ 0 };
	val3 = get_input();
	
	double first{ 0 };
	double second{ 0 };
	double third{ 0 };
	
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
