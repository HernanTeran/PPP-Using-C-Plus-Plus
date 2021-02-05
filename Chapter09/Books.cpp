#include "Book.h"

namespace Books
{
	using std::string;

	Book::Book::Book(const string& isbn_,
		const string& title_,
		const string& author_,
		const int copyright_date_,
		const Genre genre_)
		:
		isbn(isbn_),
		title(title_),
		author(author_),
		copyright_date(copyright_date_),
		genre(genre_)
	{
		if (!is_valid_book(isbn_, title_, author_, copyright_date_, genre_)) { throw Invalid{}; };
	}

	string Book::get_genre() const
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

	bool Books::is_valid_book(const string& isbn,
		const string& title,
		const string& author,
		const int copyright_date,
		const Genre genre)
	{
		// test ISBN ---------------------------------------------
		using std::regex;
		using std::smatch;

		regex pat{ R"(([0-9])\-([0-9])\-([0-9])\-([0-9])\-([a-zA-z]))" };
		smatch matches;

		if (!regex_match(isbn, matches, pat)) { return false; } // must match d-d-d-d-l

		// test title/author ---------------------------------------
		constexpr int min_str_len{ 3 };

		if (title.length() < min_str_len) { return false; }
		if (author.length() < min_str_len) { return false; }

		// test copyright date -------------------------------------
		constexpr int min_date{ 1800 };
		constexpr int max_date{ 2021 };

		if (copyright_date < min_date || copyright_date > max_date) { return false; }

		// test genre -----------------------------------------
		constexpr Genre min_genre{ Genre::Fiction };
		constexpr Genre max_genre{ Genre::Children };

		if (genre < min_genre || genre > max_genre) { return false; }

		return true; // passed all 5 tests
	}

	void check_out(const Book& book, Book_Collection& my_books)
	{
		using std::cout;
		using std::cerr;

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
				cerr << "[Error: you already have this book in your collection!]\n";
				return;
			}
			my_books.book_collection.push_back(book);
			cout << book.get_title() << " by " << book.get_author() << " has been added to your collection.\n";
			return;
		}
	}

	void return_book(const Book& book, Book_Collection& my_books)
	{
		using std::cerr;
		using std::cout;

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
				}
				// book is at the end
				my_books.book_collection.pop_back();
			}
			cout << book.get_title() << " by " << book.get_author() << " has been returned!\n";
		}
	}

	std::ostream& operator << (std::ostream& os, const Book& obj)
	{
		return os << "[Book Info]\n"
			<< "-----------\n"
			<< "[Title]: " << obj.get_title() << '\n'
			<< "[Author]: " << obj.get_author() << '\n'
			<< "[ISBN]: " << obj.get_ISBN() << '\n'
			<< "[Copyright Date]: " << obj.get_copyright_date() << '\n'
			<< "[Genre]: " << obj.get_genre() << "\n\n";
	}

	std::istream& operator >> (std::istream& is, Book& obj)
	{
		using std::vector;
		using std::cout;
		using std::cin;
		using std::cerr;

		string ISBN;
		string title;
		string author;
		int copyright{ 0 };
		Books::Genre genre{};

		const vector<string> prompts{ "Enter ISBN (d-d-d-l):\n",
									  "Enter book title:\n",
									  "Enter book author:\n",
									  "Enter copyright date (yyyy):\n",
									  "Enter genre (1-5):\nFiction\nNonfiction\nPeriodical\nBiography\nChildren\n\n" };

		const size_t prompts_size{ prompts.size() - 1 };

		for (size_t input{ 0 }; input < prompts_size; ++input)
			// excludes genre prompt because
			// it will be tested separately
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
				cerr << "[Error: unknown value entered.]\n";
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
