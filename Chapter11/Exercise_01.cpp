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

int main()
{	
	cout << "Please enter the output file name:\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	string random_str{ "I AM A CAKE AND I TASTE GREAT!" };
	ofs << random_str;
	ofs.close();

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	string new_str;
	for (char a{ '0' }; ifs >> std::noskipws >> a; ) { new_str += tolower(a); } // noskipws keeps any spaces in strings
	cout << new_str;

	return 0;
}
