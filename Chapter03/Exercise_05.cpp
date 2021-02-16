// Hernan Teran 2/16/2021
// Chapter 3 Exercise 5
// This program uses the program from exercise 4 but int is replaced with doubles
// There is no difference when using doubles ending in .0
// Otherwise numbers could be larger or smaller depending on the decimal values

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::cout;
using std::cin;
using std::cerr;

void error(const std::string& message);
void run_program();

double get_number(const std::string& prompt);
double get_smaller(double v1, double v2);
double get_larger(double v1, double v2);
double get_sum(double v1, double v2);
double get_difference(double v1, double v2);
double get_product(double v1, double v2);
double get_ratio(double v1, double v2);

void run_program()
{
	try
	{
		double val1{ 0 }, val2{ 0 };
		val1 = get_number("Enter a floating-point value:\n");
		val2 = get_number("Enter a floating-point value value:\n");

		double smaller = get_smaller(val1, val2);
		double larger = get_larger(val1, val2);
		double sum = get_sum(val1, val2);
		double difference = get_difference(val1, val2);
		double product = get_product(val1, val2);
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

double get_number(const std::string& prompt)
{
	cout << prompt;
	double temp{ 0 };
	cin >> temp;
	if (!cin) { throw std::runtime_error("error"); }
	return temp;
}

double get_smaller(double v1, double v2) { return std::min(v1, v2); }
double get_larger(double v1, double v2) { return std::max(v1, v2); }
double get_sum(double v1, double v2) { return v1 + v2; }
double get_difference(double v1, double v2) { return abs(v1 - v2); }
double get_product(double v1, double v2) { return v1 * v2; }
double get_ratio(double v1, double v2) { return get_larger(v1, v2) / get_smaller(v1, v2); }

void error(const std::string& message) { throw std::runtime_error(message); }

int main()
{
	run_program();

	return 0;
}
