#pragma once

#include "Order.h"
#include "Purchase.h"
#include "Order_file.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>

namespace All_orders
{
	struct Order_data
	{
		// member data
		std::size_t orders_to_add{ 0 };
		std::vector<Orders::Order> v_orders;
		std::list<Orders::Order> l_orders;
		std::vector<Orders::Order> combined_orders;
		Order_files::Order_file combined_file;
		double total_sum{ 0 };

		// member functions
		void create_v_orders(const std::string& prompt);
		void create_l_orders(const std::string& prompt);
		void write_v_file();
		void write_l_file();
		void merge_files();
		void compute_v_sum();
		void compute_l_sum();
		void print_sum(const std::string& message);
	};
}