#include "File.h"
#include <fstream>
#include <string>

namespace Files
{
	File::File( const Orders::Order& order_) : order{order_}
	{
	}

	bool is_valid_f_name(const std::string& f_name)
	{
		std::regex pat{ R"(\w+.txt)" };
		if (!std::regex_match(f_name, pat)) { return false; }

		return true;
	}

	void File::set_f_name(const std::string& prompt)
	{
		std::cout << prompt;
		for (std::string temp_f_name; std::cin >> temp_f_name;)
		{ 
			if (!is_valid_f_name(temp_f_name)) { throw Invalid_file{}; }
			f_name = temp_f_name; 
			break;
		}
	}

	void File::write_file()
	{
		std::ofstream ofs{ f_name };
		if (!ofs) { throw Invalid_file{}; }

		ofs << order.get_customer_name() << '\n'
			<< order.get_address() << '\n'
			<< order.get_shipping_status() << '\n';

		for (const auto& o : order.get_purchases())
		{
			ofs << o.get_product_name() << '\n'
				<< o.get_unit_price() << '\n'
				<< o.get_count() << '\n';
		}

		if (ofs.eof()) { std::cout << "{writing to file complete}\n"; }
	}

	void File::read_file(std::vector<Orders::Order>& orders)
	{
		std::ifstream ifs{ f_name };
		if (!ifs) { throw Invalid_file{}; }

		std::string full_name, home_address, shipping_status, product_name;
		double unit_price{ 0 };
		int count{ 0 };

		getline(ifs, full_name);
		getline(ifs, home_address);
		getline(ifs, shipping_status);

		std::vector<Purchases::Purchase> purchases;
		
		for (product_name; getline(ifs, product_name);)
		{
			for (unit_price; ifs >> unit_price;)
			{
				for (count; ifs >> count;)
				{
					purchases.push_back(Purchases::Purchase{ product_name, unit_price, count });
				}
			}
			ifs.clear();
		}
		
		if (ifs.eof()) { std::cout << "{reading from file complete}\n"; }
		orders.push_back(Orders::Order{ full_name, home_address, shipping_status, purchases });
	}
}