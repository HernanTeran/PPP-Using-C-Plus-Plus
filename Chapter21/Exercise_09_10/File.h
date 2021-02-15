#pragma once
#include "Order.h"
#include "Purchase.h"
#include <string>
#include <vector>
#include <sstream>
#include <regex>

// create another file of 10 orders of which about a third are the same as the vector file
// create a list<Order> and sort it by address and write it out to a file
// merge both files into a third using std::merge()
// compute the total value of the orders from both files (unit_price * count)

namespace Files
{
	class File
	{
	public:
		class Invalid_file{};

		File() = delete;

		File(const Orders::Order& order_);

		// nonmodifying operation
		std::string get_f_name() const { return f_name; }

		// modifying operation
		void set_f_name(const std::string& prompt);

		void write_file();
		void read_file(std::vector<Orders::Order>& orders);
	private:
		std::string f_name;
		Orders::Order order;
	};

	bool is_valid_f_name(const std::string& f_name);
}