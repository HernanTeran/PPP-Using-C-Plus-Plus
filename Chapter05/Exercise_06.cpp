// Author:  Hernan Teran
// Date:    2021/04/19
// Chapter 5 Exercise 6

#include <iostream>
using namespace std;

class Bad_temp {};

double fahrenheit(double cel);
double celsius(double fahr);

int main()
{
	try
	{
		double cel{ 0.0 };
		cout << "convert celsius to fahrenheit:" << endl;
		cin >> cel;
		double cel_to_fahr = fahrenheit(cel);
		cout << "ans = " << cel_to_fahr << endl;

		double fahr{ 0.0 };
		cout << "convert fahrenheit to celsius:" << endl;
		cin >> fahr;
		double fahr_to_cel = celsius(fahr);
		cout << "ans = " << fahr_to_cel << endl;
	}
	catch (Bad_temp)
	{
		cerr << "invalid temperature input" << endl;
		return -1;
	}
	
	return 0;
}

double fahrenheit(double cel)
// convert celsius to fahrenheit
// pre-conditions: MIN < cel < MAX
// post-conditions: returns valid conversion or throws exception if arguments are invalid
{
	constexpr double MIN{ -273.15 };
	constexpr double MAX{ 273.15 };
	if (cel < MIN || cel > MAX) throw Bad_temp{};
	constexpr double CONST_1{ 1.8 };
	constexpr double CONST_2{ 32.0 };
	return (cel * CONST_1) + CONST_2;
}

double celsius(double fahr)
// convert fahrenheit to celsius
// pre-conditions: -459.67 < fahr < 459.67
// post-conditions: returns valid conversion or throws exception if arguments are invalid
{
	constexpr double MIN{ -459.67 };
	constexpr double MAX{ 459.67 };
	if (fahr < MIN || fahr > MAX) throw Bad_temp{};
	constexpr double CONST_1{ 32.0 };
	constexpr double CONST_2{ 1.8 };
	return (fahr - CONST_1) / CONST_2;
}
