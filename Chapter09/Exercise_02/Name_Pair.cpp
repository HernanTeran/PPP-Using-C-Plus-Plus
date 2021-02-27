// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Name_Pair
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercise 2 & 3
//
// Author: Hernan Teran
// Created: 2021/02/09
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
#include "Name_Pair.h"

//----------------------------------------------------------------------------------------------------------------------------------
// namespace Name_pairs
//----------------------------------------------------------------------------------------------------------------------------------
/*
* @note This namespace contains the Name_Pair class and its related functions.
*/
namespace Name_pairs
{
	using namespace std;

	//------------------------------------------------------------------------------------------------------------------------------
	// void Name_pair::read_names(const string& prompt)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* @param <prompt> Prompt used to get the user to input a name.
	* 
	* @note This function reads names until 'stop' is entered. Until then, the names are added to
	* the names data member which is a vector.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Name_pair::read_names(const string& prompt)
	{
		cout << prompt;

		for (string name; getline(cin, name);)
		{
			const string stop{ "stop" };

			if (name == stop) { break; }
			names.push_back(name);
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Name_pair::read_ages(const string& prompt)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* @param <prompt> Prompt used to get the user to input an age.
	*
	* @note This function reads ages until a non-digit character is entered. Until then, the ages are added to
	*       the ages data member which is a vector.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Name_pair::read_ages(const string& prompt)
	{
		cout << prompt;

		for (int age{ 0 }; cin >> age;) { ages.push_back(age); }
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Name_pair::print()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* @note This function prints (names[i], ages[i]) pairs as long as both vectors have the same size.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Name_pair::print()
	{
		if (names.empty()) { cerr << "There are no names to print.\n"; }
		if (ages.empty()) { cerr << "There are no ages to print.\n"; }

		if (names.empty() && ages.empty())
		{
			cerr << "There are no names or ages to print.\n";
			return;
		}

		if (names.size() > ages.size() || ages.size() > names.size())
		{
			cerr << "The lists are uneven. Unable to print.\n";
			return;
		}

		for (size_t i{ 0 }; i < names.size(); ++i)
		{
			cout << names.at(i) << '\t' << ages.at(i) << '\n';
		}
		cout << '\n';
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Name_pair::sort()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* @note This function sorts the names and ages vector alphabetically.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Name_pair::sort()
	{
		constexpr size_t one_name{ 1 };

		for (size_t start{ 0 }; start < (names.size() - one_name); ++start)
			// first loop excludes the last element
		{
			// these variables update every iteration
			size_t min_index = start;
			string min_value = names.at(start);
			int temp_age = ages.at(start);

			for (size_t index{ start + one_name }; index < names.size(); ++index)
				// this loop iterates through all the elements
				// this loop begins after the first element
			{
				if (names.at(index) < min_value)
					// make changes
				{
					min_value = names.at(index);
					min_index = index;
					temp_age = ages.at(index);
				}
			}
			// confirm changes
			swap(names.at(min_index), names.at(start));
			swap(ages.at(min_index), ages.at(start));
		}
	}
}
