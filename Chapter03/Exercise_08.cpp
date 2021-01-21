#include <iostream>

int get_input();
void run_program();
void odd(int val);
void even(int val);

int main()
{
	run_program();

	return 0;
}

int get_input()
{
	std::cout << "Enter a value:\n";

	int val{ 0 };
	std::cin >> val;

	return val;
}

void run_program()
{
	int val1{ 0 };
	val1 = get_input();

	if (val1 % 2 == 0)
	{
		even(val1);
	}
	else
	{
		odd(val1);
	}
}

void odd(int val)
{
	std::cout << "The value " << val << " is an odd number.\n";
}

void even(int val)
{
	std::cout << "The value " << val << " is an even number.\n";
}
