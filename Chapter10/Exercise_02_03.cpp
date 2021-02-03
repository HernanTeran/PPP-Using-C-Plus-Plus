#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::vector;

struct Reading
{
	double temperature{ 0 };
};

void fill_vector(const string&, vector<Reading>&);
void create_file(const string&, const vector<Reading>&);
void use_file(const string&, vector<Reading>&);
void calculate_stats(const vector<Reading>&);

int main()
{
	// file path: practice -> out -> build -> x64 -> practice
	
	vector<Reading> temperatures;
	fill_vector("Please enter at least 50 temperatures:\n", temperatures);
	create_file("Please enter the output file name:\n", temperatures);

	// ------------

	vector<Reading> new_temperatures;
	use_file("Please enter the input file name:\n", new_temperatures);
	calculate_stats(new_temperatures);

	return 0;
}

void fill_vector(const string& message, vector<Reading>& temps)
{
	cout << message;
	constexpr std::size_t max_size{ 50 };

	while (temps.size() < max_size)
	{
		double temp{ 0 };
		cin >> temp;
		temps.push_back(Reading{ temp });
	}
}

void create_file(const string& prompt, const vector<Reading>& temperatures)
{
	cout << prompt;
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	for (const auto& temp : temperatures) { ofs << temp.temperature << ' '; }
}

void use_file(const string& prompt, vector<Reading>& temperatures)
{
	cout << prompt;
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	for (double temp{ 0 }; ifs >> temp;) { temperatures.push_back(Reading{ temp }); }
}

void calculate_stats(const vector<Reading>& temperatures)
{
	double sum{ 0 };

	for (const auto& temp : temperatures) { sum += temp.temperature; }

	const double vec_sz = { temperatures.size() + 0.0 };
	const double mean = { sum / vec_sz };

	constexpr int two{ 2 };
	constexpr double med_eq_val2{ 2.0 };
	constexpr double med_eq_val1{ 1.0 };
	double median{ 0 };

	if (temperatures.size() % two == 0)
	{
		median = ((vec_sz / med_eq_val2) + ((vec_sz + med_eq_val1) / med_eq_val2)) / med_eq_val2;
	}
	else
	{
		median = (vec_sz + med_eq_val1) / med_eq_val2;
	}

	cout << "[mean: " << mean << "]\n"
		<< "[median: " << median << "]\n";
}
