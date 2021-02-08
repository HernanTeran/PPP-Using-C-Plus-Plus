#pragma once
#include <string>

namespace Patrons
{
	class Patron
	{
	public:
		class Invalid{};

		Patron() = delete;

		Patron(const std::string& full_name_, int account_number_);

		// nonmodifying operations
		std::string get_full_name() const { return full_name; }
		int get_account_number() const { return account_number; }
		double get_library_fees() const { return library_fee; }

		// modifying operation
		void set_fee(double library_fee_)
		{
			if (library_fee_ < 0) { throw Invalid{}; }
			library_fee = library_fee_;
		}

	private:
		std::string full_name;
		int account_number{ 0 };
		double library_fee{ 0 };
	};

	// helper functions
	bool is_valid_patron(const std::string& full_name_, int account_number_);
	bool owes_fees(const Patron& patron);

	bool operator == (const Patron& obj1, const Patron& obj2);
	bool operator != (const Patron& obj1, const Patron& obj2);
}
