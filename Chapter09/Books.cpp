#include "Book.h"

namespace Books
{
	using std::string;
	using std::cout;
	using std::cin;
	using std::cerr;
	using std::regex;
	using std::smatch;
	using std::vector;
	using std::ostream;
	using std::istream;

	// values used to establish invariant
	static constexpr int min_year{ 1800 };
	static constexpr int max_year{ 2021 };
	static constexpr int min_str_len{ 4 };
	static constexpr int max_str_len{ 40 };
	static constexpr Genre min_genre{ Genre::Fiction };
	static constexpr Genre max_genre{ Genre::Children };

	Books::Book::Book() : ISBN("n-n-n-x"), title("title"), author("author"), copyright_date(min_year)
	{
	}

	Books::Book::Book(const string& isbn, const string& title_, const string& author_, int copyright_date_, Genre genre_)
		:
		ISBN(isbn), title(title_), author(author_), copyright_date(copyright_date_), genre(genre_)
	{
		if (!is_valid_book(isbn, title_, author_, copyright_date_, genre_)) { throw Invalid{}; };
	}

	string Books::Book::get_genre() const
	{
		string selection;

		switch (genre)
		{
		case Genre::Fiction:
			selection = "Fiction";
			break;
		case Genre::Nonfiction:
			selection = "Nonfiction";
			break;
		case Genre::Periodical:
			selection = "Periodical";
			break;
		case Genre::Biography:
			selection = "Biography";
			break;
		case Genre::Children:
			selection = "Children";
			break;
		default:
			selection = "None";
			break;
		}
		return selection;
	}

	bool Books::is_valid_book(const std::string& isbn, 
		                      const std::string& title, 
		                      const std::string& author, 
		                      const int copyright_date, 
		                      const Genre genre)
	{
		if (copyright_date < min_year || copyright_date > max_year) { return false; } // copyright must be positive
		if (genre < min_genre || max_genre < genre) { return false; }
		if (title.length() < min_str_len) { return false; }
		if (author.length() < min_str_len) { return false; }

		regex pat{ R"(([0-9])\-([0-9])\-([0-9])\-([0-9])\-([a-zA-z]))" };
		smatch matches;

		if (!regex_match(isbn, matches, pat)) { return false; } // must match d-d-d-d-l

		return true;
	}

	void check_out(const Book& book, Book_Collection& my_books)
	{
		if (my_books.book_collection.empty())
		{
			my_books.book_collection.push_back(book);
			cout << book.get_title() << " by " << book.get_author() << " has been added to your collection.\n";
			return;
		}

		for (const auto& b : my_books.book_collection)
		// search for duplicate
		{
			if (book == b)
			{
				cerr << "[Error]: you already have this book in your collection!\n";
				return;
			}
			else
			{
				my_books.book_collection.push_back(book);
				cout << book.get_title() << " by " << book.get_author() << " has been added to your collection.\n";
				return;
			}
		}
	}

	void return_book(const Book& book, Book_Collection& my_books)
	{
		if (my_books.book_collection.empty())
		{
			cerr << "There are currently no books in my collection.\n";
			return;
		}

		for (size_t index{ 0 }; index < my_books.book_collection.size(); ++index)
		{
			if (my_books.book_collection.at(index).get_ISBN() == book.get_ISBN())
			// search for a match
			{
				constexpr int one_book{ 1 }; // avoiding magic constants
				const size_t end_index{ my_books.book_collection.size() - one_book };

				if (index != my_books.book_collection.size() - end_index)
				// this if-statement swaps the last element with the current one
				// to be able to use pop_back() on the vector to remove/"return" the book
				{
					std::swap(my_books.book_collection.at(end_index), my_books.book_collection.at(index));
					my_books.book_collection.pop_back();
				}
				else
				// book is already at the end
				{
					my_books.book_collection.pop_back();
				}
			}
			cout << book.get_title() << " by " << book.get_author() << " has been returned!\n";
		}
	}

	ostream& operator << (ostream& os, const Book& obj)
	{
		return os << "[Book Info]\n"
			      << "-----------\n"
				  << "[Title]: " << obj.get_title() << '\n'
				  << "[Author]: " << obj.get_author() << '\n'
				  << "[ISBN]: " << obj.get_ISBN() << '\n'
				  << "[Genre]: " << obj.get_genre() << "\n\n";
	}

	istream& operator >> (istream& is, Book& obj)
	{
		string ISBN,
			   title,
			   author;
		int copyright{ 0 };
		Books::Genre genre{};

		const vector<string> prompts{ "Enter ISBN (d-d-d-l):\n",
									  "Enter book title:\n",
									  "Enter book author:\n",
									  "Enter copyright date (yyyy):\n",
									  "Enter genre (1-5):\nFiction\nNonfiction\nPeriodical\nBiography\nChildren\n\n" };

		const size_t prompts_size{ prompts.size() - 1 };

		for (size_t input{ 0 }; input < prompts_size; ++input)
		{
			switch (input)
			{
			case 0:
				cout << prompts.at(input);
				getline(cin, ISBN);
				break;
			case 1:
				cout << prompts.at(input);
				getline(cin, title);
				break;
			case 2:
				cout << prompts.at(input);
				getline(cin, author);
				break;
			case 3:
				cout << prompts.at(input);
				cin >> copyright;
				break;
			default:
				cerr << "[Error]: unknown value entered.\n";
				break;
			}
		}

		cout << prompts.at(prompts_size);
		int i_genre{ 0 };
		cin >> i_genre;

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

	bool operator == (const Book& obj1, const Book& obj2)
	{
		return obj1.get_ISBN() == obj2.get_ISBN()
			&& obj1.get_author() == obj2.get_author()
			&& obj1.get_title() == obj2.get_title()
			&& obj1.get_copyright_date() == obj2.get_copyright_date()
			&& obj1.get_genre() == obj2.get_genre();
	}

	bool operator != (const Book& obj1, const Book& obj2) { return !(obj1 == obj2); }
}
