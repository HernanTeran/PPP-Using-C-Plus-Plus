// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Library
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 5 - 9
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Create a Library class.
* Include vectors of Books and Patrons.
* Include a struct called Transaction.
* Have it include a Book, a Patron, and a Date from the chapter.
* Make a vector of Transactions.
* Create functions to add books to the library, add patrons to the library, and check out books.
* Whenever a user checks out a book, have the library make sure that both the user
* and the book are in the library.
* If they aren't, report an error. Then check to make sure that the user owes no fees.
* If the user does, report an error.
* If not, create a Transaction, and place it the vector of Transactions.
* Also write a function that will return a vector that contains the names of all Patrons who owe fees.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Library.h"

using namespace std;

namespace Local_Library
{
	ostream& operator<<(ostream& os, const Library& library)
	{
		os << "================================\n"
			<< "*Patrons in Library*\n"
			<< "================================\n";
		for (const Patron& p : library.get_patrons())
			os << p;

		os << "\n================================\n"
			<< "*Books in Library*\n"
			<< "================================\n";
		for (const Book& b : library.get_books())
			os << b;

		os << "\n================================\n"
			<< "*Transactions*\n" 
			<<"================================\n";
		for (const Transaction& t : library.get_transactions())
			os << t.patron << t.book << '\n';

		os << "================================\n\n";

		return os;
	}

	void Library::add_book(const Book& book)
	{
		auto it = find(books.cbegin(), books.cend(), book);
		if (it == books.cend())
		{ 
			books.push_back(book);
			cout << "\n[" + book.get_title() + " by " + book.get_author() + " has been added to the Library.]\n\n";
			return;
		}
		cerr << "\n[This Book is already in the Library!]\n";
		return;
	}

	void Library::add_patron(const Patron& patron)
	{
		auto it = find(patrons.cbegin(), patrons.cend(), patron);
		if (it == patrons.cend())
		{
			patrons.push_back(patron);
			cout << "\n[" + patron.get_full_name() + " is in the Library.]\n\n";
			return;
		}
		cerr << "\n[This Patron is already in the Library]!\n";
		return;
	}

	void Library::check_out_book(Book& book, Patron& patron)
	{
		auto it_book = find(books.cbegin(), books.cend(), book);
		auto it_patron = find(patrons.cbegin(), patrons.cend(), patron);

		if (it_book != books.cend() && it_patron != patrons.cend())
		{
			if (!book.is_available())
			{
				cerr << "\n[" + book.get_title() + " by " + book.get_author() + " is currently unavailable.]\n\n";
				return;
			}

			if (owes_fees(patron))
			{
				cerr << "\n[Unable to checkout book because " + patron.get_full_name() + 
					" owes $" << patron.get_lib_fees() << ".]\n\n";
				return;
			}

			book.set_availability(false);
			patron.set_lib_fee(BASE_FEE);
			book.set_status("Unavailable");

			for (auto& b : books)
				if (b == book)
					b.set_status("Unavailable");
			
			for (auto& p : patrons)
				if (p == patron)
					p.set_lib_fee(BASE_FEE);

			transactions.push_back(Transaction{ book, patron });
			cout << "\n[" + patron.get_full_name() + " has checked out " + book.get_title() + " by " +
				book.get_author() + ".]\n\n";
			return;
		}
		else { throw Lib_Error{}; }
	}

	void Library::check_in_book(Book& book, Patron& patron)
	{
		auto it_bl = find(books.cbegin(), books.cend(), book);
		auto it_pl = find(patrons.cbegin(), patrons.cend(), patron);

		if (it_bl == books.cend() || it_pl == patrons.cend())
			throw Lib_Error{};

		for (size_t i{ 0 }; i != transactions.size(); ++i)
		{
			if (book == transactions.at(i).book && patron == transactions.at(i).patron)
			{
				book.set_availability(true);
				patron.set_lib_fee(patron.ZERO_BAL);
				book.set_status("Available");
				break;
			}
		}

		for (auto& b : books)
			if (b == book)
				b.set_status("Available");

		for (size_t i{ 0 }; i != patrons.size(); ++i)
		{
			if (patron == patrons.at(i))
			{
				patrons.at(i).set_lib_fee(patron.ZERO_BAL);
				break;
			}
		}

		if (transactions.size() == 1)
		{
			transactions.pop_back();
			cout << "[" + patron.get_full_name() + " has returned " + book.get_title() + "]\n";
			remove_patron(patron);
			return;
		}

		if (transactions.size() > 1)
		{
			for (size_t i{ 0 }; i != transactions.size(); ++i)
			{
				if (patron == transactions.at(i).patron)
				{
					swap(transactions.at(i), transactions.at(transactions.size() - 1));
					transactions.pop_back();
					cout << "[" + patron.get_full_name() + " has returned " + book.get_title() + "]\n";
					remove_patron(patron);
					return;
				}
			}
		}
		else { throw Lib_Error{}; }
	}

	void Library::remove_patron(Patron& patron)
	{
		if (owes_fees(patron))
			throw Lib_Error{};

		for (size_t i{ 0 }; i != patrons.size(); ++i)
		{
			if (patron == patrons.at(i))
			{
				if (patrons.size() == 1)
				{
					patrons.pop_back();
					break;
				}
				else
				{
					swap(patron, patrons.at(patrons.size() - 1));
					patrons.pop_back();
					break;
				}
			}
		}

		cout << "\n[" + patron.get_full_name() + " has left the Library.]\n";
		return;
	}

	vector<string> patrons_in_debt(const Library& library)
	{
		vector<string> names;

		for (const auto& p : library.get_patrons())
			if (owes_fees(p))
				names.push_back(p.get_full_name());
			else
				throw Library::Lib_Error{};

		return names;
	}

	void print_p_names(const vector<string>& pnames)
	{
		cout << "[Patrons in debt]:\n";
		for (const auto& n : pnames)
			cout << n << '\n';
		cout << endl;
	}
}
