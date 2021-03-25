// Author: Hernan Teran
// Date:   2021/03/25
// Chapter 18 Exercise 5

#include <iostream>
#include <string>

using namespace std;

string cat_dot(const string& s1, const string& s2);

int main()
{
	string s1{ "Niels" },
		     s2{ "Bohr" },
		     s3 = cat_dot(s1, s2);

	cout << s3 << endl;

	return 0;
}

string cat_dot(const string& s1, const string& s2)
{
	return s1 + '.' + s2;
}
