#include "Library.h"

namespace Local_Library
{
	Local_Library::Library::Library(const std::vector<Books::Book>& books_,
		const std::vector<Patrons::Patron>& patrons_)
		:
		books{ books_ }, patrons{ patrons_ }
	{
	}

	void Library::add_book(const Books::Book& book)
	{
		if (books.empty())
		{
			books.push_back(book);
			std::cout << book.get_title() << " by " << book.get_author() << " has been added to the library.\n";
			return;
		}

		for (const auto& b : books)
		{
			if (b == book)
			{ 
				std::cerr << "This book is already in the library!\n";
				return;
			}
			books.push_back(book);
			std::cout << book.get_title() << " by " << book.get_author() << " has been added to the library.\n";
		}
	}

	void Library::add_patron(const Patrons::Patron& patron)
	{
		if (patrons.empty())
		{
			patrons.push_back(patron);
			std::cout << patron.get_full_name() << " is now in the library.\n";
			return;
		}

		for (const auto& p : patrons)
		{
			if (p == patron)
			{ 
				std::cerr << "This patron is already in the library!\n";
				return;
			}
			patrons.push_back(patron);
			std::cout << patron.get_full_name() << " is now in the library.\n";
		}
	}

	void Library::check_out_book(Books::Book& book, Patrons::Patron& patron)
	{
		for (const auto& b : books)
		{
			if (b != book)
			{
				std::cerr << "This book is not in the library!\n";
				return;
			}
		}

		for (const auto& p : patrons)
		{
			if (p != patron)
			{
				std::cerr << "This patron is not in the library!\n";
				return;
			}
		}

		constexpr double zero_balance{ 0 };

		if (patron.get_library_fees() != zero_balance)
		{
			std::cerr
				<< patron.get_full_name() << " you have an outstanding balance of $"
				<< patron.get_library_fees() << ".\nYou are not allowed to check out a book until it is paid off.\n";
			return;
		}

		if (book.is_available())
		{
			book.check_out();
			patron.set_fee(1.08);
			transactions.push_back(Transaction{ book, patron });
			std::cout << "Happy Reading " << patron.get_full_name() << "!\n";
		}
		else
		{
			std::cerr << book.get_title() << " by " << book.get_author() << " is currently checked out.\n";
		}
	}

	void Library::check_in_book(Books::Book& book, Patrons::Patron& patron)
	{
		for (auto& t : transactions)
		{
			if (t.book == book && t.patron == patron)
				// return book and clear library fee
				// remove single transaction if there is only one in the vector
				// else move transaction to the back to be able to remove it by using pop_back()
			{
				book.return_book();

				constexpr double zero_balance{ 0 };
				patron.set_fee(zero_balance);

				constexpr std::size_t one_transaction{ 1 };
				if (transactions.size() == one_transaction)
				{ 
					transactions.pop_back(); 
				}
				else
				{
					const std::size_t last_transaction{ transactions.size() - one_transaction };
					std::swap(t, transactions.at(last_transaction));
				}

				std::cout << "Transaction has been cleared.\n";
				return;
			}
		}
		// if there are no matches
		std::cerr << "There are no matches for that book or patron.\n";
	}

	std::vector<Patrons::Patron> Library::patrons_in_debt(const Library& library)
	{
		std::vector<Patrons::Patron> patrons;

		if (library.transactions.empty())
		{
			std::cerr << "There are currently no transactions.\n";
			return patrons;
		}

		for (const auto& t : library.transactions)
		{
			constexpr double zero_balance{ 0 };

			if (t.patron.get_library_fees() != zero_balance) { patrons.push_back(t.patron); }
		}

		return patrons;
	}
}
