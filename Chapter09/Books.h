#pragma once

#include <string>
#include <regex>
#include <iostream>
#include <ostream>
#include <istream>
#include <vector>

namespace Books
{
	enum class Genre { Fiction = 1, Nonfiction, Periodical, Biography, Children };

	class Book
	{
	private:
		std::string isbn;
		std::string title;
		std::string author;
		int copyright_date{ 0 };
		Genre genre{};
	public:
		class Invalid{};

		Book() = default;

		Book(const std::string& isbn_,
			const std::string& title_,
			const std::string& author_,
			const int copyright_date_,
			const Genre genre_);

		// nonmodifying operations
		std::string get_ISBN() const { return isbn; }
		std::string get_title() const { return title; }
		std::string get_author() const { return author; }
		int get_copyright_date() const { return copyright_date; }
		std::string get_genre() const;
	};

	// establish invariant
	// true for valid book
	bool is_valid_book(const std::string& isbn,
		const std::string& title,
		const std::string& author,
		const int copyright_date,
		const Genre genre);

	struct Book_Collection
	{
		std::vector<Book> book_collection;
	};

	void check_out(const Book& book, Book_Collection& my_books);
	void return_book(const Book& book, Book_Collection& my_books);

	std::ostream& operator << (std::ostream& os, const Book& obj);
	std::istream& operator >> (std::istream& is, Book& obj);

	bool operator == (const Book& obj1, const Book& obj2);
	bool operator != (const Book& obj1, const Book& obj2);
};
