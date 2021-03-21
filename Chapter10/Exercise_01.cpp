// Hernan Teran 2021/03/21
// Chapter 10 Exercise 1

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void error(string s1, string s2);

int main()
{
	try
	{
		cout << "Please enter the name of output file: ";
		string oname;
		cin >> oname;
		ofstream ofs{ oname };
		if (!ofs) error("can't open output file ", oname);

		for (int i{ 0 }; i != 100; ++i)
			ofs << i << ' ';

		ofs.close();

		cout << "Please enter the input file name: ";
		string iname;
		cin >> iname;
		ifstream ifs{ iname };
		if (!ifs) error("can't open input file ", iname);

		int sum{ 0 };

		for (int i{ 0 }; ifs >> i;)
			sum += i;

		cout << "sum: " << sum << endl;
	}
	catch (exception& e)
	{
		cerr << e.what();
	}


	return 0;
}

void error(string s1, string s2)
{
	throw runtime_error(s1 + s2);
}
