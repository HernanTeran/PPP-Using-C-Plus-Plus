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

#include <iostream>
#include <string>
#include <vector>

namespace Local_Library
{
	struct Transaction
	{
		Book book;
		Patron patron;
	};

	class Library
	{
	public:
		// constant
		static constexpr double BASE_FEE{ 10.99 };

		// exception class
		class Lib_Error {};

		// no need for constructors
	public:
		// public member functions

		// nonmodifying operations
		std::vector<Book> get_books() const { return books; }
		std::vector<Patron> get_patrons() const { return patrons; }
		std::vector<Transaction> get_transactions() const { return transactions; }

		// modifying operations
		void add_book(const Book& book);
		void add_patron(const Patron& patron);
		void check_out_book(Book& book, Patron& patron);
		void check_in_book(Book& book, Patron& patron);

	protected:
		void remove_patron(Patron& patron);

	private:
		std::vector<Book> books;
		std::vector<Patron> patrons;
		std::vector<Transaction> transactions;
	};

	// helper functions
	std::ostream& operator<<(std::ostream& os, const Library& library);

	std::vector<std::string> patrons_in_debt(const Library& library);
	void print_p_names(const std::vector<std::string>& pnames);
}

#endif // LIBRARY_H
