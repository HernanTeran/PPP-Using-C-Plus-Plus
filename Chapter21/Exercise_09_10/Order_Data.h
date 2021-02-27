// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Order_Data
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
* Merge the two files into a third using std::merge().
* Compute the total value of the orders in the two files.
* The value of an individual Purchase is its unit_price * count.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef ORDER_DATA_H
#define ORDER_DATA_H
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

namespace Driver
{
	struct Order_data
	{
		// member data
		std::size_t orders_to_add{ 0 };
		std::vector<Orders::Order> v_orders;
		std::list<Orders::Order> l_orders;
		std::vector<Orders::Order> combined_orders;
		Order_Files::Order_File combined_file;
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

	void driver();
}

#endif 
