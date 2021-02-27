// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Name_Pair
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 2 & 3
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
#ifndef NAME_PAIR_H
#define NAME_PAIR_H
#pragma once

#include <string>
#include <iostream>
#include <vector>

namespace Name_pairs
{
	class Name_pair
	{
	public:
		// default constructor is fine

		void read_names(const std::string& prompt);
		void read_ages(const std::string& prompt);
		void print();
		void sort();
	private:
		std::vector<std::string> names;
		std::vector<double> ages;
	};
}

#endif // NAME_PAIR_H
