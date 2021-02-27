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

namespace Books
{
	using namespace std;

	//-----------------------------------------------------
	// Constructors
	//-----------------------------------------------------

	//------------------------------------------------------------------------------------------------------------------------------
	// Book::Book()
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* @note default constructor
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Book::Book() : copyright_date{0}, genre{}
	{
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// Book::Book(const string& isbn_,
	//            const string& title_,
	//            const string& author_,
	//            int copyright_date_,
	//            Genre genre_)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Constructor invariant consists of these members having valid input.
	* 
	* @param <isbn_>           input ISBN in n-n-n-n-x
	* @param <title_>          input book title with length >= 3
	* @param <author_>         input author full name
	* @param <copyright_date_> input a date in YYYY in the range of [1800:2021]
	* @param <genre_>          input 1 of the 5 genre options
	* 
	* @exception Invalid_Book exception is thrown if any of the members are invalid.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	Book::Book(const string& isbn_,
		const string& title_,
		const string& author_,
		int copyright_date_,
		Genre genre_)
		:
		isbn{ isbn_ },
		title{ title_ },
		author{ author_ },
		copyright_date{ copyright_date_ },
		genre{ genre_ }
	{
		if (!is_valid_book(isbn_, title_, author_, copyright_date_, genre_)) { throw Invalid_Book{}; }
	}

	//-----------------------------------------------------
	// Helper functions
	//-----------------------------------------------------

	//------------------------------------------------------------------------------------------------------------------------------
	// bool is_valid_book(const string& isbn,
	//                    const string& title,
	//                    const string& author,
	//                    const int copyright_date,
	//                    const Genre genre)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* This function validates all user input and is called in the constructor which is able to trigger an exception.
	* 
	* @param <isbn>           input ISBN in n-n-n-n-x
	* @param <title>          input book title with length >= 3
	* @param <author>         input author full name
	* @param <copyright_date> input a date in YYYY in the range of [1800:2021]
	* @param <genre>          input 1 of the 5 genre options
	* 
	* @note test: 1) ISBN 2) title 3) author 4) copyright date 5) genre
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool is_valid_book(const string& isbn,
		const string& title,
		const string& author,
		const int copyright_date,
		const Genre genre)
	{
		regex pat{ R"(([0-9])\-([0-9])\-([0-9])\-([0-9])\-([a-zA-z]))" };

		if (!regex_match(isbn, pat)) { return false; }

		constexpr int min_str_len{ 3 };

		if (title.length() < min_str_len) { return false; }
		if (author.length() < min_str_len) { return false; }

		constexpr int min_date{ 1800 };
		constexpr int max_date{ 2021 };

		if (copyright_date < min_date || copyright_date > max_date) { return false; }

		constexpr Genre min_genre{ Genre::Fiction };
		constexpr Genre max_genre{ Genre::Children };

		if (genre < min_genre || genre > max_genre) { return false; }

		return true;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// ostream& operator << (ostream& os, const Book& obj)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the << (extraction) operator to print the title, author, ISBN, and copyright date.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	ostream& operator << (ostream& os, const Book& obj)
	{
		return os << "[Book Info]\n"
			<< "-----------\n"
			<< "[Title]: " << obj.get_title() << '\n'
			<< "[Author]: " << obj.get_author() << '\n'
			<< "[ISBN]: " << obj.get_isbn() << '\n'
			<< "[Copyright Date]: " << obj.get_copyright_date() << "\n\n";
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// istream& operator >> (istream& is, const Book& obj)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the >> (insertion) operator to get user input for the title, author, ISBN, and copyright date.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	istream& operator >> (istream& is, Book& obj)
	{
		cout << "Enter ISBN (d-d-d-d-l):\n";
		string ISBN;
		getline(is, ISBN);
		if (!is) { return is; }

		cout << "Enter book title:\n";
		string title;
		getline(is, title);
		if (!is) { return is; }

		cout << "Enter book author:\n";
		string author;
		getline(is, author);
		if (!is) { return is; }

		cout << "Enter copyright date (yyyy):\n";
		int copyright{ 1800 };
		is >> copyright;
		if (!is) { return is; }

		cout
			<< "Enter genre (1-5):\n"
			<< "Fiction\n"
			<< "Nonfiction\n"
			<< "Periodical\n"
			<< "Biography\n"
			<< "Children\n\n";

		int i_genre{ 0 };
		is >> i_genre;
		if (!is) { return is; }
		Books::Genre genre{};

		switch (i_genre)
		{
		case 1:
			genre = Books::Genre::Fiction;
			break;
		case 2:
			genre = Books::Genre::Nonfiction;
			break;
		case 3:
			genre = Books::Genre::Periodical;
			break;
		case 4:
			genre = Books::Genre::Biography;
			break;
		case 5:
			genre = Books::Genre::Children;
			break;
		default:
			cerr << "[Error]: invalid input\n";
			break;
		}

		cin.ignore();

		obj = Book{ ISBN, title, author, copyright, genre };

		return is;
	}

	//------------------------------------------------------------------------------------------------------------------------------
	// bool operator==(const Book& obj1, const Book& obj2)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the == (equality) operator to compare valid books.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool operator==(const Book& obj1, const Book& obj2) { return obj1.get_isbn() == obj2.get_isbn(); }

	//------------------------------------------------------------------------------------------------------------------------------
	// bool operator!=(const Book& obj1, const Book& obj2)
	//------------------------------------------------------------------------------------------------------------------------------
	/*
	* Overloading the != (inequality) operator to compare valid books.
	*/
	//------------------------------------------------------------------------------------------------------------------------------
	bool operator!=(const Book& obj1, const Book& obj2) { return !(obj1.get_isbn() == obj2.get_isbn()); }
}
