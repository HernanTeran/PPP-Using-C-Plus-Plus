#include "Patron.h"

namespace Patrons
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::cerr;

	Patron::Patron::Patron(const string& name_, int acc_num_, double lib_fees_)
		: name(name_), acc_num(acc_num_), lib_fees(lib_fees_)
	{
		string temp_name{ name_ };
		if (!is_valid_patron(temp_name, acc_num_, lib_fees_)) { cerr << "[ERROR]\n"; }
	}

	bool Patrons::owes_fee(const Patron& patron)
	{
		constexpr double zero_balance{ 0 };
		if (patron.get_lib_fees() == zero_balance) { return false; }
		
		return true;
	}

	void pay_fee(Patron& patron)
	{
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
					const double zero_balance{ 0 };
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
						else { return; }
					}
					if (patron.get_lib_fees() == zero_balance)
					{
						cout << "Your balance has been paid in full! Thank you.\n\n";
						return;
					}
				}
			}
			else
			{
				return;
			}
		}
	}

	bool is_valid_patron(string& name, int acc, double lib)
	{
		for (const auto& c : name)
		{
			if (!isalpha(c))
			{
				cerr << "[Error]: invalid name input. Try again:\n";
				getline(cin, name);
			}
		}

		while (acc < 0)
		{
			cerr << "[Error]: invalid account number. Try again:\n";
			cin >> acc;
		}

		while (lib < 0)
		{
			cerr << "[Error]: invalid library fee input. Try again:\n";
			cin >> lib;
		}
		return true;
	}
}
