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

#include <string>

namespace Patrons
{
	class Patron
	{
	public:
		class Invalid_Patron{};

		Patron() = delete;

		Patron(const std::string& full_name_, int account_number_);

		//-----------------------------------------------------
		// Public member functions
		//-----------------------------------------------------

		//-----------------------------------------------------
		// Nonmodifying operations
		//-----------------------------------------------------
		inline std::string get_full_name() const { return full_name; }
		inline int get_account_number() const { return account_number; }
		inline double get_library_fees() const { return library_fee; }

		//-----------------------------------------------------
		// Modifying operation
		//-----------------------------------------------------
		inline void set_fee(double library_fee_)
		{
			if (library_fee_ < 0) { throw Invalid_Patron{}; }
			library_fee = library_fee_;
		}

	private:
		std::string full_name;
		int account_number{ 0 };
		double library_fee{ 0 };
	};

	bool is_valid_patron(const std::string& full_name_, int account_number_);
	bool owes_fees(const Patron& patron);

	bool operator == (const Patron& obj1, const Patron& obj2);
	bool operator != (const Patron& obj1, const Patron& obj2);
}

#endif // PATRON_H
