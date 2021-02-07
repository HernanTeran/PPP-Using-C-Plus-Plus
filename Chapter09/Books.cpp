#include "Book.h"

namespace Books
{
	Books::Book::Book(const std::string& isbn_,
		const std::string& title_,
		const std::string& author_,
		int copyright_date_,
		Genre genre_)
		:
		isbn{ isbn_ },
		title{ title_ },
		author{ author_ },
		copyright_date{ copyright_date_ },
		genre{ genre_ }
	{
		if (!is_valid_book(isbn_, title_, author_, copyright_date_, genre_)) { throw Invalid{}; }
	}


	bool is_valid_book(const std::string& isbn, 
					   const std::string& title, 
					   const std::string& author, 
					   const int copyright_date, 
					   const Genre genre)
	{
		// test ISBN ----------------------------------------------

		std::regex pat{ R"(([0-9])\-([0-9])\-([0-9])\-([0-9])\-([a-zA-z]))" };

		if (!regex_match(isbn, pat)) { return false; } // must match d-d-d-d-l

		// test title/author ---------------------------------------
		constexpr int min_str_len{ 3 };

		if (title.length() < min_str_len) { return false; }
		if (author.length() < min_str_len) { return false; }

		// test copyright date -------------------------------------
		constexpr int min_date{ 1800 };
		constexpr int max_date{ 2021 };

		if (copyright_date < min_date || copyright_date > max_date) { return false; }

		// test genre ----------------------------------------------
		constexpr Genre min_genre{ Genre::Fiction };
		constexpr Genre max_genre{ Genre::Children };

		if (genre < min_genre || genre > max_genre) { return false; }

		return true;
	}

	std::ostream& operator << (std::ostream& os, const Book& obj)
	{
		return os << "[Book Info]\n"
			<< "-----------\n"
			<< "[Title]: " << obj.get_title() << '\n'
			<< "[Author]: " << obj.get_author() << '\n'
			<< "[ISBN]: " << obj.get_isbn() << '\n'
			<< "[Copyright Date]: " << obj.get_copyright_date() << "\n\n";
	}

	std::istream& operator >> (std::istream& is, Book& obj)
	{
		using std::cout;

		cout << "Enter ISBN (d-d-d-l):\n";
		std::string ISBN;
		getline(is, ISBN);
		if (!is) { return is; }
		
		cout << "Enter book title:\n";
		std::string title;
		getline(is, title);
		if (!is) { return is; }

		cout << "Enter book author:\n";
		std::string author;
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
		Books::Genre genre{ Genre::Fiction };

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
			std::cerr << "[Error]: invalid input\n";
			break;
		}

		std::cin.ignore();

		obj = Book{ ISBN, title, author, copyright, genre };

		return is;
	}

	bool operator == (const Book& obj1, const Book& obj2)
	{
		return obj1.get_isbn() == obj2.get_isbn()
			&& obj1.get_author() == obj2.get_author()
			&& obj1.get_title() == obj2.get_title()
			&& obj1.get_copyright_date() == obj2.get_copyright_date();
	}

	bool operator != (const Book& obj1, const Book& obj2) { return !(obj1 == obj2); }
}
