#pragma once

#include "Purchase.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>

namespace Orders
{
	class Order
	{
	public:
		// exception class
		class Invalid_order{};

		// default constructor
		Order();

		// constructor
		Order(const std::string& customer_name_,
			const std::string& home_address_,
			const std::vector<Purchases::Purchase>& purchases_);

		// nonmodifying operations
		std::string get_customer_name() const { return customer_name; }
		std::string get_home_address() const { return home_address; }
		bool has_shipped() const { return order_shipped; }
		std::vector<Purchases::Purchase> get_purchases() const { return purchases; }

		// modifying operation
		void set_shipping_status(bool status) { order_shipped = status; }

	private:
		std::string customer_name, home_address;
		bool order_shipped{ false };
		std::vector<Purchases::Purchase> purchases;
	};

	// helper functions
	bool is_valid_order(const std::string& customer_name_, const std::string& home_address_);
	std::ostream& operator<<(std::ostream& os, const Order& order);
	std::istream& operator>>(std::istream& is, Order& order);
}
