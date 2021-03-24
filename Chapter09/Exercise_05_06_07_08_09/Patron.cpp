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

using namespace std;

namespace Local_Library
{
	Patron::Patron() : full_name{ default_patron().get_full_name() },
		               lib_card_num{ default_patron().get_lib_card_num() }
	{
	}

	Patron::Patron(const string& full_name_, const string& lib_card_num_)
		: full_name{ full_name_ }, lib_card_num{ lib_card_num_ }
	{
		if (!is_valid_patron(full_name_, lib_card_num_)) { throw Invalid_Patron{}; }
	}

	const Patron& default_patron()
	{
		static Patron patron{ "Unknown Name", "000000" };
		return patron;
	}

	bool is_valid_patron(const string& full_name, const string& lib_card_num)
	{
		if (full_name.length() < Patron::MIN_NAME_LEN) { return false; }
		if (lib_card_num.length() != Patron::CARD_NUM_LEN) { return false; }

		regex name_pat{ R"([A-Z][a-z]+ [A-Z][a-z]+)" };
		if (!regex_match(full_name, name_pat)) { return false; }

		regex num_pat{ R"([0-9]{6})" };
		if (!regex_match(lib_card_num, num_pat)) { return false; }

		return true;
	}

	bool owes_fees(const Patron& patron)
	{
		if (patron.get_lib_fees() == patron.ZERO_BAL) { return false; }
		return true;
	}

	ostream& operator<<(ostream& os, const Patron& patron)
	{
		return os
			<< "\n[Patron]\n"
			<< "[Name: " << patron.get_full_name() << "]\n"
			<< "[LC #: " << patron.get_lib_card_num() << "]\n"
			<< "[Fees owed: $" << patron.get_lib_fees() << "]\n";
	}

	istream& operator>>(istream& is, Patron& patron)
	{
		string full_name = name_input(is);
		string lib_card_num = lcn_input(is);

		patron = Patron{ full_name, lib_card_num };

		return is;
	}

	bool operator==(const Patron& p1, const Patron& p2)
	{
		return p1.get_lib_card_num() == p2.get_lib_card_num();
	}

	bool operator!=(const Patron& p1, const Patron& p2)
	{
		return p1.get_lib_card_num() != p2.get_lib_card_num();
	}

	string name_input(istream& is)
	{
		string first_name, last_name;
		cout << "[Full name]: ";

		is >> first_name >> last_name;

		if (is.eof())
		{
			is.clear();
			throw Patron::Invalid_Patron{};
		}

		if (!is)
		{
			is.clear();
			is.ignore();
			throw Patron::Invalid_Patron{};
		}

		return first_name + ' ' + last_name;
	}

	string lcn_input(istream& is)
	{
		string lib_card_num;
		cout << "[LC #]: ";
		is >> lib_card_num;

		if (is.eof())
		{
			is.clear();
			throw Patron::Invalid_Patron{};
		}

		return lib_card_num;
	}
}
