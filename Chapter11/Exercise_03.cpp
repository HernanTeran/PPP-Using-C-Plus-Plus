#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// *READ*
// at first the program wasn't working because I didn't close ofs

int main()
{	
	cout << "Please enter the output file name:\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
		cerr << "can't open file, " << oname << '\n';

	string vowels{ "Once upon a time!" };
	ofs << vowels;
	ofs.close();

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
		cerr << "can't open file, " << iname << '\n';

	string disemvowel;

	for (char l{ '0' }; ifs >> noskipws >> l;)
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
