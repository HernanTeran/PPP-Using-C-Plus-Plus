// Author: Hernan Teran
// Date:   2021/03/25
// Chapter 18 Exercise 6

#include <iostream>
#include <string>

using namespace std;

string cat_dot(const string& s1, const string& s2, const string& delim);

int main()
{
	string s1{ "Niels" },
		s2{ "Bohr" },
		delim{ "MOON" },
		s3 = cat_dot(s1, s2, delim);

	cout << s3 << endl;

	return 0;
}

string cat_dot(const string& s1, const string& s2, const string& delim)
{
	return s1 + delim + s2;
}
