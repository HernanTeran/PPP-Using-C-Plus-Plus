// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Patron
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 5 - 9
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Create a Patron class for the library.
* The class will have a user's name, library card number, and library fees (if owed).
* Have functions that access this data, as well as a function to set the fee of the user.
* Have a helper function that returns a Boolean (bool) depending on whether or not the user owes a fee.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef PATRON_H
#define PATRON_H
#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace Local_Library
{
	class Patron
	{
	public:
		// constants
		static constexpr std::size_t MIN_NAME_LEN{ 2 };
		static constexpr std::size_t CARD_NUM_LEN{ 6 };
		static constexpr double ZERO_BAL{ 0.0 };

	public:
		// exception class
		class Invalid_Patron {};

		// constructors
		Patron();
		Patron(const std::string& full_name_, const std::string& lib_card_num_);

	public:
		// public member functions

		// nonmodifying operations
		std::string get_full_name() const { return full_name; }
		std::string get_lib_card_num() const { return lib_card_num; }
		double get_lib_fees() const { return lib_fees; }

		// modifying operation
		void set_lib_fee(double fee)
		{
			if (fee < 0) { throw Invalid_Patron{}; }
			lib_fees = fee;
		}

	private:
		std::string full_name, lib_card_num;
		double lib_fees{ 0.0 };
	};

	// helper functions
	const Patron& default_patron();
	bool is_valid_patron(const std::string& full_name, const std::string& lib_card_num);
	bool owes_fees(const Patron& patron);

	std::ostream& operator<<(std::ostream& os, const Patron& patron);
	std::istream& operator>>(std::istream& is, Patron& patron);

	bool operator==(const Patron& p1, const Patron& p2);
	bool operator!=(const Patron& p1, const Patron& p2);

	std::string name_input(std::istream& is);
	std::string lcn_input(std::istream& is);
}

#endif // PATRON_H
