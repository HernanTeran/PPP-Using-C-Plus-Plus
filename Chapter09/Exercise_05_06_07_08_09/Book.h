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

#include <iostream>
#include <string>
#include <regex>

namespace Local_Library
{
	// symbolic constants
	enum class Genre { Fiction = 1, Nonfiction, Periodical, Biography, Children };

	class Book
	{
	public:
		// constants
		static constexpr std::size_t MIN_WORD_LEN{ 2 };
		static constexpr int MIN_YEAR{ 1800 }, MAX_YEAR{ 2021 };

	public:
		// exception class
		class Invalid_Book {};

		// constructors
		Book();
		Book(const std::string& ISBN_,
			const std::string& title_,
			const std::string& author_,
			int copyright_date_,
			Genre genre_);

	public:
		// public member functions

		// nonmodifying operations
		std::string get_ISBN() const { return ISBN; }
		std::string get_title() const { return title; }
		std::string get_author() const { return author; }
		std::string get_avail_status() const { return status; }
		std::string get_str_genre() const;
		int get_copyright_date() const { return copyright_date; }
		Genre get_genre() const { return genre; }
		bool is_available() const { return available; }

		// modifying operation
		void set_availability(bool avai) { available = avai; }
		void set_status(const std::string& s) { status = s; }

	private:
		std::string ISBN, title, author, status;
		int copyright_date;
		Genre genre;
		bool available{ true };
	};

	// helper functions
	const Book& default_book();
	bool is_valid_book(const std::string& ISBN, const std::string& title, const std::string& author,
		int copyright_date, Genre genre);

	std::ostream& operator<<(std::ostream& os, const Book& book);
	std::istream& operator>>(std::istream& is, Book& book);

	bool operator==(const Book& b1, const Book& b2);
	bool operator!=(const Book& b1, const Book& b2);

	std::string ISBN_input(std::istream& is);
	std::string title_input(std::istream& is);
	std::string author_input(std::istream& is);
	int cpyd_input(std::istream& is);
	int genre_int(std::istream& is);
	Genre genre_input(std::istream& is);
}

#endif // BOOK_H
