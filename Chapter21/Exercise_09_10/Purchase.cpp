#include "Purchase.h"

namespace Purchases
{
	Purchase::Purchase() : unit_price{0}, count{0}
	{
	}

	Purchase::Purchase(const std::string& product_name_, double unit_price_, int count_)
		: product_name{product_name_}, unit_price{unit_price_}, count{count_}
	{
		if (!is_valid_purchase(product_name_, unit_price_, count_)) { throw Invalid_purchase{}; }
	}

	bool is_valid_purchase(const std::string& product_name_, double unit_price_, int count_)
	{
		std::regex pat{ R"(\w+ ?\w*)" };
		if (!std::regex_match(product_name_, pat)) { return false; }
		if (unit_price_ <= 0) { return false; }
		if (count_ <= 0) { return false; }

		return true;
	}

	std::ostream& operator<<(std::ostream& os, const Purchase& purchase)
	{
		return os << "{Product name: " << purchase.get_product_name() << "}\n"
			      << "{Unit price: $" << purchase.get_unit_price() << "}\n"
			      << "{Total ordered: " << purchase.get_count() << "}\n\n";
	}

	std::istream& operator>>(std::istream& is, Purchase& purchase)
	{
		std::cout << "Enter product name: ";
		std::string product_name;
		is >> product_name;

		std::cout << "Enter unit price: $";
		double unit_price{ 0 };
		is >> unit_price;

		std::cout << "Enter total bought: ";
		int count{ 0 };
		is >> count;

		if (!is)
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		purchase = Purchase{ product_name, unit_price, count };

		return is;
	}
}
