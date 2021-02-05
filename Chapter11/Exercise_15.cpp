#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::vector;

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the output file name:\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	vector<double> numbers;
	constexpr std::size_t max_vec_sz{ 5 };

	for (double i{ 0 }; cin >> i;)
	{
		numbers.push_back(i);
		if (numbers.size() == max_vec_sz) { break; }
	}

	for (const auto& n : numbers) { ofs << n << ' '; }

	ofs.close();

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	while (!ifs)
	{
		cerr << "error cannot open file, " << iname << '\n';
		iname.clear();
		cin.clear();
		cout << "Please try entering another input file name:\n";
		cin >> iname;
		ifs.open(iname);
	}

	numbers.clear();

	for (double number{ 0 }; ifs >> number;)
	{
		numbers.push_back(number);
		if (ifs.eof()) { break; }
	}
	
	ifs.close();

	cout << "Please input the output file name:\n";
	oname.clear();
	cin >> oname;
	ofs.open(oname);

	for (auto& n : numbers)
	{
		ofs << std::setprecision(8) << std::scientific << n << '\n';
	}

	return 0;
}
