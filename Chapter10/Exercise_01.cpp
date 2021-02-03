#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::string;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::vector;

// * READ *
// I found that if you don't space out the values
// that you are outputting into a file
// they will read wrong (1.1 reads as 0.1)

struct Numbers
{
	double x{ 0 };
};

void fill_vector(vector<Numbers>&, const string&);
void create_file(ofstream& os, const vector<Numbers>&);
void fill_vector(vector<Numbers>&, ifstream&);
void print_sum(const vector<Numbers>&);

int main()
{
	// file path: practice -> out -> build -> x64 -> practice
	
	vector<Numbers> numbers;
	fill_vector(numbers, "Please input 7 numbers:\n");

	cout << "Please enter the output file name: ";
	string oname;
	cin >> oname;
	while (!cin) { cin >> oname; }
	ofstream ofs{ oname };

	create_file(ofs, numbers);

	ofs.close();

	cout << "Please enter the input file name: ";
	string iname;
	cin >> iname;
	while (!cin) { cin >> iname; }
	ifstream ifs{ iname };

	vector<Numbers> new_numbers;
	fill_vector(new_numbers, ifs);
	print_sum(new_numbers);

	return 0;
}

void fill_vector(vector<Numbers>& nums, const string& message)
{
	cout << message;

	while (nums.size() < 7)
	{
		double i{ 0 };
		cin >> i;
		nums.push_back(Numbers{ i });
	}
}

void fill_vector(vector<Numbers>& numbers, ifstream& ifs)
{
	for (double i{ 0 }; ifs >> i;) { numbers.push_back(Numbers{ i }); }
}

void create_file(ofstream& os, const vector<Numbers>& numbers)
{
	for (const auto& ele : numbers) { os << ele.x << ' '; }
}

void print_sum(const vector<Numbers>& numbers)
{
	double sum{ 0 };
	for (const auto& n : numbers) { sum += n.x; }
	cout << "[sum: " << sum << "]\n";
}
