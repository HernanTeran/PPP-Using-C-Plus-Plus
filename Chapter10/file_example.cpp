#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Reading
{
	int hour{ 0 };
	double temperature{ 0 };
};

int main()
{
	// file path: practice -> out -> build -> x64 -> practice
	using std::cout;
	using std::string;
	using std::cin;
	using std::ifstream;
	using std::ofstream;
	using std::cerr;
	using std::vector;

	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) { cerr << "can't open input file " << iname << '\n'; }

	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) { cerr << "can't open output file " << oname << '\n'; }

	vector<Reading> temps;
	int hour{ 0 };
	double temperature{ 0 };
	while (ist >> hour >> temperature)
	{
		if (hour < 0 || hour > 23) { cerr << "\nhour out of range\n"; }
		temps.push_back(Reading{ hour, temperature });
	}

	for (std::size_t i{ 0 }; i < temps.size(); ++i)
	{
		ost << '(' << temps.at(i).hour << ',' << temps.at(i).temperature << ")\n";
	}

	return 0;
}

void fill_vector(istream& ist, vector<int>& v, char terminator, const string& message)
{
	for (int i{ 0 }; ist >> i; ) { v.push_back(i); }
	if (ist.eof()) { return; }

	ist.clear(); // else bad state

	char c{ '0' };
	ist >> c;

	if (c != terminator)
	{
		ist.unget();
		ist.clear(ios_base::failbit);
	}
}
