// Hernan Teran 2/18/2021
// Chapter 10 Exercise 1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;

// --------------------------------------------------------------------------------------------

struct Numbers
{
	vector<double> numbers;
};

void fill(const string& prompt, Numbers& v)
{
	cout << prompt;
	while (true)
	{
		double n{ 0 };
		if (!(cin >> n)) { error("invalid input\n"); }
		if (v.numbers.size() == 7) { break; }
		v.numbers.push_back(n);
	}
}

void create_file(const string& prompt, const Numbers& v)
{
	cout << prompt;
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) { error("error while creating file, " + oname + '\n'); }
	for (const auto& num : v.numbers) { ofs << num << ' '; }
}

void read(const string& prompt, Numbers& v)
{
	cout << prompt;
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) { error("cannot open file, " + iname + '\n'); }
	for (double i{ 0 }; ifs >> i;) { v.numbers.push_back(i); }
}

void print_sum(const Numbers& v)
{
	double sum{ 0 };
	for (const auto& n : v.numbers) { sum += n; }
	cout << "[sum: " << sum << "]\n";
}

// --------------------------------------------------------------------------------------------

void error(const string& message) { throw std::runtime_error(message); }

void run_program()
{
	try
	{
		Numbers numbers;
		fill("Please input numbers:\n", numbers);
		create_file("Please enter the output file name:\n", numbers);

		Numbers new_numbers;
		read("Please enter the input file name:\n", new_numbers);
		print_sum(new_numbers);

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
