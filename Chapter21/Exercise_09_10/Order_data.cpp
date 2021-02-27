// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Order_Data
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
* Merge the two files into a third using std::merge().
* Compute the total value of the orders in the two files.
* The value of an individual Purchase is its unit_price * count.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Order_Data.h"

namespace Driver
{
	using namespace std;
	using namespace Orders;
	using namespace Purchases;
	using namespace Order_Files;

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::create_v_orders(const string& prompt)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function creates Orders and an Order_File. The Orders get added to a vector.
	* 
	* @param <prompt> This prompt asks the user to input how many Orders they would like to add.
	*                 Then the user inputs Orders and a file name for an Order_File.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::create_v_orders(const string& prompt)
	{
		cout << prompt;
	    cin >> orders_to_add;

		while (v_orders.size() != orders_to_add)
		{
			Order order;
			cin >> order;
			cout << order;
			Order_File order_file;
			cin >> order_file;
			order_file.write_file(order);
			cin >> order_file;
			order_file.read_file(order, v_orders);
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::create_l_orders(const string& prompt)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function creates Orders and an Order_File. The Orders get added to a list.
	*
	* @param <prompt> This prompt asks the user to input how many Orders they would like to add.
	*                 Then the user inputs Orders and a file name for an Order_File.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::create_l_orders(const string& prompt)
	{
		cout << prompt;
		cin >> orders_to_add;

		while (l_orders.size() != orders_to_add)
		{
			Order order;
			cin >> order;
			cout << order;
			Order_File order_file;
			cin >> order_file;
			order_file.write_file(order);
			cin >> order_file;
			order_file.read_file(order, l_orders);
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::write_v_file()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function sorts Orders alphabetically by customer name then writes all Orders to one combined file.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::write_v_file()
	{
	    sort(v_orders.begin(), v_orders.end(),
			[](const Order& left, const Order& right)
			{return left.get_customer_name() <= right.get_customer_name(); });

		cin >> combined_file;

		for (const auto& o : v_orders)
		{
			combined_file.write_file(o);
			cout << o;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::write_l_file()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function sorts Orders by customer home address and then writes all Orders to one combined file.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::write_l_file()
	{
		l_orders.sort([](const Order& left, const Order& right)
			{return left.get_home_address() <= right.get_home_address(); });

		cin >> combined_file;

		for (const auto& o : l_orders)
		{
			combined_file.write_file(o);
			cout << o;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::merge_files()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function merges the Orders contained in the vector and the Orders contained in the list into a vector.
	* Then the Orders in the new vector is written to a file.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::merge_files()
	{
		merge(v_orders.begin(), v_orders.end(),
			l_orders.begin(), l_orders.end(),
			back_inserter(combined_orders),
			[](Order& o1, Order& o2)
			{return o1.get_customer_name() < o2.get_customer_name(); });

		cin >> combined_file;

		for (const auto& o : combined_orders)
		{
			combined_file.write_file(o);
			cout << o;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::compute_v_sum()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function computes the sum of all the Orders in the vector.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::compute_v_sum()
	{
		for (const auto& o : v_orders)
		{
			for (const auto& p : o.get_purchases())
			{
				total_sum += (p.get_unit_price() * p.get_count());
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::compute_l_sum()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function computes the sum of all the Orders in the list.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::compute_l_sum()
	{
		for (const auto& o : l_orders)
		{
			for (const auto& p : o.get_purchases())
			{
				total_sum += (p.get_unit_price() * p.get_count());
			}
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_data::print_sum(const string& message)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function prints the total sum in dollars of all the Orders.
	*
	* @param <message> This message prints the dollar sign.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_data::print_sum(const string& message)
	{
		cout << message << total_sum << "}\n\n";
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void driver()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function runs the program and is called by main.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void driver()
	{
		try
		{
			Order_data orders;

			orders.create_v_orders("Please enter the amount of orders you would like to add: ");
			orders.write_v_file();

			orders.create_l_orders("Please enter the amount of orders you would like to add: ");
			orders.write_l_file();

			orders.merge_files();

			orders.compute_v_sum();
			orders.compute_l_sum();
			orders.print_sum("{Sum of all purchases: $");
		}
		catch (Order::Invalid_order)
		{
			std::cerr << "Invalid order\n";
		}
		catch (Purchase::Invalid_purchase)
		{
			cerr << "Invalid purchase\n";
		}
		catch (Order_File::Invalid_file)
		{
			cerr << "Invalid order file\n";
		}
		catch (...)
		{
			cerr << "Error\n";
		}
	}
}
