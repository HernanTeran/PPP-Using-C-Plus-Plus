#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::vector;
using std::regex;

// *READ*
// the regex pattern help finally solve this exercise
// use it to find a word/phrase in between
// the boundaries of other words

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) { cerr << "error cannot open file name, " << iname << '\n'; }

	vector<string> matches;

	const string word_to_find{ "time" };
	regex pat{ "\\b" + word_to_find + "\\b" };

	for (string line; getline(ifs, line); )
	{
		if (regex_search(line, pat)) { matches.push_back(line); }
	}

	for (const auto& line : matches) cout << line << '\n';

	return 0;
}
