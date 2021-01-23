#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::map;
using std::size_t;

string find_min(const vector<string>& strings);
string find_max(const vector<string>& strings);
string find_mode(const vector<string>& strings);
void display_results(const string min, const string max, const string mode);

int main()
{
	vector<string> strings{ "Hi", "Hello", "Goodbye",
							"Beatles", "Paul", "John",
							"George", "Ringo", "Lennon",
							"McCartney", "Harrison", "Starr",
							"McCartney", "Lennon", "McCartney" };

	string min_str;
	string max_str;
	string mode_str;

	min_str = find_min(strings);
	max_str = find_max(strings);
	mode_str = find_mode(strings);

	display_results(min_str, max_str, mode_str);

	return 0;
}

string find_min(const vector<string>& strings)
{
	string min_str{ strings.at(0) };

	for (size_t i{ 1 }; i < strings.size(); ++i)
	{
		min_str = min_str < strings.at(i) ? min_str : strings.at(i);
	}

	return min_str;
}

string find_max(const vector<string>& strings)
{
	string max_str{ strings.at(0) };

	for (size_t i{ 1 }; i < strings.size(); ++i)
	{
		max_str = max_str > strings.at(i) ? max_str : strings.at(i);
	}
	return max_str;
}

string find_mode(const vector<string>& strings)
{
	size_t current_count{ 0 };
	size_t max_count{ 0 };
	map<string, std::size_t> mode_count;
	string mode_str;
	
	for (const auto& str : strings)
	{
		if (!mode_count.count(str))
		{
			++current_count;
			mode_count.emplace(str, current_count);
		}
		else if (mode_count.count(str))
		{
			++mode_count[str];
		}
		current_count = 0;
	}

	if (mode_count.count(strings.at(0))) { current_count = mode_count.at(strings.at(0)); }

	for (const auto& str : mode_count)
	{
		if (str.second != 1)
		{
			max_count = std::max(current_count, str.second);
			mode_str = str.first;
		}
	}

	if (max_count == 1) { mode_str = "none"; }

	return mode_str;
}

void display_results(const string min, const string max, const string mode)
{
	cout
		<< "min: " << min << '\n'
		<< "max: " << max << '\n'
		<< "mode: " << mode << '\n';
}
