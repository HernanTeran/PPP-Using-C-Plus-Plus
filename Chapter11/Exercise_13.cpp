#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		cerr << "can't open file, " << iname << '\n';
	
	vector<string> separated;

	for (string temp; getline(ifs, temp);)
	{
		string word;

		for (size_t i{ 0 }; i < temp.length(); ++i)
		{
			if (!isspace(temp.at(i)))
				word += temp.at(i);

			const size_t end_pos{ temp.length() - 1 };

			if (isspace(temp.at(i)) || i == end_pos)
			{
				separated.push_back(word);
				word.clear();
			}
		}
	}

	sort(separated.rbegin(), separated.rend());

	for (const auto& word : separated)
		cout << word << ' ';

	return 0;
}
