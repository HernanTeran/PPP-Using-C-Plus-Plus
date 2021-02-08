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
		class Invalid{};

		Book() = default;

		Book(const std::string& isbn_,
			const std::string& title_,
			const std::string& author_,
			int copyright_date_,
			Genre genre_);

		// nonmodifying operations
		std::string get_isbn() const { return isbn; }
		std::string get_title() const { return title; }
		std::string get_author() const { return author; }
		int get_copyright_date() const { return copyright_date; }
		bool is_available() { return book_is_available; }
		
		// modifying operation
		void check_out()
		{
			if (book_is_available)
			{
				book_is_available = false;
				std::cout << get_title() << " by " << get_author() << " has been checked out.\n";
				return;
			}
		}

		void return_book() 
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

	// establish invariant
	// true for valid book
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
