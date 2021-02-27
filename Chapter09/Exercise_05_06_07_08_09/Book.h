// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Book
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 5 - 9
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Class Book should have members for the ISBN, title, author, and copyright date.
* Also store data on whether or not the book is checked out.
* Create functions for returning those data values.
* Create functions for checking a book in and out.
* Do simple validation of data entered into a Book; for example, accept ISBNs only of the form
* n-n-n-n-x where n is an integer and x is a digit or a letter.
* Store an ISBN as a string.
* Add operators for the Book class.
* Have the == operator check whether the ISBN numbers are the same for the two books.
* Have != also compate the ISBN numbers.
* Have a << operator print out the title, author, and ISBN on separate lines.
* Create an enumerated type for the Book class called Genre.
* Have the types be fiction, nonfiction, periodical, biography, and children.
* Give each book a Genre and make appropriate changes to the Book constructor and member functions.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H
#pragma once

#include <string>
#include <regex>
#include <iostream>
#include <ostream>

namespace Books
{
	enum class Genre { Fiction = 1, Nonfiction, Periodical, Biography, Children };

	class Book
	{
	public:
		class Invalid_Book{};

		Book();

		Book(const std::string& isbn_,
			const std::string& title_,
			const std::string& author_,
			int copyright_date_,
			Genre genre_);

		//-----------------------------------------------------
	    // Public member functions
	    //-----------------------------------------------------

		//-----------------------------------------------------
		// Nonmodifying operations
		//-----------------------------------------------------
		inline std::string get_isbn() const { return isbn; }
		inline std::string get_title() const { return title; }
		inline std::string get_author() const { return author; }
		inline int get_copyright_date() const { return copyright_date; }
		inline bool is_available() { return book_is_available; }

		//-----------------------------------------------------
		// Modifying operations
		//-----------------------------------------------------
		inline void check_out()
		{
			if (book_is_available)
			{
				book_is_available = false;
				std::cout << get_title() << " by " << get_author() << " has been checked out.\n";
				return;
			}
		}

		inline void return_book()
		{
			if (!book_is_available)
			{
				book_is_available = true;
				std::cout << get_title() << " by " << get_author() << " has been returned.\n";
				return;
			}
		}
	private:
		std::string isbn;
		std::string title;
		std::string author;
		int copyright_date{ 1800 };
		Genre genre{ Genre::Fiction };
		bool book_is_available{ true };
	};

	bool is_valid_book(const std::string& isbn,
		const std::string& title,
		const std::string& author,
		const int copyright_date,
		const Genre genre);

	std::ostream& operator << (std::ostream& os, const Book& obj);
	std::istream& operator >> (std::istream& is, Book& obj);

	bool operator == (const Book& obj1, const Book& obj2);
	bool operator != (const Book& obj1, const Book& obj2);
}

#endif // BOOK_H
