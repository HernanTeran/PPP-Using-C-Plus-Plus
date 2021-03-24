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

using namespace std;

namespace Local_Library
{
	void driver(const string& inv_b, const string& inv_p, const string& inv_l)
	{
		for (;;)
		{
			try
			{
				Library library;

				Book b1, b2;
				cin >> b1 >> b2;

				library.add_book(b1);
				library.add_book(b2);

				Patron p1, p2;
				cin >> p1 >> p2;

				library.add_patron(p1);
				library.add_patron(p2);

				library.check_out_book(b1, p1);
				library.check_out_book(b2, p2);

				print_lib(library);

				library.check_in_book(b1, p1);
				library.check_in_book(b2, p2);

				print_lib(library);
				
				char a = cont_loop("Enter 'c' to continue...\n");
				if (a != 'c') { return; }
			}
			catch (Book::Invalid_Book)
			{
				cerr << inv_b << '\n';
				char a = cont_loop("Enter 'c' to continue...\n");
				if (a != 'c') { return; }
			}
			catch (Patron::Invalid_Patron)
			{
				cerr << inv_p << '\n';
				char a = cont_loop("Enter 'c' to continue...\n");
				if (a != 'c') { return; }
			}
			catch (Library::Lib_Error)
			{
				cerr << inv_l << '\n';
				char a = cont_loop("Enter 'c' to continue...\n");
				if (a != 'c') { return; }
			}
			catch (exception& e)
			{
				cerr << e.what();
				char a = cont_loop("Enter 'c' to continue...\n");
				if (a != 'c') { return; }
			}
			catch (...)
			{
				cerr << "An unexpected error occurred.\n";
				return;
			}
		}
	}

	char cont_loop(const string& prompt)
	{
		cout << prompt;
		char c{ '0' };
		cin >> c;

		if (!cin || cin.eof())
		{
			cin.clear();
			return 'q';
		}

		return c;
	}

	void print_lib(const Library& lib)
	{
		cout << lib;
		print_p_names(patrons_in_debt(lib));
	}
}
