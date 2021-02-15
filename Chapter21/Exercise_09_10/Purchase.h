#pragma once
#include <string>
#include <regex>

namespace Purchases
{
	class Purchase
	{
	public:
		// exception class
		class Invalid_Purchase{};

		// deleted default constructor
		Purchase() = delete;

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

	bool is_valid_purchase(const std::string& product_name,
						   double unit_price,
						   int count);
};
