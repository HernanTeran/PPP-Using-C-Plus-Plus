#include "Order.h"

namespace Orders
{
	Order::Order(const std::string& customer_name_, 
		         const std::string& address_, 
		         const std::vector<Purchases::Purchase>& purchases_)
		:
		customer_name{customer_name_},
		address{address_},
		purchases{ purchases_ }
	{
		if (!is_valid_order(customer_name_, address_)) { throw Invalid_Order{}; };
	}

	Order::Order(const std::string& customer_name_, 
				const std::string& address_, 
				const std::string& status_, 
				const std::vector<Purchases::Purchase>& purchases_)
		:
		customer_name{customer_name_},
		address{address_},
		status{status_},
		purchases{purchases_}
	{
		if (!is_valid_order(customer_name_, address_)) { throw Invalid_Order{}; };
	}

	bool is_valid_order(const std::string& customer_name, const std::string& address)
	{
		// testing customer name ------------------------------------------------
		std::regex pat1{ R"([a-zA-Z]+ [a-zA-z]+)" };
		if (!std::regex_match(customer_name, pat1)) { return false; }

		// testing customer address ---------------------------------------------
		std::regex pat2{ R"([0-9]+ \w+ (St|Rd|Pl|Ln|Rd|Ct|Ave).)" };
		if (!std::regex_match(address, pat2)) { return false; }

		// purchases have already been tested in their class --------------------

		return true;
	}

	void print_order(const Orders::Order& order)
	{
		std::cout
			<< "\t {ORDER}\n"
			<< "==============================\n"
			<< "{Full name: " << order.get_customer_name() << "}\n"
			<< "{Home address: " << order.get_address() << "}\n"
			<< "{Shipping status: " << order.get_shipping_status() << "}\n\n";

		for (const auto& p : order.get_purchases())
		{
			std::cout
				<< "{Product name: " << p.get_product_name() << "}\n"
				<< "{Unit price: $" << p.get_unit_price() << "}\n"
				<< "{Units ordered: " << p.get_count() << "}\n";
		}
		std::cout << '\n';
	}
}
