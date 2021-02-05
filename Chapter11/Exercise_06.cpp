#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;

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
			switch (c)
			{
			case '.':
			case ',':
			case '/':
			case ';':
			case '?':
			case '-':
			case '\'':
			case '\"':
			case ':':
				c = ' ';
				break;
			default:
				break;;
			}
		}
		paragraph += temp;
	}

	cout << paragraph;

	return 0;
}
