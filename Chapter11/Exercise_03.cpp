#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using std::cout;
using std::string;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;

// *READ*
// at first the program wasn't working because
// I didn't close ofs

int main()
{
	// file path: practice -> out -> build -> x64 -> practice
	
	cout << "Please enter the output file name:\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	string vowels{ "Once upon a time!" };
	ofs << vowels;
	ofs.close();

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	string disemvowel;

	for (char l{ '0' }; ifs >> std::noskipws >> l;)
	{
		switch (l)
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'U':
		case 'u':
			break;
		default:
			disemvowel += l;
			break;
		}
	}

	cout << disemvowel;

	return 0;
}
