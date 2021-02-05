#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;

// *READ*
// I couldn't get the program to work
// at first because I was using str.find()
// and str.replace() incorrectly.
// order: (old, found_position, new)

int main()
{
	// file path: practice -> out -> build -> x64 -> practice

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

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

		while (temp.find("can't") != std::string::npos)
		{
			std::size_t pos = temp.find("can't");
			temp.replace(temp.find("can't"), pos, "cannot");
		}

		while (temp.find("don't") != std::string::npos)
		{
			std::size_t pos = temp.find("don't");
			temp.replace(temp.find("don't"), pos, "do not");
		}
		
		paragraph += temp;
	}

	cout << paragraph;

	return 0;
}
