#include <iostream>
#include <string>
#include <fstream>
#include <map>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::map;

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the output file name:\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	ofs << "i like to eat 5 pies\nso & ye%$a; go, tell / a dog 23\n4 4.5 nice...{}~~ QWERTY_+=:";
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

	map<char, int> counts;

	for (string line; getline(ifs, line);)
	{
		for (const auto& c : line)
		{
			if (isalpha(c)) { ++counts[c]; }
			else if (isdigit(c)) { ++counts[c]; }
			else if (isspace(c)) { ++counts[c]; }
			else if (isascii(c)) { ++counts[c]; }
			else if (ispunct(c)) { ++counts[c]; }
			else { cerr << "{error} unknown character\n"; }
		}
	}

	cout << "\nvalue\tcount\n"
		   << "-------------\n";

	for (const auto& m : counts) { cout << m.first << '\t' << m.second << '\n'; }

	return 0;
}
