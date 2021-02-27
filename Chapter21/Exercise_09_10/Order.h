// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Order
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Define an Order class with (customer) name, address, data, and vector<Purchase> members.
* Purchase is a class with a (product) name, unit_price, and count members.
* Define a mechanism for reading and writing Orders to and from a file.
* Define a mechanism for printing Orders.
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
* Merge the two files into a third using std::merge().
* Compute the total value of the orders in the two files.
* The value of an individual Purchase is its unit_price * count.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef ORDER_H
#define ORDER_H
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
		class Invalid_order {};

		Order();

		Order(const std::string& customer_name_,
			const std::string& home_address_,
			const std::vector<Purchases::Purchase>& purchases_);

		//------------------------------------------------------
		// Public member functions
		//------------------------------------------------------

		// nonmodifying operations
		inline std::string get_customer_name() const { return customer_name; }
		inline std::string get_home_address() const { return home_address; }
		inline bool has_shipped() const { return order_shipped; }
		inline std::vector<Purchases::Purchase> get_purchases() const { return purchases; }

		// modifying operation
		inline void set_shipping_status(bool status) { order_shipped = status; }

	private:
		std::string customer_name, home_address;
		bool order_shipped{ false };
		std::vector<Purchases::Purchase> purchases;
	};

	bool is_valid_order(const std::string& customer_name_, const std::string& home_address_);

	std::ostream& operator<<(std::ostream& os, const Order& order);
	std::istream& operator>>(std::istream& is, Order& order);
}

#endif // ORDER_H
