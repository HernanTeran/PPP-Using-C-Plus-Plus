// Hernan Teran
// V1 - 2/15/2021

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using std::cout;
using std::string;
using std::cin;
using std::cerr;
using std::vector;

#include "Order.h"
#include "Purchase.h"
#include "File.h"

void run();

// TO-DO:
// use a while-loop and a menu to run the program
// create a function to create an order
// create a function to create a purchase and it to a vector<Purchase>
// create a function to simulate a day passing and then setting shipping status to shipped
// create functions to get file names and read/write files
// create a struct of files

int main()
{
	run();

	return 0;
}

void run()
{
	using Purchases::Purchase;
	using Orders::Order;
	using Files::File;

	try
	{
		// orders/purchases -------------------------------------------------------------------
		vector<Purchase> purchases_linda{ Purchase{"cranberry sauce", 12.99, 1},
									Purchase{"fish sauce", 8.87, 3},
									Purchase{"mashed potatoes", 5.99, 4} };
		Order order_linda{ "Linda Belcher", "123 Burger St.", purchases_linda };
		order_linda.set_status(false);

		vector<Purchase> purchases_tina{ Purchase{"toy horse", 34.55, 6},
									Purchase{"movie tickets", 51.32, 3},
									Purchase{"french fries", 4.99, 1} };

		Order order_tina{ "Tina Belcher", "123 Burger St.", purchases_tina };
		order_tina.set_status(true);

		vector<Purchase> purchases_bob{ Purchase{"turkey", 21.99, 2},
									Purchase{"soy sauce", 4.99, 5},
									Purchase{"radishes", 2.36, 10} };

		Order order_bob{ "Bob Belcher", "123 Burger St.", purchases_bob };
		order_bob.set_status(true);

		// write/read files -------------------------------------------------------------------

		File file_linda{ order_linda };
		file_linda.set_f_name("Please enter the output file name:\n");
		file_linda.write_file();

		File file_tina{ order_tina };
		file_tina.set_f_name("Please enter the output file name:\n");
		file_tina.write_file();

		File file_bob{ order_bob };
		file_bob.set_f_name("Please enter the output file name:\n");
		file_bob.write_file();

		// use vector of orders ----------------------------------------------------------------

		vector<Order> orders;

		file_linda.set_f_name("Please enter the input file name:\n");
		file_linda.read_file(orders);

		file_tina.set_f_name("Please enter the input file name:\n");
		file_tina.read_file(orders);

		file_bob.set_f_name("Please enter the input file name:\n");
		file_bob.read_file(orders);

		std::sort(orders.begin(), orders.end(),
			[](const Order& left, const Order& right) {return left.get_customer_name() < right.get_customer_name(); });

		for (const auto& order : orders) { print_order(order); }

	}
	catch (Order::Invalid_Order)
	{
		cerr << "error invalid order\n";
	}
	catch (Purchase::Invalid_Purchase)
	{
		cerr << "error invalid purchase\n";
	}
	catch (File::Invalid_file)
	{
		cerr << "error invalid file\n";
	}
}
