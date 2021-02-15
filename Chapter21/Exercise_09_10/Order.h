#pragma once
#include "Purchase.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

namespace Orders
{
	class Order
	{
	public:
		// exception class
		class Invalid_Order{};

		// deleted default constructor
		Order() = delete;

		// constructor
		Order(const std::string& customer_name_,
			const std::string& address_,
			const std::vector<Purchases::Purchase>& purchases_);

		Order(const std::string& customer_name_,
			const std::string& address_,
			const std::string& status_,
			const std::vector<Purchases::Purchase>& purchases_);

		// nonmodifying operations
		std::string get_customer_name() const { return customer_name; }
		std::string get_address() const { return address; }
		std::string get_shipping_status() const { return status; }
		bool has_shipped() const { return shipped; }
		std::vector<Purchases::Purchase> get_purchases() const { return purchases; }

		// modifying operation
		void set_status(bool ship_status) 
		{ 
			shipped = ship_status;
			status = shipped ? "shipped" : "pending";
		}

	private:
		std::string customer_name, address, status;
		bool shipped{ false };
		std::vector<Purchases::Purchase> purchases;
	};

	bool is_valid_order(const std::string& customer_name, const std::string& address);
	void print_order(const Orders::Order& order);
};
