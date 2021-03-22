#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

using namespace std;

// *READ*
// the regex pattern helped finally solve this exercise
// use it to find a word/phrase in between the boundaries of other words

int main()
{
	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		cerr << "error cannot open file name, " << iname << '\n';

	string word_to_find{ "time" };
	regex pat{ "\\b" + word_to_find + "\\b" };
	vector<string> matches;

	for (string line; getline(ifs, line); )
		if (regex_search(line, pat))
			 matches.push_back(line);

	for (const auto& line : matches)
		cout << line << '\n';

	return 0;
}
