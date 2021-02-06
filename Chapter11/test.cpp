#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::string;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::vector;

// file path: practice -> out -> build -> x64 -> practice
// ------------------------------------------------------

int main()
// testing out the append file stream mode
{
	cout << "Please enter the output file name:\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	vector<int> numbers;
	for (std::size_t i{ 0 }; i < 10; ++i) { numbers.push_back(i); }
	for (const auto& n : numbers) { ofs << n << ' '; }
	ofs.close();

	cout << "Please enter the output file name:\n";
	oname.clear();
	cin >> oname;
	ofs.open(oname, std::ios_base::app);

	for (int i{ 0 }; i < 10; ++i) { ofs << i * 2 << ' '; }
	ofs.close();

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	numbers.clear();

	for (int i{ 0 }; ifs >> i; ) { numbers.push_back(i); }

	for (const auto& n : numbers) { cout << n << '\n'; }

	return 0;
}
