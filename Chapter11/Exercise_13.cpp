#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;
using std::vector;

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	vector<string> separated;

	for (string temp; getline(ifs, temp);)
	{
		string word;

		for (std::size_t i{ 0 }; i < temp.length(); ++i)
		{
			if (!isspace(temp.at(i))) { word += temp.at(i); }

			const std::size_t end_pos{ temp.length() - 1 };

			if (isspace(temp.at(i)) || i == end_pos)
			{
				separated.push_back(word);
				word.clear();
			}
		}
	}

	std::sort(separated.rbegin(), separated.rend());

	for (const auto& word : separated) { cout << word << ' '; }

	return 0;
}
