// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Name_Pair
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
#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H
#pragma once

#include <vector>
#include <string>
#include <iostream>

class Name_Pairs
{
public:
	// exception class
	class Invalid_Pair{};
	
	// nonmodifying operations
	size_t get_sz() const { return DATA_SZ; }
	std::vector<std::string> get_names() const { return name; }
	std::vector<int> get_ages() const { return age; }
	
	// modifying operations
	void read_names(const std::string& prompt);
	void read_ages(const std::string& prompt);
	void sort();
	void print(const std::string& prompt);

protected:
	size_t DATA_SZ{ 0 };
	size_t data_sz(const std::string& prompt);

private:
	std::vector<std::string> name;
	std::vector<int> age;
};

// helper functions
std::ostream& operator<<(std::ostream& os, const Name_Pairs& pairs);

bool operator==(const Name_Pairs& lp, const Name_Pairs& rp);
bool operator!=(const Name_Pairs& lp, const Name_Pairs& rp);

#endif // NAME_PAIRS_H
