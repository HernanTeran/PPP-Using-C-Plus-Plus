// Chapter 8 Exercise 13
// Author: Hernan Teran
// Created on: 2021/03/19

#include "<iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> str_lengths(const vector<string>& v);
string maxv(const vector<string>& v);
string minv(const vector<string>& v);
string lex_first(const vector<string>& v);
string lex_last(const vector<string>& v);

int main()
{
	vector<string> v;
	constexpr size_t MAX_SZ{ 10 };

	cout << "input " << MAX_SZ << " words:\n";
	for (string str; cin >> str;)
	{
		v.push_back(str);
		if (v.size() == MAX_SZ) { break; }
	}

	cout << endl;

	vector<int> l = str_lengths(v);
	for (const int len : l)
		cout << "length: " << len << '\n';

	cout << endl;

	cout << "largest string length: " << maxv(v) << '\n'
		<< "smallest string length: : " << minv(v) << '\n'
		<< "lexicographically first: " << lex_first(v) << '\n'
		<< "lexicographically last: " << lex_last(v) << '\n';

	return 0;
}

vector<int> str_lengths(const vector<string>& v)
{
	vector<int> l;

	for (const string& s : v)
		l.push_back(s.length());
	return l;
}

string maxv(const vector<string>& v)
{
	string largest = v.at(0);
	for (size_t i{ 0 }; i != v.size(); ++i)
		largest = (largest.length() >= v.at(i).length()) ? largest : v.at(i);
	return largest;
}

string minv(const vector<string>& v)
{
	string smallest = v.at(0);
	for (size_t i{ 0 }; i != v.size(); ++i)
		smallest = (smallest.length() <= v.at(i).length()) ? smallest : v.at(i);
	return smallest;
}

string lex_first(const vector<string>& v)
{
	string first = v.at(0);
	for (size_t i{ 0 }; i != v.size(); ++i)
		first = (first <= v.at(i)) ? first : v.at(i);
	return first;
}

string lex_last(const vector<string>& v)
{
	string last = v.at(0);
	for (size_t i{ 0 }; i != v.size(); ++i)
		last = (last >= v.at(i)) ? last : v.at(i);
	return last;
}
