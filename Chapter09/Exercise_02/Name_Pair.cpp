// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Name_Pair
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercise 2 & 3
//
// Author: Hernan Teran
// Created: 2021/03/20
//
/*
* Design and implement a Name_Pairs class holding (name, age) pairs where name is a string and age is a double.
* Represent that as a vector<string> (called name) and a vector<double> (called age) member.
* Provide an input operation read_names() that reads a series of names.
* Provide a read_ages() operation that prompts the user for an age for each name.
* Provide a print() operation that prints out the (name[i], age[i]) pairs (one per line)
* in the order determined by the name vector.
* Provide a sort() operation that sorts the vector in alphabetical order and reorganizes the age vector to match.
* Implement all "operations" as member functions.
* Replace Name_Pair::print() with a global operator << and define == and != for Name_Pairs.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Name_Pairs.h"

using namespace std;

size_t Name_Pairs::data_sz(const string& prompt)
{
	cout << prompt;
	size_t sz{ 0 };
	cin >> sz;
	if (!cin) { throw Invalid_Pair{}; }
	return sz;
}

void Name_Pairs::read_names(const string& prompt)
{
	DATA_SZ = data_sz("Total names to be entered: ");

	cout << prompt << '\n';

	for (string n; cin >> n;)
	{
		name.push_back(n);
		if (name.size() == DATA_SZ) { return; }
	}
}

void Name_Pairs::read_ages(const string& prompt)
{
	cout << prompt << '\n';

	for (int a{ 0 }; cin >> a;)
	{
		if (a <= 0 || !cin) { throw Invalid_Pair{}; }
		age.push_back(a);
		if (age.size() == DATA_SZ) { return; }
	}
}

void Name_Pairs::sort()
{
	for (size_t start{ 0 }; start < (name.size() - 1); ++start)
	{
		// these variables update every iteration
		size_t min_index = start;
		string min_value = name.at(start);
		int temp_age = age.at(start);

		for (size_t index{ start + 1 }; index < name.size(); ++index)
			// this loop iterates through all the elements
			// this loop begins after the first element
		{
			if (name.at(index) < min_value)
				// make changes
			{
				min_value = name.at(index);
				min_index = index;
				temp_age = age.at(index);
			}
		}
		// confirm changes
		swap(name.at(min_index), name.at(start));
		swap(age.at(min_index), age.at(start));
	}
}

void Name_Pairs::print(const string& prompt)
{
	cout << prompt << endl;
	for (size_t i{ 0 }; i != DATA_SZ; ++i)
		cout << "Name: " << name.at(i) << '\n' << "Age: " << age.at(i) << "\n\n";
}

ostream& operator<<(ostream& os, const Name_Pairs& pairs)
{
	os << "\nPairs: " << endl;
	for (size_t i{ 0 }; i != pairs.get_sz(); ++i)
		os << "Name: " << pairs.get_names().at(i) << '\n' << "Age: " << pairs.get_ages().at(i) << "\n\n";
	return os;
}

bool operator==(const Name_Pairs& lp, const Name_Pairs& rp)
{
	return (lp.get_names() == rp.get_names()) && (lp.get_ages() == rp.get_ages());
}

bool operator!=(const Name_Pairs& lp, const Name_Pairs& rp)
{
	return !(lp.get_names() == rp.get_names()) && (lp.get_ages() == rp.get_ages());;
}
