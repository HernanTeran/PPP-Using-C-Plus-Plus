// Hernan Teran 2/16/2021
// Chapter 3 Exercise 4
// This program computes basic arithmetic operations using
// two user inputs

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::cout;
using std::cin;
using std::cerr;

void error(const std::string& message);
void run_program();

int get_number(const std::string& prompt);
int get_smaller(int v1, int v2);
int get_larger(int v1, int v2);
int get_sum(int v1, int v2);
int get_difference(int v1, int v2);
int get_product(int v1, int v2);
double get_ratio(int v1, int v2);

void run_program()
{
	try
	{
		int val1{ 0 }, val2{ 0 };
		val1 = get_number("Enter an integer value:\n");
		val2 = get_number("Enter an integer value:\n");

		int smaller = get_smaller(val1, val2);
		int larger = get_larger(val1, val2);
		int sum = get_sum(val1, val2);
		int difference = get_difference(val1, val2);
		int product = get_product(val1, val2);
		double ratio = get_ratio(val1, val2);

		cout
			<< "smaller: " << smaller << '\n'
			<< "larger: " << larger << '\n'
			<< "sum: " << sum << '\n'
			<< "difference: " << difference << '\n'
			<< "product: " << product << '\n'
			<< "ratio: " << ratio << '\n';
	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}
}

int get_number(const std::string& prompt)
{
	cout << prompt;
	int temp{ 0 };
	cin >> temp;
	if (!cin) { throw std::runtime_error("error"); }
	return temp;
}

int get_smaller(int v1, int v2) { return std::min(v1, v2); }
int get_larger(int v1, int v2) { return std::max(v1, v2); }
int get_sum(int v1, int v2) { return v1 + v2; }
int get_difference(int v1, int v2) { return abs(v1 - v2); }
int get_product(int v1, int v2) { return v1 * v2; }
double get_ratio(int v1, int v2) { return (double)get_larger(v1, v2) / (double)get_smaller(v1, v2); }

void error(const std::string& message) { throw std::runtime_error(message); }

int main()
{
	run_program();

	return 0;
}
