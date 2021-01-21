#include <iostream>

int get_input();
void run_program();
void display_number(int val);

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

	display_number(val1);
}

void display_number(int val)
{
	switch (val)
	{
	case 0:
		std::cout << "zero\n";
		break;
	case 1:
		std::cout << "one\n";
		break;
	case 2:
		std::cout << "two\n";
		break;
	case 3:
		std::cout << "three\n";
		break;
	case 4:
		std::cout << "four\n";
		break;
	case 5:
		std::cout << "five\n";
		break;
	case 6:
		std::cout << "six\n";
		break;
	case 7:
		std::cout << "seven\n";
		break;
	case 8:
		std::cout << "eight\n";
		break;
	case 9:
		std::cout << "nine\n";
		break;
	default:
		std::cout << "not a number I know\n";
		break;
	}
}
