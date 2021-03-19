// Chapter 8 Exercise 7
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<string>& names, const vector<double>& ages);
size_t find_ind(const vector<string>& names_cpy, const string& name);

int main()
{
	vector<string> names;
	cout << "enter names [enter 'done' to exit]\n\n";
	for (string name; cin >> name && name != "done";)
	{
		names.push_back(name);
	}
	cout << endl;

	vector<double> ages;
	cout << "enter the ages of each person\n\n";
	for (double age{ 0 }; cin >> age;)
		ages.push_back(age);

	cout << endl;
	print(names, ages);
	cout << endl;

	vector<string> names_cpy = names;
	sort(names.begin(), names.end());
	vector<double> sorted_ages;

	for (size_t i{ 0 }; i != names.size(); ++i)
	{
		size_t ind = find_ind(names_cpy, names.at(i));
		if (ind != -1)
		{
			sorted_ages.push_back(ages.at(ind));
		}
	}

	print(names, sorted_ages);

	return 0;
}

void print(const vector<string>& names, const vector<double>& ages)
{
	for (size_t i{ 0 }; i != names.size(); ++i)
		cout << names.at(i) << ", " << ages.at(i) << endl;
}

size_t find_ind(const vector<string>& names_cpy, const string& name)
{
	size_t ind{ 0 };
	for (size_t i{ 0 }; i != names_cpy.size(); ++i)
	{
		if (names_cpy.at(i) == name)
			ind = i;
	}
	return ind;
}
