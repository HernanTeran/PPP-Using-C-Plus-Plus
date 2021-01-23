#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::regex;
using std::stoi;
using std::smatch;

void run_program();
void prompt();
string get_q_equation();
void display_results(string, int, int, int, int);

int main()
{
	run_program();
	
	return 0;
}

void run_program()
{
	string quadratic_equation;
	quadratic_equation = get_q_equation();

	regex pat{ "(([0-9]+)x\\^(2) ?\\+ ?([0-9]+)x ?\\+ ?([0-9]+) ?= ?(0))" };
	smatch matches;

	while (!regex_match(quadratic_equation, matches, pat))
	{
		cerr << "invalid input try again\n\n";
		quadratic_equation = get_q_equation();
	}

	int a{ 0 };
	int power{ 0 };
	int b{ 0 };
	int c{ 0 };

	a = stoi(matches[0]);
	power = stoi(matches[3]);
	b = stoi(matches[4]);
	c = stoi(matches[5]);

	display_results(quadratic_equation, a, power, b, c);
	
}

string get_q_equation()
{
	prompt();

	string quadratic_equation;
	getline(cin, quadratic_equation);

	return quadratic_equation;
}

void display_results(string equation, int a, int power, int b, int c)
{
	cout
		<< "results:\n"
		<< "equation: " << equation << '\n'
		<< "a: " << a << '\n'
		<< "power: " << power << '\n'
		<< "b: " << b << '\n'
		<< "c: " << c << '\n';
}

void prompt()
{
	cout << "enter a quadratic equation [ Ax^2 + Bx + C = 0 ]:\n";
}
