// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Purchase
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Purchase is a class with a (product) name, unit_price, and count members.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Purchase.h"

namespace Purchases
{
	using namespace std;

	//-----------------------------------------------------------------------------------------------------------------------------
	// Purchase::Purchase()
	//-----------------------------------------------------------------------------------------------------------------------------
	/*
	* Default constructor
	*/
	//-----------------------------------------------------------------------------------------------------------------------------
	Purchase::Purchase() : unit_price{ 0 }, count{ 0 }
	{
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	// Purchase::Purchase()
	//-----------------------------------------------------------------------------------------------------------------------------
	/*
	* Constructor that establishes invariant from a valid product name, unit price, and count.
	* 
	* @param <product_name_> input one or two word product name
	* @param <unit_price_>   input positive unit price
	* @param <count_>        input positive count
	* 
	* @exception Invalid_purchase is thrown if one of the members has invalid input.
	*/
	//-----------------------------------------------------------------------------------------------------------------------------
	Purchase::Purchase(const string& product_name_, double unit_price_, int count_)
		: product_name{ product_name_ }, unit_price{ unit_price_ }, count{ count_ }
	{
		if (!is_valid_purchase(product_name_, unit_price_, count_)) { throw Invalid_purchase{}; }
	}

	//--------------------------------------------------------
	// Helper functions
	//--------------------------------------------------------

	//-----------------------------------------------------------------------------------------------------------------------------
	// bool is_valid_purchase(const string& product_name_, double unit_price_, int count_)
	//-----------------------------------------------------------------------------------------------------------------------------
	/*
	* This functions validates user input and is called by the constructor to establish invariant.
	*
	* @param <product_name_> input one or two word product name
	* @param <unit_price_>   input positive unit price
	* @param <count_>        input positive count
	* 
	* @return                true if valid
	*/
	//-----------------------------------------------------------------------------------------------------------------------------
	bool is_valid_purchase(const string& product_name_, double unit_price_, int count_)
	{
		regex pat{ R"(\w+ ?\w*)" };
		if (!regex_match(product_name_, pat)) { return false; }
		if (unit_price_ <= 0) { return false; }
		if (count_ <= 0) { return false; }

		return true;
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	// ostream& operator<<(ostream& os, const Purchase& purchase)
	//-----------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the << (extraction) operator to print a Purchase.
	*/
	//-----------------------------------------------------------------------------------------------------------------------------
	ostream& operator<<(ostream& os, const Purchase& purchase)
	{
		return os << "{Product name: " << purchase.get_product_name() << "}\n"
			<< "{Unit price: $" << purchase.get_unit_price() << "}\n"
			<< "{Total ordered: " << purchase.get_count() << "}\n\n";
	}

	//-----------------------------------------------------------------------------------------------------------------------------
	// istream& operator>>(istream& is, Purchase& purchase)
	//-----------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the >> (insertion) operator to get user input and construct a Purchase.
	*/
	//-----------------------------------------------------------------------------------------------------------------------------
	istream& operator>>(istream& is, Purchase& purchase)
	{
		cout << "Enter product name: ";
		string product_name;
		is >> product_name;

		cout << "Enter unit price: $";
		double unit_price{ 0 };
		is >> unit_price;

		cout << "Enter total bought: ";
		int count{ 0 };
		is >> count;

		if (!is)
		{
			is.clear(ios_base::failbit);
			return is;
		}

		purchase = Purchase{ product_name, unit_price, count };

		return is;
	}
}
