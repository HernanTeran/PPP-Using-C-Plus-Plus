#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

using std::string;
using std::cout;
using std::cin;
using std::regex;
using std::vector;

void display_prompt();
double convert_to_meters(double value, string units);

int main()
{
	double val1{ 0 };
	double val2{ 0 };
	double old_val{ 0 };
	double smaller{ 0 };
	double larger{ 0 };
	double sum{ 0 };
	int total_values{ 0 };

	string str_val1;
	string units;

	regex pat{ "(([0-9]+)(.)?([0-9]+)? ?[a-z]{1,2})" };
	std::smatch matches;

	const vector<string> valid_units{ "cm", "m", "in", "ft" };
	vector<double> values_entered;

	bool invalid{ false };

	while (!invalid)
	{
		display_prompt();

		getline(cin, str_val1);

		if (str_val1 == "|") { break; } // terminate loop

		if (regex_match(str_val1, matches, pat))
		{
			val1 = std::stoi(matches[2]);
			val2 = std::stoi(matches[4]);
			val1 += val2 < 10 ? val2 / 10 : val2 / 100; // put the decimal back together
			val2 = 0; // reset val2

			for (const char& a : str_val1)
			{
				if (isalpha(a))
				{
					units += a;
				}
			}

			auto iter = std::find(valid_units.cbegin(), valid_units.cend(), units);

			if (iter == valid_units.cend())
			{
				std::cerr << "invalid format try again\n\n";
				invalid = true;
			}
		}
		else
		{
			std::cerr << "invalid format try again\n\n";
			invalid = true;
		}

		smaller = std::min(val1, old_val);
		larger = std::max(val1, old_val);

		cout << "the smaller value is: " << smaller << '\n'
			 << "the larger value is: " << larger << '\n';

		values_entered.push_back(val1);
		sum += convert_to_meters(val1, units);
		++total_values;
		old_val = val1;
		str_val1 = str_val1.erase(); // clear to erase whitespace
		units = units.erase(); // clear to erase whitespace
	}

	std::sort(values_entered.begin(), values_entered.end());

	if (!invalid)
	{
		cout << "values entered: [ ";

		for (const double& value : values_entered)
		{
			smaller = std::min(smaller, value);
			larger = std::max(larger, value);

			cout << value << " ";
		}

		cout << "]\n";

		cout
			<< "smallest: " << smaller << '\n'
			<< "largest: " << larger << '\n'
			<< "total values entered: " << total_values << '\n'
			<< "sum (m): " << sum << '\n';
	}

	return 0;
}

void display_prompt()
{
	cout << "enter a value with a valid unit [ cm m in ft ]:\n";
}

double convert_to_meters(double value, string units)
{
	constexpr double in_to_m{ 39.37 };
	constexpr double cm_to_m{ 100.0 };
	constexpr double ft_to_m{ 3.281 };

	if (units == "in") { return value / in_to_m;  }
	else if (units == "cm") { return value / cm_to_m;  }
	else if (units == "ft") { return value / ft_to_m; }

	return value; // if units == m
}
