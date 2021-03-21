// Hernan Teran 2/18/2021
// Chapter 10 Exercise 9

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include <functional>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;

// --------------------------------------------------------------------------------------------

void error(const std::string& message);
void run_program();

// --------------------------------------------------------------------------------------------

void error(const string& message) { throw std::runtime_error(message); }

void run_program()
{
	try
	{
		// get file names
		cout << "enter file names:\n";
		string iname1, iname2;
		cin >> iname1 >> iname2;
		ifstream ifs{ iname1 };
		if (!ifs) { error("error iname1"); }

		// fill vectors
		vector<string> v1, v2;
		for (string s; ifs >> s;) { v1.push_back(s); }
		ifs.close();
		ifs.open(iname2);
		if (!ifs) { error("error iname2"); }
		for (string s; ifs >> s;) { v2.push_back(s); }

		// sort
		std::sort(v1.begin(), v1.end());
		std::sort(v2.begin(), v2.end());

		// output v1
		cout << "v1:\n";
		std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<string>(std::cout, " "));
		cout << '\n';

		// output v2
		cout << "v2:\n";
		std::copy(v2.cbegin(), v2.cend(), std::ostream_iterator<string>(std::cout, " "));
		cout << '\n';

		// merge
		vector<string> v3;
		std::merge(v2.cbegin(), v2.cend(), v1.cbegin(), v1.cend(), std::back_inserter(v3));
    
    // output v3
		cout << "v3:\n";
		std::copy(v3.cbegin(), v3.cend(), std::ostream_iterator<string>(std::cout, " "));
		cout << '\n';

    // create a file containing merged files
		cout << "enter output file name:\n";
		string oname;
		cin >> oname;
		ofstream ofs{ oname };

		for (const auto& s : v3) { ofs << s << ' '; }
	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}
	catch (...)
	{
		cerr << "something went wrong\n";
	}
}

int main()
{
	run_program();

	return 0;
}
