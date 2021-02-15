#include "Purchase.h"

namespace Purchases
{
	Purchase::Purchase(const std::string& product_name_, 
					   double unit_price_, 
					   int count_)
		: 
		product_name{product_name_}, 
		unit_price{unit_price_}, 
		count{count_}
	{
		if (!is_valid_purchase(product_name_, unit_price_, count_)) { throw Invalid_Purchase{}; }
	}

	bool is_valid_purchase(const std::string& product_name, double unit_price, int count)
	{
		// testing product name ------------------------------------------------
		std::regex pat1{ R"(\w+ ?\w*)" };
		if (!std::regex_match(product_name, pat1)) { return false; }

		// testing unit_price --------------------------------------------------
		if (unit_price <= 0) { return false; }

		// testing count -------------------------------------------------------
		if (count <= 0) { return false; }

		return true;
	}
}
