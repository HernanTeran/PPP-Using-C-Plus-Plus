// Author:  Hernan Teran
// Date:    2021/04/20
// Chapter 5 Exercise 7

/////////////////////////////////////////////////////////////////
// Program description                                         //
/////////////////////////////////////////////////////////////////
// Solve quadratic equations using the quadratic formula:      //
// Quadratic equation: a*x^2 + b*x + c = 0                     //
// Quadratic formula:  x = (-b (+-) sqrt(b^2 - 4(a*c))) / 2*a  //
// (+-) = plus or minus sign                                   //
// ***DOES NOT solve if result contains a complex number       //
/////////////////////////////////////////////////////////////////

// headers
#include <iostream>
#include <string>
#include <cmath>
#include <exception>

using namespace std;

// exception class
struct Bad_input {};

// functions
void driver(ostream& os, const string& errMes1, const string& errMes2, const string& gbMes);
char cont_loop(ostream& os, const string& prompt, istream& is);
double coefficient(ostream& os, const string& prompt, istream& is);
double solve_root(double a, double b, double c);
double solve_den(double a);
void print_ans(ostream& os, double ans1, double ans2);

int main()
{
	driver(cerr, "Invalid input", "Unknown error", "Goodbye!");
	return 0;
}

/// @brief Driver that runs the program loop
/// @param os      Reference to ostream cerr object
/// @param errMes1 Error message for invalid input i.e. non-numerical input
/// @param errMes2 Error message for unknown errors
/// @param gbMes   Goodbye message
void driver(ostream& os, const string& errMes1, const string& errMes2, const string& gbMes)
{
	for (;;)
	{
		try
		{
			// constant for -b or -1 * b
			constexpr double neg_b{ -1.0 };

			// coefficients
			double a = coefficient(cout, "Enter a:", cin);
			double b = coefficient(cout, "Enter b:", cin);
			double c = coefficient(cout, "Enter c:", cin);

			// square root
			double root = solve_root(a, b, c);

			// denominator
			a = solve_den(a);

			// -b
			b *= neg_b;

			// 2 answers
			double ans1 = b + root, ans2 = b - root;
			ans1 /= a, ans2 /= a;

			// print answers
			print_ans(cout, ans1, ans2);
			
			// calculate again?
			char res = cont_loop(cout, "Calculate again? y/n:", cin);
			if (res == 'n' || res == 'N') break;
		}
		catch (Bad_input)
		{
			os << errMes1 << endl;
			return;
		}
		catch (...)
		{
			os << errMes2 << endl;
			return;
		}
	}
	os << gbMes << endl;
	return; // done calculating
}

/// @brief User input to calculate again
/// @param os     Reference to ostream cout object
/// @param prompt Prompt for user input
/// @param is     Reference to istream cin object
/// @return A char value, ideally y or n
char cont_loop(ostream& os, const string& prompt, istream& is)
{
	os << endl;
	os << prompt << endl;
	char res{ '0' };
	is >> res;
	if (!is)
	{
		is.clear();
		throw Bad_input{};
	}
	os << endl;
	return res;
}

/// @brief Get user input for coefficient
/// @param os     Reference to ostream cout object
/// @param prompt Prompt for user input
/// @param is     Reference to istream cin object
/// @return       A positive or negative double value
double coefficient(ostream& os, const string& prompt, istream& is)
{
	os << prompt << endl;
	double coeff{ 0.0 };
	is >> coeff;
	if (!is)
	{
		is.clear(ios_base::failbit);
		throw Bad_input{};
	}
	return coeff;
}

/// @brief Solves the sqrt(b^2 - 4(a*c)) part of the equation
/// @param  a double a coefficient
/// @param  b double b coefficient
/// @param  c double c coefficient
/// @return decimal value of this part of the equation
double solve_root(double a, double b, double c)
{
	constexpr double four{ 4.0 }, two{ 2.0 };
	return abs(sqrt((pow(b, two) - (four * (a * c)))));
}

/// @brief Solves the 2*a part of the equation
/// @param a double a coefficient
/// @return whatever 2*a is
double solve_den(double a)
{
	constexpr double two{ 2.0 };
	return two * a;
}

/// @brief Print both answers to the console
/// @param os   Reference to ostream cout object
/// @param ans1 Answer where addition was used
/// @param ans2 Answer the subtraction was used
void print_ans(ostream& os, double ans1, double ans2)
{
	os << "+ ans = " << ans1 << '\n'
		<< "- ans = " << ans2 << endl;
}
