#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		cerr << "can't open file, " << iname;

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
