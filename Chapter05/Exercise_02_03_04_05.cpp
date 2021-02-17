// Hernan Teran 2/17/2021
// Chapter 5 Exercises 2, 3, 4, 5
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
#include <string>
#include <exception>

using std::string;
using std::stringstream;
using std::vector;
using std::size_t;
using std::cout;
using std::cin;
using std::cerr;

// --------------------------------------------------------------------------------------------

void error(const std::string& message);
void run_program();
double ctok(double c, const std::string& message);
double ktoc(double k, const std::string& message);

// --------------------------------------------------------------------------------------------

double ktoc(double k, const std::string message)
// convert kelvin to celsius
// 0 < k < 10,000
// returns a valid conversion within range
// throws an exception if there is invalid input
{
	constexpr double celsius{ 273.15 },
			 min_kelvin{ 0 },
			 max_kelvin{ 10'000 };
	
	if (k < min_kelvin || k > max_kelvin) { error(message); }
	
	return k - celsius;	 
}

double ctok(double c, const string& message)
// convert celsius to kelvin
// -273.15 < c < 273.15
// returns a valid conversion within range
// throws an exception if there is invalid input
{
	constexpr double kelvin{ 273.15 }, 
		         min_celsius{ -273.15 },
		         max_celsius{ 1000 };

	if (c < min_celsius || c > max_celsius) { error(message); }

	return c + kelvin;
}

// --------------------------------------------------------------------------------------------

void error(const string& message) { throw std::runtime_error(message); }

void run_program()
{
	try
	{
		cout << "enter a temperature to convert (celsius to kelvin):\n";

		for (double celsius{ 0 }; cin >> celsius;)
			// reads temperatures until a character is entered
			// outputs valid temperatures
		{
			double kelvin = ctok(celsius, "error temperature is not within a valid range\n");
			cout << "celsius: " << celsius << "\nkelvin: " << kelvin << '\n';
		}
		
		cout << "enter a temperature to convert (kelvin to celsius):\n";

		for (double kelvin{ 0 }; cin >> kelvin;)
			// reads temperatures until a character is entered
			// outputs valid temperatures
		{
			double celsius = ktoc(kelvin, "error temperature is not within a valid range\n");
			cout << "kelvin: " << kelvin << "\ncelsius: " << celsius << '\n';
		}
	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}
	catch (...)
	{
		cerr << "something went wrong\n";
	}
}

int main()
{
	run_program();

	return 0;
}
