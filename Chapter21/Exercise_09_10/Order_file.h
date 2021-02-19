#pragma once

#include "Order.h"
#include "Purchase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <regex>

namespace Order_files
{
	class Order_file
	{
	public:
		// exception class
		class Invalid_file{};

		// default constructor
		Order_file();

		// constructor
		Order_file(const std::string& f_name_);

		// write file
		void write_file(const Orders::Order& order);

		// read file and store into vector
		void read_file(const Orders::Order& order, std::vector<Orders::Order>& orders);

		// read file and store into list
		void read_file(const Orders::Order& order, std::list<Orders::Order>& orders);

	private:
		std::string f_name;
	};

	// helper functions
	bool is_valid_f_name(const std::string& f_name);
	std::istream& operator>>(std::istream& is, Order_file& order_file);
}
