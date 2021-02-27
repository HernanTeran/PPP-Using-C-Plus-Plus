// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Purchase
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Purchase is a class with a (product) name, unit_price, and count members.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef PURCHASE_H
#define PURCHASE_H
#pragma once

#include <iostream>
#include <string>
#include <regex>

namespace Purchases
{
	class Purchase
	{
	public:
		// exception class
		class Invalid_purchase{};

		// default constructor
		Purchase();

		// constructor
		Purchase(const std::string& product_name_,
			     double unit_price_,
			     int count_);

		//----------------------------------------------------------------------
		// Public member functions
		//----------------------------------------------------------------------

		// nonmodifying operations
		inline std::string get_product_name() const { return product_name; }
		inline double get_unit_price() const { return unit_price; }
		inline int get_count() const { return count; }

	private:
		std::string product_name;
		double unit_price{ 0 };
		int count{ 0 };
	};

	bool is_valid_purchase(const std::string& product_name_, double unit_price_, int count_);

	std::ostream& operator<<(std::ostream& os, const Purchase& purchase);
	std::istream& operator>>(std::istream& is, Purchase& purchase);
}

#endif // PURCHASE_H
