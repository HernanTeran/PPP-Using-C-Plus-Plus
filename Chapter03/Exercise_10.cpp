// Hernan Teran 2/16/2021
// Chapter 3 Exercise 10
// This program takes a string in the form of:
// operator operand operand
// then performs a computation of basic arithmetic

#include <iostream>
#include <string>
#include <exception>
#include <sstream>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::cerr;

void error(const std::string& message);
void run_program();

string get_operation(const std::string& prompt);
double calculate_result(char oper, double op1, double op2);

void run_program()
{
	try
	{
		string operation = get_operation("Enter an expression (operator operand operand):\n");

		stringstream ss{ operation };
		char operator_{ '0' };
		double op1{ 0 }, op2{ 0 };
		ss >> operator_ >> op1 >> op2;

		double result = calculate_result(operator_, op1, op2);
		cout << op1 << ' ' << operator_ << ' ' << op2 << " = " << result << '\n';

	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}
}

string get_operation(const std::string& prompt)
{
	cout << prompt;
	string operation;
	getline(cin, operation);
	return operation;
}

double calculate_result(char oper, double op1, double op2)
{
	double result{ 0 };

	switch (oper)
	{
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		result = std::max(op1, op2) / std::min(op1, op2);
		break;
	default:
		error("invalid operator");
		break;
	}
	return result;
}

void error(const std::string& message) { throw std::runtime_error(message); }

int main()
{
	run_program();

	return 0;
}
