#include "Patron.h"

namespace Patrons
{
	Patron::Patron(const std::string& full_name_, int account_number_)
		:
		full_name{full_name_}, account_number{account_number_}
	{
		if (!is_valid_patron(full_name_, account_number_)) { throw Invalid{}; }
	}

	bool is_valid_patron(const std::string& full_name_, int account_number_)
	{
		// test full_name_ ---------------------------------------------------
		constexpr int min_name_len{ 5 };

		if (full_name_.length() < min_name_len) { return false; }

		// test account_number_ -----------------------------------------------
		constexpr int acc_num_len{ 6 };
		std::string acc_num_str = std::to_string(account_number_);

		if (acc_num_str.length() != acc_num_len) { return false; }

		return true;
	}

	bool owes_fees(const Patron& patron)
	{
		constexpr double zero_balance{ 0 };
		if (patron.get_library_fees() == zero_balance) { return false; }

		return true;
	}

	bool operator==(const Patron& obj1, const Patron& obj2) 
	{ 
		return obj1.get_account_number() == obj2.get_account_number();
	}

	bool operator!=(const Patron& obj1, const Patron& obj2)
	{
		return !(obj1.get_account_number() == obj2.get_account_number());
	}
}
