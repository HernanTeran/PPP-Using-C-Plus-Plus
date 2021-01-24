// ------------------------------------------------------------------------------
// incorrect version

#include <iostream>

int main()
// code is a jumbled mess
{
	double c = 0; // could use {} initializer
	cin >> d; // cin for a variable that doesn't exist
	double k = ctok("c"); // the argument is a string when it should be a double
	Cout << k << '\n'; // cout is misspelled
	
	return 0;
}

double ctok(double c)
{
	int k = c + 273.15; // uses an int instead of a double and a magic constant
	return int; // returns int instead of a variable/value
}

// -------------------------------------------------------------------------------
// correct version

#include <iostream>

class Bad_Input
// simple exception class
{
private:
	double value{ 0 };

public:
	Bad_Input(double val) : value(val) {}

	double get_error_value() { return value; }
};

double get_celsius();
double celsius_to_kelvin(const double celsius);

int main()
// output a valid Celsius temperature
// perform a Celsius to Kelvin converison
// output a valid Kelvin temperature
// throw an exception if invariants and requirements are not met
{
	try
	{
		cout << "convert celsius to kelvin\n";

		double celsius{ 0 }; // uses {} initializer to protect against narrowing conversions
		celsius = get_celsius();

		double kelvin{ 0 };
		kelvin = celsius_to_kelvin(celsius); // proper argument supplied

		cout
		// proper output of values
			<< "[celsius]: " << celsius << " C\n"
			<< "[kelvin]: " << kelvin << " K\n";
	}
	catch (Bad_Input& error)
	{
		cerr << "[invalid input]: " << error.get_error_value() << '\n';
	}
	
	return 0;
}

double get_celsius()
// returns a valid double
// throws exception otherwise
{
	double celsius{ 0 };
	cin >> celsius;

	if (!cin) { throw Bad_Input(celsius); } // first check for invalid input

	constexpr double lowest{ -273.15 }; // lowest possible temperature in Celsius
	constexpr double highest{ 1000000}; // not the highest possible temperature but will do

	if (celsius < lowest || celsius > highest) { throw Bad_Input(celsius); } // second check for ranges

	return celsius;
}

double celsius_to_kelvin(const double celsius)
// performs the computation
// celsius is const because it doesn't need to be modified
{
	constexpr double kelvin{ 273.15 }; // constexpr instead of magic constant

	return celsius + kelvin; // no need to test because celsius was already tested
}
