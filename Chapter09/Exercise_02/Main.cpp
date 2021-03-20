// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 2 & 3
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
#include "Main.h"

using namespace std;

int main()
{
	try
	{
		Name_Pairs p1;
		
		p1.read_names("Input names:");
		p1.read_ages("Input ages:");
		p1.sort();
		p1.print("\nPairs:");

		Name_Pairs p2;
		
		p2.read_names("Input names:");
		p2.read_ages("Input ages:");
		p2.sort();
		cout << p2;

		if (p1 == p2)
			cout << "p1 and p2 are equal\n";
		else
			cout << "p1 and p2 are not equal\n";
	}
	catch (Name_Pairs::Invalid_Pair)
	{
		cerr << "I am unable to create pairs.\n";
	}
	
	return 0;
}
