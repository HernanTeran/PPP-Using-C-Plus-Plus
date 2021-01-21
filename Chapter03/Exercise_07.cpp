#include <iostream>
#include <string>

using std::string;

void run_program();
string get_input();

int main()
{
	run_program();

	return 0;
}

string get_input()
{
	std::cout << "Enter a value:\n";

	string val;;
	getline(std::cin, val);

	return val;
}

void run_program()
{
	string val1;
	val1 = get_input();

	string val2;
	val2 = get_input();

	string val3;
	val3 = get_input();

	string first;
	string second;
	string third;
	
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
