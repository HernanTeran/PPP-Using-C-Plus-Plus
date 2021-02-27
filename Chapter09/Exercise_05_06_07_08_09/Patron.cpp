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
#include "Patron.h"

namespace Patrons
{
	using std::string;

	//------------------------------------------------------------------------------------------------------------------------------
	// Patron::Patron(const string& full_name_, int account_number_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* A patron is created by having a full name and valid 6 digit account number.
	* 
	* @param <full_name_>      input first name and last name
	* @param <account_number_> input a 6 digit account number
	* 
	* @exception Invalid_Patron exception is thrown if one or both members are invalid.
	* 
	* @note The default constructor is deleted because you cannot have a default person.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Patron::Patron(const string& full_name_, int account_number_)
		:
		full_name{ full_name_ }, account_number{ account_number_ }
	{
		if (!is_valid_patron(full_name_, account_number_)) { throw Invalid_Patron{}; }
	}

	//-----------------------------------------------------
	// Helper functions
	//-----------------------------------------------------

	//------------------------------------------------------------------------------------------------------------------------------
	// bool is_valid_patron(const string& full_name_, int account_number_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function validates the input for the constructor.
	*
	* @param <full_name_>      input first name and last name
	* @param <account_number_> input a 6 digit account number
	*
	* @note test: 1) full_name_ 2) account_number_
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool is_valid_patron(const string& full_name_, int account_number_)
	{
		constexpr int min_name_len{ 5 };

		if (full_name_.length() < min_name_len) { return false; }

		constexpr int acc_num_len{ 6 };
		string acc_num_str = std::to_string(account_number_);

		if (acc_num_str.length() != acc_num_len) { return false; }

		return true;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// bool owes_fees(const Patron& patron)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function checks whether a patron owes fees or not.
	*
	* @param <patron> input valid patron
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool owes_fees(const Patron& patron)
	{
		constexpr double zero_balance{ 0 };
		if (patron.get_library_fees() == zero_balance) { return false; }

		return true;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// bool operator==(const Patron& obj1, const Patron& obj2)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the == (equality) operator to compare patrons.
	*
	* @param <obj1> input valid patron
	* @param <obj2> input valid patron
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool operator==(const Patron& obj1, const Patron& obj2)
	{
		return obj1.get_account_number() == obj2.get_account_number();
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// bool operator!=(const Patron& obj1, const Patron& obj2)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the != (inequality) operator to compare patrons.
	*
	* @param <obj1> input valid patron
	* @param <obj2> input valid patron
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool operator!=(const Patron& obj1, const Patron& obj2)
	{
		return !(obj1.get_account_number() == obj2.get_account_number());
	}
}
