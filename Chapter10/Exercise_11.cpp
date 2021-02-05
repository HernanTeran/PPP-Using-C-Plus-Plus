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
using std::smatch;

// *READ*
// The program only worked after I used
// an iterator for regex because
// it got matches in a single line
// and on following lines.

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) { cerr << "error cannot open file name, " << iname << '\n'; }

	regex pat{R"( ([0-9]+) )"};
	smatch matches;
  std::size_t sum{ 0 };

	for (string line; getline(ifs, line); )
	{
		string::const_iterator search_start(line.cbegin()); // could also use auto here

		while (regex_search(search_start, line.cend(), matches, pat))
		{
			search_start = matches.suffix().first;
			std::size_t num = stoi(matches[0]);
			sum += num;
		}
	}

	cout << "[sum]: " << sum << '\n';

	return 0;
}
