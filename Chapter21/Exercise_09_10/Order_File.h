// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Order_File
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Define a mechanism for reading and writing Orders to and from a file.
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef ORDER_FILE_H
#define ORDER_FILE_H
#pragma once

#include "Order.h"
#include "Purchase.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <regex>

namespace Order_Files
{
	class Order_File
	{
	public:
		// exception class
		class Invalid_file {};

		// default constructor
		Order_File();

		// constructor
		Order_File(const std::string& f_name_);

		//--------------------------------------------------------------
		// Public member functions
		//--------------------------------------------------------------
		void write_file(const Orders::Order& order);
		void read_file(const Orders::Order& order, std::vector<Orders::Order>& orders);
		void read_file(const Orders::Order& order, std::list<Orders::Order>& orders);

	private:
		std::string f_name;
	};

	bool is_valid_f_name(const std::string& f_name);
	std::istream& operator>>(std::istream& is, Order_File& order_file);
}

#endif // ORDER_FILE_H
