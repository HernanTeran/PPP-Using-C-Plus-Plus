// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Order
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Define an Order class with (customer) name, address, data, and vector<Purchase> members.
* Purchase is a class with a (product) name, unit_price, and count members.
* Define a mechanism for reading and writing Orders to and from a file.
* Define a mechanism for printing Orders.
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
* Merge the two files into a third using std::merge().
* Compute the total value of the orders in the two files.
* The value of an individual Purchase is its unit_price * count.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Order.h"

namespace Orders
{
	using namespace std;

	using Purchases::Purchase;

	//------------------------------------------------------------------------------------------------------------------------------
	// Order::Order()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Default constructor
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Order::Order() : order_shipped{ false }
	{
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// Order::Order(const string& customer_name_,
	//              const string& home_address_,
	//	            const vector<Purchase>& purchases_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Constructor that establishes invariant of valid data members.
	* 
	* @param <customer_name_> input customer full name
	* @param <home_address_>  input address of street number street name suffix
	* @param <purchases_>     input valid Purchases
	* 
	* @exception Invalid_order is thrown if one of the members are invalid
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Order::Order(const string& customer_name_,
		const string& home_address_,
		const vector<Purchase>& purchases_)
		:
		customer_name{ customer_name_ }, home_address{ home_address_ }, purchases{ purchases_ }
	{
		if (!is_valid_order(customer_name_, home_address_)) { throw Invalid_order{}; }
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// bool is_valid_order(const string& customer_name_, const string& home_address_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function validates user input used in the constructor using regular expressions.
	*
	* @param <customer_name_> input customer full name
	* @param <home_address_>  input address of street number street name suffix
	* 
	* @note Purchases are validated in their own class.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool is_valid_order(const string& customer_name_, const string& home_address_)
	{
		regex customer_pat{ R"([A-Za-z]+ [A-Za-z]+)" };
		if (!regex_match(customer_name_, customer_pat)) { return false; }

		regex address_pat{ R"([0-9]+ \w+ (St|Rd|Pl|Ln|Rd|Ct|Ave).)" };
		if (!regex_match(home_address_, address_pat)) { return false; }

		return true;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// ostream& operator<<(ostream& os, const Order& order)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the << (extraction) operator to print a customer Order.
	*
	* @note Purchases are printed using their overloaded << operator.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	ostream& operator<<(ostream& os, const Order& order)
	{
		os << "\t {ORDER}\n"
			<< "{Customer name: " << order.get_customer_name() << "}\n"
			<< "{Home address: " << order.get_home_address() << "}\n\n";

		for (const auto& purchase : order.get_purchases())
		{
			os << purchase;
		}

		return os;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// istream& operator>>(istream& is, Order& order)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the >> (insertion) operator to get user input and construct an Order object.
	*
	* @note Purchases use their own >> operator.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	istream& operator>>(istream& is, Order& order)
	{
		cout << "Enter customer name: ";
		string first_name, last_name, full_name;
		is >> first_name >> last_name;
		full_name = first_name + ' ' + last_name;

		cout << "Enter home address: ";
		string street_number, street_name, street_suffix, home_address;
		is >> street_number >> street_name >> street_suffix;
		home_address = street_number + ' ' + street_name + ' ' + street_suffix;

		if (!is)
		{
			is.clear(ios_base::failbit);
			return is;
		}

		vector<Purchase> purchases;
		Purchase purchase;
		is >> purchase;
		purchases.push_back(purchase);

		char add_order{ '0' };

		while (add_order != 'n')
		{
			cout << "Would you like to add another purchase (y/n): ";
			is.ignore();
			is.get(add_order);

			switch (add_order)
			{
			case 'y':
				is >> purchase;
				purchases.push_back(purchase);
				break;
			case 'n':
				cout << "Completing order...\n\n";
				break;
			default:
				cerr << "Unknown input. Try again.\n";
				break;
			}
		}

		order = Order{ full_name, home_address, purchases };

		return is;
	}
}
