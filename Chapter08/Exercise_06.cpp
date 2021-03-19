// Chapter 8 Exercise 6
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fill(vector<string>& v);
void print(const vector<string>& v, const string& label);
vector<string> reverse_copy(const vector<string>& v);
void reverse_v(vector<string>& v);

int main()
{
	vector<string> words;
	fill(words);
	print(words, "[original] index #");

	cout << endl;
	
	vector<string> words_cpy = reverse_copy(words);
	print(words_cpy, "[copy] index #");

	cout << endl;

	reverse_v(words);
	print(words, "[reversed] index #");

	return 0;
}

void fill(vector<string>& v)
{
	for (string word; cin >> word;)
		v.push_back(word);
}

void print(const vector<string>& v, const string& label)
{
	for (size_t i{ 0 }; i != v.size(); ++i)
		cout << label << i << ": " << v.at(i) << '\n';
}

vector<string> reverse_copy(const vector<string>& v)
{
	vector<string> words;
	for (size_t i{ v.size() - 1 }; i != 0; --i)
		words.push_back(v.at(i));
	words.push_back(v.at(0));
	return words;
}

void reverse_v(vector<string>& v)
{
	size_t limit{ v.size() / 2 };
	size_t last_idx{ v.size() - 1 };

	for (size_t i = 0; i < limit; ++i)
		swap(v[i], v[last_idx - i]);
}
