// Hernan Teran 2/16/2021
// Chapter 3 Exercise 2
// This program converts miles to kilometers

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::cout;
using std::cin;
using std::cerr;

void error(const std::string& message);
double get_miles(const std::string& prompt, const std::string& message);
double convert_mi_to_km(double miles);
void run_program();

int main()
{
	run_program();

	return 0;
}

void run_program()
{
	try
	{
		double miles{ 0 };
		miles = get_miles("Enter miles to convert to kilometers:\n", "error input cannot be less than 0\n");

		double mi_to_km{ 0 };
		mi_to_km = convert_mi_to_km(miles);

		std::cout
			<< "Miles: " << miles << " mi\n"
			<< "Kilometers " << mi_to_km << " km\n";
	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}
}

double get_miles(const std::string& prompt, const std::string& message)
{
	cout << prompt;
	double miles{ 0 };
	std::cin >> miles;

	if (miles < 0) { throw std::runtime_error(message); }

	return miles;
}

double convert_mi_to_km(double miles)
{
	constexpr double kilometers{ 1.609 };

	return miles * kilometers;
}

void error(const std::string& message) { throw std::runtime_error(message); }
