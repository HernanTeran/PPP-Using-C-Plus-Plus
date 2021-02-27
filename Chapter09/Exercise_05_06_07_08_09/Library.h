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
#ifndef LIBRARY_H
#define LIBRARY_H
#pragma once

#include "Book.h"
#include "Patron.h"

#include <vector>

namespace Local_Library
{
	//-----------------------------------------------------
	// struct Transaction
	//-----------------------------------------------------
	/*
	* takes valid books and patrons
	*/
	//-----------------------------------------------------
	struct Transaction
	{
		Books::Book book;
		Patrons::Patron patron;
	};

	class Library
	{
	public:
		Library() = default;

		Library(const std::vector<Books::Book>& books_,
			const std::vector<Patrons::Patron>& patrons_);

		void add_book(const Books::Book& book);
		void add_patron(const Patrons::Patron& patron);
		void check_out_book(Books::Book& book, Patrons::Patron& patron);
		void check_in_book(Books::Book& book, Patrons::Patron& patron);
		void print_debt_list();

	private:
		std::vector<Books::Book> books;
		std::vector<Patrons::Patron> patrons;
		std::vector<Transaction> transactions;
		std::vector<Patrons::Patron> patrons_in_debt;
	};
}

#endif // LIBRARY_H
