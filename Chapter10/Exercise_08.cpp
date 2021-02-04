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

struct Numbers
{
	int number{ 0 };
};

void fill_vector(const string&, vector<Numbers>&);
void create_file(const string&, const vector<Numbers>&);
void combine_files(const string&, vector<Numbers>&);
void print_data(const vector<Numbers>&);

int main()
{
	// file path: practice -> out -> build -> x64 -> practice
	
	vector<Numbers> vec_num_1;
	fill_vector("Please input 5 numbers:\n", vec_num_1);

	vector<Numbers> vec_num_2;
	fill_vector("Please input 5 numbers:\n", vec_num_2);

	create_file("Please enter the output file name:\n", vec_num_1);
	create_file("Please enter the output file name:\n", vec_num_2);

	vector<Numbers> combined_vec;
	combine_files("Please enter the two file names you would like to combine:\n", combined_vec);
	print_data(combined_vec);

	return 0;
}

void fill_vector(const string& message, vector<Numbers>& numbers)
{
	cout << message;

	while (numbers.size() < 5)
	{
		int i{ 0 };
		cin >> i;
		numbers.push_back(Numbers{ i });
	}
}

void create_file(const string& message, const vector<Numbers>& numbers)
{
	cout << message;
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	for (const auto& n : numbers) { ofs << n.number << ' '; }
}

void combine_files(const string& message, vector<Numbers>& combined_vec)
{
	cout << message;

	string first_file;
	cin >> first_file;
	string second_file;
	cin >> second_file;
	ifstream ifs{ first_file };

	for (int i{ 0 }; ifs >> i; ) { combined_vec.push_back(Numbers{ i }); }

	ifstream ifs2{ second_file };
	for (int i{0}; ifs2 >> i;) {combined_vec.push_back({Numbers{i}}); }
}

void print_data(const vector<Numbers>& combined_vec)
{
	for (const auto& v : combined_vec) { cout << v.number << '\n'; }
}
