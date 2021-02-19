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

		// nonmodifying operations
		std::string get_product_name() const { return product_name; }
		double get_unit_price() const { return unit_price; }
		int get_count() const { return count; }

	private:
		std::string product_name;
		double unit_price{ 0 };
		int count{ 0 };
	};

	// helper functions
	bool is_valid_purchase(const std::string& product_name_, double unit_price_, int count_);
	std::ostream& operator<<(std::ostream& os, const Purchase& purchase);
	std::istream& operator>>(std::istream& is, Purchase& purchase);
}
