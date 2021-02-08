#pragma once
#include "Book.h"
#include "Patron.h"
#include <vector>

namespace Local_Library
{
	struct Transaction
	{
		Books::Book book;
		Patrons::Patron patron;
	};

	class Library
	{
		// static variables
	public:
		Library() = default;

		Library(const std::vector<Books::Book>& books_,
			    const std::vector<Patrons::Patron>& patrons_);

		void add_book(const Books::Book& book);
		void add_patron(const Patrons::Patron& patron);
		void check_out_book(Books::Book& book, Patrons::Patron& patron);
		void check_in_book(Books::Book& book, Patrons::Patron& patron);
		std::vector<Patrons::Patron> patrons_in_debt(const Library& library);

	private:
		std::vector<Books::Book> books;
		std::vector<Patrons::Patron> patrons;
		std::vector<Transaction> transactions;
	};
}
