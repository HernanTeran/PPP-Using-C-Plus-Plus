// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Library_Impl
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 5 - 9
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Driver that runs the program.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Library_Impl.h"

namespace Driver
{
	using namespace Books;
	using namespace Patrons;
	using namespace Local_Library;

	using std::cin;
	using std::cout;
	using std::cerr;

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
			//----------------------------------------------------------------------------------------------------------------------
			// Test cases
			//----------------------------------------------------------------------------------------------------------------------
			/*
			* @note rand_book and rand_patron are suppose to provide invalid input for testing purposes.
			*/
			//----------------------------------------------------------------------------------------------------------------------
			Book rand_book{ "1-2-2-2-F", "The Shining", "Stephen King", 1805, Books::Genre::Biography };
			Patron rand_patron{ "Gene Belcher", 123456 };

			Book book1;
			cin >> book1;
			cout << book1;

			Patron patron1{ "Bob Belcher", 434323 };

			Library library;
			library.add_book(book1);
			library.add_patron(patron1);
			library.check_out_book(book1, patron1);

			// test case ------------------------------------------------------------------
			library.check_out_book(rand_book, rand_patron);
			// ----------------------------------------------------------------------------

			Book book2;
			cin >> book2;
			cout << book2;

			Patron patron2{ "Linda Belcher", 785342 };
			library.add_book(book2);
			library.add_patron(patron2);
			library.check_out_book(book2, patron2);

			library.print_debt_list();

			library.check_in_book(book1, patron1);
			library.check_in_book(book2, patron2);

		}
		catch (Book::Invalid_Book)
		{
			cerr << "Invalid book.\n";
		}
		catch (Patron::Invalid_Patron)
		{
			cerr << "Invalid patron.\n";
		}
	}
}