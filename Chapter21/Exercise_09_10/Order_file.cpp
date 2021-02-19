#include "Order_file.h"

namespace Order_files
{
	Order_file::Order_file()
	{
	}

	Order_file::Order_file(const std::string& f_name_)
		: f_name{f_name_}
	{
		if (!is_valid_f_name(f_name_)) { throw Invalid_file{}; }
	}

	bool is_valid_f_name(const std::string& f_name)
	{
		std::regex pat{ R"(\w+.txt)" };
		if (!std::regex_match(f_name, pat)) { return false; }
		return true;
	}

	std::istream& operator>>(std::istream& is, Order_file& order_file)
	{
		std::cout << "Please enter a file name: ";
		std::string f_name;
		is >> f_name;

		if (!is)
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		order_file = Order_file{ f_name };

		return is;
	}

	void Order_file::write_file(const Orders::Order& order)
	{
		std::ofstream ofs{ f_name, std::ios::app };
		if (!ofs) { throw Invalid_file{}; }

		ofs << order.get_customer_name() << '\n'
			<< order.get_home_address() << '\n';
		for (const auto& purchase : order.get_purchases())
		{
			ofs << purchase.get_product_name() << '\n'
				<< purchase.get_unit_price() << '\n'
				<< purchase.get_count() << '\n';
		}

		if (ofs) { std::cout << "Writing to file complete.\n\n"; }
	}

	void Order_file::read_file(const Orders::Order& order, std::vector<Orders::Order>& orders)
	{
		std::ifstream ifs{ f_name };
		if (!ifs) { throw Invalid_file{}; }

		std::string first_name, last_name, full_name,
			street_number, street_name, street_suffix, home_address;

		ifs >> first_name >> last_name >> street_number >> street_name >> street_suffix;

		full_name = first_name + ' ' + last_name;
		home_address = street_number + ' ' + street_name + ' ' + street_suffix;

		std::vector<Purchases::Purchase> purchases;
		std::string product_name;
		double unit_price{ 0 };
		int count{ 0 };

		while (ifs >> product_name >> unit_price >> count)
		{
			purchases.push_back(Purchases::Purchase{ product_name, unit_price, count });
			ifs.clear();
		}

		if (ifs.eof()) { std::cout << "Reading from file complete.\n\n"; }
		orders.push_back(Orders::Order{ full_name, home_address, purchases });
	}
}
