#include "Order.h"

namespace Orders
{
	Order::Order() : order_shipped{ false }
	{
	}

	Order::Order(const std::string& customer_name_,
		const std::string& home_address_,
		const std::vector<Purchases::Purchase>& purchases_)
		:
		customer_name{ customer_name_ }, home_address{ home_address_ }, purchases{ purchases_ }
	{
		if (!is_valid_order(customer_name_, home_address_)) { throw Invalid_order{}; }
	}

	bool is_valid_order(const std::string& customer_name_, const std::string& home_address_)
	{
		std::regex customer_pat{ R"([A-Za-z]+ [A-Za-z]+)" };
		if (!std::regex_match(customer_name_, customer_pat)) { return false; }

		std::regex address_pat{ R"([0-9]+ \w+ (St|Rd|Pl|Ln|Rd|Ct|Ave).)" };
		if (!std::regex_match(home_address_, address_pat)) { return false; }

		return true;
	}

	std::ostream& operator<<(std::ostream& os, const Order& order)
	{
		os << "\t {ORDER}\n"
			<< "{Customer name: " << order.get_customer_name() << "}\n"
			<< "{Home address: " << order.get_home_address() << "}\n\n";
		
		for (const auto& purchase : order.get_purchases())
		{
			os << purchase;
		}

		return os;
	}

	std::istream& operator>>(std::istream& is, Order& order)
	{
		std::cout << "Enter customer name: ";
		std::string first_name, last_name, full_name;
		is >> first_name >> last_name;
		full_name = first_name + ' ' + last_name;

		std::cout << "Enter home address: ";
		std::string street_number, street_name, street_suffix, home_address;
		is >> street_number >> street_name >> street_suffix;
		home_address = street_number + ' ' + street_name + ' ' + street_suffix;

		if (!is)
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		std::vector<Purchases::Purchase> purchases;
		Purchases::Purchase purchase;
		is >> purchase;
		purchases.push_back(purchase);

		char add_order{ '0' };

		while (add_order != 'n')
		{
			std::cout << "Would you like to add another purchase (y/n): ";
			is.ignore();
			is.get(add_order);

			switch (add_order)
			{
			case 'y':
				is >> purchase;
				purchases.push_back(purchase);
				break;
			case 'n':
				std::cout << "Completing order...\n\n";
				break;
			default:
				std::cerr << "Unknown input. Try again.\n";
				break;
			}
		}

		order = Order{ full_name, home_address, purchases };

		return is;
	}
}
