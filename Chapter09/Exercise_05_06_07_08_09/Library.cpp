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

namespace Local_Library
{
	using namespace std;
	using Books::Book;
	using Patrons::Patron;

	//------------------------------------------------------------------------------------------------------------------------------
	// Local_Library::Library::Library(const vector<Book>& books_,
	//                                 const vector<Patron>& patrons_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* @param <books_>   valid books are added to vector
	* @param <patrons_> valid patrons are added to vector
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Local_Library::Library::Library(const vector<Book>& books_,
		const vector<Patron>& patrons_)
		:
		books{ books_ }, patrons{ patrons_ }
	{
	}

	//-----------------------------------------------------
	// Public member functions
	//-----------------------------------------------------

	//------------------------------------------------------------------------------------------------------------------------------
	// void Library::add_book(const Book& book)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Adds a valid book to the books vector unless the book is already in the vector.
	* 
	* @param <book> valid unique book
	* 
	* @note If the book is already in the vector the function returns with an error message.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Library::add_book(const Book& book)
	{
		if (books.empty())
		{
			books.push_back(book);
			cout << book.get_title() << " by " << book.get_author() << " has been added to the library.\n";
			return;
		}

		for (const auto& b : books)
		{
			if (b == book)
			{
				cerr << "This book is already in the library!\n";
				return;
			}
		}

		books.push_back(book);
		cout << book.get_title() << " by " << book.get_author() << " has been added to the library.\n";
		return;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Library::add_patron(const Patron& patron)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Adds a valid patron to the patrons vector unless the patron is already in the vector.
	*
	* @param <patron> valid unique patron
	*
	* @note If the patron is already in the vector the function returns with an error message.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Library::add_patron(const Patron& patron)
	{
		if (patrons.empty())
		{
			patrons.push_back(patron);
			cout << patron.get_full_name() << " is now in the library.\n";
			return;
		}

		for (const auto& p : patrons)
		{
			if (p == patron)
			{
				cerr << "This patron is already in the library!\n";
				return;
			}
		}

		patrons.push_back(patron);
		cout << patron.get_full_name() << " is now in the library.\n";
		return;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Library::check_out_book(Book& book, Patron& patron)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function checks out a book by validating the book, patron, and checking if the patron owes fees.
	* If everything checks out, a Transaction is created.
	*
	* @param <book>   valid unique book
	* @param <patron> valid unique patron
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Library::check_out_book(Book& book, Patron& patron)
	{
		bool book_match{ true };

		for (size_t b{ 0 }; b != books.size(); ++b)
		{
			if (books.at(b) == book)
			{
				cout << book.get_title() << " with ISBN " << book.get_isbn() << " has been found.\n";
				break;
			}

			constexpr double last_book{ 1 };

			if (b == books.size() - last_book)
			{
				cerr << "This book is not in the library!\n";
				book_match = false;
			}
		}

		bool patron_match{ true };

		for (size_t p{ 0 }; p != patrons.size(); ++p)
		{
			if (patrons.at(p) == patron)
			{
				cout << patron.get_full_name() << " with account number "
					 << patron.get_account_number() << " has been found.\n";
				break;
			}

			constexpr double last_patron{ 1 };

			if (p == patrons.size() - last_patron)
			{
				cerr << "This patron is not in the library!\n";
				patron_match = false;
			}
		}

		if (!book_match || !patron_match) { return; }

		for (const auto& t : transactions)
		{
			if (t.book == book && t.patron == patron)
			{
				cerr << "You have already checked this book out!\n";
				return;
			}
		}

		constexpr double zero_balance{ 0 };

		if (patron.get_library_fees() != zero_balance)
		{
			cerr << patron.get_full_name() << " you have an outstanding balance of $"
				 << patron.get_library_fees() << ".\nYou are not allowed to check out a book until it is paid off.\n";
			return;
		}

		if (book.is_available())
		{
			book.check_out();
			constexpr double base_fee{ 1.08 };
			patron.set_fee(base_fee);
			transactions.push_back(Transaction{ book, patron });
			patrons_in_debt.push_back(patron);
			cout << "Happy Reading " << patron.get_full_name() << "!\n";
			return;
		}
		else
		{
			cerr << book.get_title() << " by " << book.get_author() << " is currently checked out.\n";
			return;
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Library::check_in_book(Book& book, Patron& patron)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function checks in a book by checking for the correct book and patron.
	* If the patron owed any fees, the fees will be cleared.
	*
	* @param <book>   valid unique book
	* @param <patron> valid unique patron
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Library::check_in_book(Book& book, Patron& patron)
	{
		for (auto& t : transactions)
		{
			if (t.book == book && t.patron == patron)
				// return book and clear library fee
				// remove single transaction if there is only one in the vector
				// else move transaction to the back to be able to remove it by using pop_back()
			{
				book.return_book();

				constexpr double zero_balance{ 0 };
				patron.set_fee(zero_balance);

				constexpr size_t one_transaction{ 1 };

				if (transactions.size() == one_transaction)
				{
					transactions.pop_back();
					cout << "Transaction has been cleared.\n";
					return;
				}
				else
				{
					const size_t last_transaction{ transactions.size() - one_transaction };

					swap(t, transactions.at(last_transaction));
					transactions.pop_back();
					cout << "Transaction has been cleared.\n";
					return;
				}
			}
		}

		for (auto& p : patrons_in_debt)
		{
			constexpr size_t one_patron{ 1 };

			if (patrons_in_debt.size() == one_patron)
			{
				patrons_in_debt.pop_back();
				cout << p.get_full_name() << " has been cleared from in-debt list.\n";
				return;
			}
			else
			{
				const size_t last_patron{ patrons_in_debt.size() - one_patron };

				swap(p, patrons_in_debt.at(last_patron));
				patrons_in_debt.pop_back();
				cout << p.get_full_name() << " has been cleared from in-debt list.\n";
				return;
			}
		}

		// if there are no matches
		cerr << "There are no matches for that book or patron.\n";
		return;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// void Library::print_debt_list()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function prints the names of patrons that owe fees.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	void Library::print_debt_list()
	{
		if (transactions.empty())
		{
			cerr << "There are currently no transactions.\n";
			return;
		}

		cout << "\n*PATRONS IN-DEBT*\n"
			<< "------------------\n";
		for (const auto& p : patrons_in_debt) { cout << p.get_full_name() << '\n'; }
		cout << '\n';

		return;
	}
}
