#include "Patron.h"

namespace Patrons
{
	using std::string;

	Patron::Patron::Patron(const string& name_, int acc_num_, double lib_fees_)
		: name(name_), acc_num(acc_num_), lib_fees(lib_fees_)
	{
		if (!is_valid_patron(name_, acc_num_, lib_fees_)) { throw Invalid{}; };
	}

	bool Patrons::owes_fee(const Patron& patron)
	{
		constexpr double zero_balance{ 0 };
		if (patron.get_lib_fees() == zero_balance) { return false; }

		return true;
	}

	void pay_fee(Patron& patron)
	{
		using std::cout;
		using std::cin;

		cout << "You're current outstanding balance is: $" << patron.get_lib_fees() << '\n';
		cout << "Would you like to pay your fee now? (Y/N)\n";

		for (char yes_no{ '0' }; cin >> yes_no; )
		{
			if (yes_no == 'Y' || yes_no == 'y')
			{
				for (double cash{ 0 }; cin >> cash; )
				{
					double settle_bal{ 0 };
					settle_bal = patron.get_lib_fees() - cash;
					patron.set_lib_fee(settle_bal);
					cout << "Your balance is now $" << patron.get_lib_fees() << '\n';

					constexpr double zero_balance{ 0 };
					// in case full amount wasn't paid
					while (patron.get_lib_fees() != zero_balance)
					{
						cout << "You still have an outstanding balance of $" << patron.get_lib_fees() << '\n';
						cout << "Would you like to pay the rest of your fee now? (Y/N)\n";
						cin >> yes_no;
						if (yes_no == 'Y' || yes_no == 'y')
						{
							cin >> cash;
							settle_bal = patron.get_lib_fees() - cash;
							patron.set_lib_fee(settle_bal);
						}
					}
					if (patron.get_lib_fees() == zero_balance)
					{
						cout << "Your balance has been paid in full! Thank you.\n\n";
						return;
					}
				}
			}
		}
	}

	bool is_valid_patron(const string& name, int acc, double lib)
	{
		// test name for valid length ---------------------------------
		constexpr int min_name_len{ 5 };

		if (name.length() < min_name_len) { return false; }
		
		// test name for valid characters -----------------------------
		for (const auto& c : name)
		{
			if (!isalpha(c) && !isspace(c))
			{
				std::cerr << "[Error: invalid name input]\n";
				return false;
			}
		}

		// test account number for valid integer range
		if (acc < 0)
		{
			std::cerr << "[Error: invalid account number]\n";
			return false;
		}

		// test account number for valid length of 6 digits
		string str_acc_number = std::to_string(acc);
		constexpr int acc_number_len{ 6 };

		if (str_acc_number.length() != acc_number_len)
		{
			std::cerr << "[Error: invalid account digit length]\n";
			return false;
		}

		// test library fees for valid monetary value
		if (lib < 0)
		{
			std::cerr << "[Error: invalid library fee input]\n";
			return false;
		}

		return true;
	}
}
