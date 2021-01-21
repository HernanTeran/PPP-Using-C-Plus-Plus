#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::cout;
using std::cin;

string get_operation();
void run_program();
int compute(char op, const int val1, const int val2);

int main()
{
	run_program();

	return 0;
}

string get_operation()
{
	cout
		<< "Compute an operation\n"
		<< "------------------\n"
		<< "Operators: + - * /\n\n"
		<< "Format: operator value1 value2\n\n";

	string operation;
	getline(cin, operation);

	return operation;
}

void run_program()
{
	string operation;
	operation = get_operation();

	std::regex pat{ "([\\+|\\-|\\*|\\/] ([0-9]+) ([0-9]+))" };
	std::smatch matches;

	char operator_used{ 0 };
	int val1{ 0 };
	int val2{ 0 };

	if (std::regex_match(operation, matches, pat))
	{
		operator_used = operation.at(0);
		val1 = std::stoi(matches[2]);
		val2 = std::stoi(matches[3]);
	}
	else
	{
		std::cerr << "invalid format try again\n";
	}

	int result{ 0 };
	result = compute(operator_used, val1, val2);

	std::cout << "Result: " << result << '\n';
}

int compute(char op, const int val1, const int val2)
{
	int result{ 0 };
	int largest{ 0 };
	largest = val1 > val2 ? val1 : val2;

	switch (op)
	{
	case '+':
		result = val1 + val2;
		break;
	case '-':
		result = val1 - val2;
		break;
	case '*':
		result = val1 * val2;
		break;
	case '/':
		result = val1 == largest ? val1 / val2 : val2 / val1;
		break;
	default:
		std::cerr << "can't compute\n";
		break;
	}
	return result;
}
