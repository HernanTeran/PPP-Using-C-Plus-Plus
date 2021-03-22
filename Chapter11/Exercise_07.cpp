#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// *READ*
// I couldn't get the program to work
// at first because I was using str.find() and str.replace() incorrectly.
// order: (old, found_position, new)

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		cerr << "can't open file, " << iname << '\n';

	string paragraph;
	
	for (string temp; getline(ifs, temp);)
	{
		for (auto& c : temp)
		{
			c = tolower(c);

			switch (c)
			{
			case '.':
			case ',':
			case '/':
			case ';':
			case '?':
			case '\"':
			case ':':
				c = ' ';
				break;
			default:
				break;;
			}
		}

		while (temp.find("can't") != string::npos)
		{
			size_t pos = temp.find("can't");
			temp.replace(temp.find("can't"), pos, "cannot");
		}

		while (temp.find("don't") != string::npos)
		{
			size_t pos = temp.find("don't");
			temp.replace(temp.find("don't"), pos, "do not");
		}
		paragraph += temp;
	}

	cout << paragraph;

	return 0;
}
