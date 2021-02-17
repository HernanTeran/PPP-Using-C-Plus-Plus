// Hernan Teran 2/17/2021
// Chapter 5 Exercise 14

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

int main()
{
	vector<string> valid_days{ "mon", "monday", "Monday",
								  "tues", "tuesday", "Tuesday",
								  "weds", "wednesday", "Wednesday",
								  "thurs", "thursday", "Thursday",
								  "fri", "friday", "Friday",
								  "sat", "saturday", "Saturday",
								  "sun", "sunday", "Sunday" };
		vector<int> day_digits;
		vector<string> week_days;
		int rejected_values{ 0 };
		int sum{ 0 };

		string day;
		int n_day{ 0 };

		while (cin >> day >> n_day)
		{
			auto it = std::find(valid_days.cbegin(), valid_days.cend(), day);
			if (it != valid_days.cend()) { week_days.push_back(day); }
			else { ++rejected_values; }

			if (n_day > 0 && n_day < 31) { day_digits.push_back(n_day); sum += n_day; }
			else { ++rejected_values; }
		}

		for (const auto& week_day : week_days) { cout << week_day << '\n'; }

		cout << "total rejected values: " << rejected_values << '\n'
			 << "sum of values entered: " << sum << '\n';

	return 0;
}
