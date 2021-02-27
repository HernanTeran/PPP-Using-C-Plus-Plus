// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Order_File
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Define a mechanism for reading and writing Orders to and from a file.
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Order_file.h"

namespace Order_Files
{
	using namespace std;

	using Orders::Order;
	using Purchases::Purchase;

	//------------------------------------------------------------------------------------------------------------------------------
	// Order_File::Order_File()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* default constructor
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Order_File::Order_File()
	{
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// Order_File::Order_File(const string& f_name_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Constructor that takes a valid file name to establish invariant.
	* 
	* @param <f_name_> input a valid file name
	* 
	* @exception Invalid_file is thrown if file name is not found or is not a .txt file.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Order_File::Order_File(const string& f_name_) : f_name{ f_name_ }
	{
		if (!is_valid_f_name(f_name_)) { throw Invalid_file{}; }
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// bool is_valid_f_name(const string& f_name)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function validates a file name using a regular expressions.
	*
	* @param <f_name> input a valid file name with .txt suffic
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool is_valid_f_name(const string& f_name)
	{
		regex pat{ R"(\w+.txt)" };
		if (!regex_match(f_name, pat)) { return false; }
		return true;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// istream& operator>>(istream& is, Order_File& order_file)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the >> (insertion) operator to get user input to construct an Order File.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	istream& operator>>(istream& is, Order_File& order_file)
	{
		cout << "Please enter a file name: ";
		string f_name;
		is >> f_name;

		if (!is)
		{
			is.clear(ios_base::failbit);
			return is;
		}

		order_file = Order_File{ f_name };

		return is;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_File::write_file(const Order& order)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function writes a file that contains an Order.
	* 
	* @param <order> input valid Order object
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_File::write_file(const Order& order)
	{
		ofstream ofs{ f_name, ios::app };
		if (!ofs) { throw Invalid_file{}; }

		ofs << order.get_customer_name() << '\n'
			<< order.get_home_address() << '\n';
		for (const auto& purchase : order.get_purchases())
		{
			ofs << purchase.get_product_name() << '\n'
				<< purchase.get_unit_price() << '\n'
				<< purchase.get_count() << '\n';
		}

		if (ofs) { cout << "Writing to file complete.\n\n"; }
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_File::read_file(const Order& order, vector<Order>& orders)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function reads a file that contains an Order and stores it in a vector.
	*
	* @param <order>  input valid Order object
	* @param <orders> vector of valid Order objects
	* 
	* @exception Invalid_file is thrown if file name is not found or a .txt file.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_File::read_file(const Order& order, vector<Order>& orders)
	{
		ifstream ifs{ f_name };
		if (!ifs) { throw Invalid_file{}; }

		string first_name, last_name, full_name,
			street_number, street_name, street_suffix, home_address;

		ifs >> first_name >> last_name >> street_number >> street_name >> street_suffix;

		full_name = first_name + ' ' + last_name;
		home_address = street_number + ' ' + street_name + ' ' + street_suffix;

		vector<Purchase> purchases;
		string product_name;
		double unit_price{ 0 };
		int count{ 0 };

		while (ifs >> product_name >> unit_price >> count)
		{
			purchases.push_back(Purchase{ product_name, unit_price, count });
			ifs.clear();
		}

		if (ifs.eof()) { cout << "Reading from file complete.\n\n"; }
		orders.push_back(Order{ full_name, home_address, purchases });
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Order_File::read_file(const Order& order, list<Order>& orders)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function reads a file that contains an Order and stores it in a list.
	*
	* @param <order>  input valid Order object
	* @param <orders> list of valid Order objects
	* 
	* @exception Invalid_file is thrown if file name is not found or a .txt file.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Order_File::read_file(const Order& order, list<Order>& orders)
	{
		ifstream ifs{ f_name };
		if (!ifs) { throw Invalid_file{}; }

		string first_name, last_name, full_name,
			street_number, street_name, street_suffix, home_address;

		ifs >> first_name >> last_name >> street_number >> street_name >> street_suffix;

		full_name = first_name + ' ' + last_name;
		home_address = street_number + ' ' + street_name + ' ' + street_suffix;

		vector<Purchase> purchases;
		string product_name;
		double unit_price{ 0 };
		int count{ 0 };

		while (ifs >> product_name >> unit_price >> count)
		{
			purchases.push_back(Purchase{ product_name, unit_price, count });
			ifs.clear();
		}

		if (ifs.eof()) { cout << "Reading from file complete.\n\n"; };
		orders.push_back(Order{ full_name, home_address, purchases });
	}
}
