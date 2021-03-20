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

int main()
{
	try
	{
		Name_Pairs pairs;

		pairs.read_names("Input names:");
		pairs.read_ages("Input ages:");
		pairs.sort();
		pairs.print("\nPairs:");

	}
	catch (Name_Pairs::Invalid_Pair)
	{
		cerr << "I am unable to create pairs.\n";
	}

	return 0;
}
