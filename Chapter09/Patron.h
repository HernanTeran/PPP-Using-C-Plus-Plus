#pragma once

#include <string>
#include <iostream>

namespace Patrons
{
	class Patron
	{
	private:
		std::string name;
		int acc_num;
		double lib_fees;

	public:
		Patron() = delete;

		Patron(const std::string& name_, int acc_num_, double lib_fees_);

		// nonmodifying operations
		std::string get_patron_name() const { return name; }
		int get_acc_num() const { return acc_num; }
		double get_lib_fees() const { return lib_fees; }

		// modifying operation
		void set_lib_fee(double fee)
		{
			while (fee < 0) { std::cin >> fee; }
			lib_fees = fee;
		}
	};

	bool owes_fee(const Patron& patron);
	void pay_fee(Patron& patron);
	bool is_valid_patron(std::string& name, int acc, double lib);
}
