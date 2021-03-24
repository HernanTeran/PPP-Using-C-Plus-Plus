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
#include "Book.h"

using namespace std;

namespace Local_Library
{
	Book::Book()
		:
		ISBN{ default_book().get_ISBN() },
		title{ default_book().get_title() },
		author{ default_book().get_author() },
		copyright_date{ default_book().get_copyright_date() },
		genre{ default_book().get_genre() }
	{
		available = true;
		if (available)
			status = "Available";
		else
			status = "Unavailable";
	}

	Book::Book(const string& ISBN_,
		const string& title_,
		const string& author_,
		int copyright_date_,
		Genre genre_)
		:
		ISBN{ ISBN_ },
		title{ title_ },
		author{ author_ },
		copyright_date{ copyright_date_ },
		genre{ genre_ }
	{
		if (!is_valid_book(ISBN_, title_, author_, copyright_date_, genre_)) { throw Invalid_Book{}; }
		available = true;
		if (available)
			status = "Available";
		else
			status = "Unavailable";
	}

	const Book& default_book()
	{
		static Book book{ "0-0-0-x", "Unknown title", "Unknown author", 1800, Genre::Fiction };
		return book;
	}

	bool is_valid_book(const string& ISBN,
		const string& title,
		const string& author,
		int copyright_date,
		Genre genre)
	{
		regex pat{ R"(([0-9])\-([0-9])\-([0-9])\-([A-za-z]))" };
		if (!regex_match(ISBN, pat)) { return false; }
		if (title.length() < Book::MIN_WORD_LEN) { return false; }
		if (author.length() < Book::MIN_WORD_LEN) { return false; }
		if (copyright_date < Book::MIN_YEAR || copyright_date > Book::MAX_YEAR) { return false; }
		if (genre < Genre::Fiction || genre > Genre::Children) { return false; }
		return true;
	}

	string Book::get_str_genre() const
	{
		string str_genre;

		switch (genre)
		{
		case Genre::Fiction:
			str_genre = "Fiction";
			break;
		case Genre::Nonfiction:
			str_genre = "Nonfiction";
			break;
		case Genre::Periodical:
			str_genre = "Periodical";
			break;
		case Genre::Biography:
			str_genre = "Biography";
			break;
		case Genre::Children:
			str_genre = "Children";
			break;
		default:
			throw Invalid_Book{};
		}

		return str_genre;
	}

	ostream& operator<<(ostream& os, const Book& book)
	{
		return os << "\n[Book]\n"
			<< "[Title: " << book.get_title() << "]\n"
			<< "[Author: " << book.get_author() << "]\n"
			<< "[ISBN: " << book.get_ISBN() << "]\n"
			<< "[Genre: " << book.get_str_genre() << "]\n"
			<< "[Status: " << book.get_avail_status() << "]\n";
	}

	istream& operator>>(istream& is, Book& book)
	{
		string ISBN = ISBN_input(is);
		string title = title_input(is);
		string author = author_input(is);
		int copyright_date = cpyd_input(is);
		Genre genre = genre_input(is);

		book = Book{ ISBN, title, author, copyright_date, genre };

		return is;
	}

	bool operator==(const Book& b1, const Book& b2)
	{
		return b1.get_ISBN() == b2.get_ISBN();
	}

	bool operator!=(const Book& b1, const Book& b2)
	{
		return b1.get_ISBN() != b2.get_ISBN();
	}

	string ISBN_input(istream& is)
	{
		string ISBN;
		cout << "[Input ISBN n-n-n-x]: ";
		is >> ISBN;
		if (is.eof())
		{
			is.clear();
			throw Book::Invalid_Book{};
		}
		return ISBN;
	}

	string title_input(istream& is)
	{
		string title;
		cout << "[Input title]: ";
		is.ignore(10000, '\n');
		getline(is, title, '\n');
		return title;
	}

	string author_input(istream& is)
	{
		string fname, lname;
		cout << "[Input author]: ";
		is >> fname >> lname;

		if (is.eof())
		{
			is.clear();
			throw Book::Invalid_Book{};
		}

		if (!is)
		{
			is.clear();
			is.ignore();
			throw Book::Invalid_Book{};
		}

		return fname + ' ' + lname;
	}

	int cpyd_input(istream& is)
	{
		int copyright_date{ 0 };
		cout << "[Input copyright date]: ";
		is >> copyright_date;

		if (is.eof())
		{
			is.clear();
			throw Book::Invalid_Book{};
		}

		if (!is)
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			throw Book::Invalid_Book{};
		}

		return copyright_date;
	}

	int genre_int(istream& is)
	{
		cout << "\n[Genres]\n"
			<< "(1) Fiction\n"
			<< "(2) Nonfiction\n"
			<< "(3) Periodical\n"
			<< "(4) Biography\n"
			<< "(5) Children\n"
			<< "\n[Input genre]: ";

		int genre{ 0 };
		is >> genre;

		if (is.eof())
		{
			is.clear();
			throw Book::Invalid_Book{};
		}

		if (!is)
		{
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			throw Book::Invalid_Book{};
		}

		return genre;
	}

	Genre genre_input(istream& is)
	{
		int i_genre = genre_int(is);
		Genre genre;

		switch (i_genre)
		{
		case 1:
			genre = Genre::Fiction;
			break;
		case 2:
			genre = Genre::Nonfiction;
			break;
		case 3:
			genre = Genre::Periodical;
			break;
		case 4:
			genre = Genre::Biography;
			break;
		case 5:
			genre = Genre::Children;
			break;
		default:
			throw Book::Invalid_Book{};
		}

		return genre;
	}
}
