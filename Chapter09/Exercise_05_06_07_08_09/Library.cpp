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
		}

		books.push_back(book);
		std::cout << book.get_title() << " by " << book.get_author() << " has been added to the library.\n";
		return;
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
		}

		patrons.push_back(patron);
		std::cout << patron.get_full_name() << " is now in the library.\n";
		return;
	}

	void Library::check_out_book(Books::Book& book, Patrons::Patron& patron)
	{
		bool book_match{ true };

		for (std::size_t b{ 0 }; b != books.size(); ++b)
		{
			if (books.at(b) == book)
			{
				std::cout << book.get_title() << " with ISBN " << book.get_isbn() << " has been found.\n";
				break;
			}

			constexpr double last_book{ 1 };

			if (b == books.size() - last_book)
			{
				std::cerr << "This book is not in the library!\n";
				book_match = false;
			}
		}

		bool patron_match{ true };

		for (std::size_t p{ 0 }; p != patrons.size(); ++p)
		{
			if (patrons.at(p) == patron)
			{
				std::cout << patron.get_full_name() << " with account number " 
						  << patron.get_account_number() << " has been found.\n";
				break;
			}

			constexpr double last_patron{ 1 };

			if (p == patrons.size() - last_patron)
			{
				std::cerr << "This patron is not in the library!\n";
				patron_match = false;
			}
		}

		if (!book_match || !patron_match) { return; }

		for (const auto& t : transactions)
		{
			if (t.book == book && t.patron == patron)
			{
				std::cerr << "You have already checked this book out!\n";
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
			constexpr double base_fee{ 1.08 };
			patron.set_fee(base_fee);
			transactions.push_back(Transaction{ book, patron });
			patrons_in_debt.push_back(patron);
			std::cout << "Happy Reading " << patron.get_full_name() << "!\n";
			return;
		}
		else
		{
			std::cerr << book.get_title() << " by " << book.get_author() << " is currently checked out.\n";
			return;
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
					std::cout << "Transaction has been cleared.\n";
					return;
				}
				else
				{
					const std::size_t last_transaction{ transactions.size() - one_transaction };

					std::swap(t, transactions.at(last_transaction));
					transactions.pop_back();
					std::cout << "Transaction has been cleared.\n";
					return;
				}
			}
		}

		for (auto& p : patrons_in_debt)
		{
			constexpr std::size_t one_patron{ 1 };

			if (patrons_in_debt.size() == one_patron)
			{
				patrons_in_debt.pop_back();
				std::cout << p.get_full_name() << " has been cleared from in-debt list.\n";
				return;
			}
			else
			{
				const std::size_t last_patron{ patrons_in_debt.size() - one_patron };

				std::swap(p, patrons_in_debt.at(last_patron));
				patrons_in_debt.pop_back();
				std::cout << p.get_full_name() << " has been cleared from in-debt list.\n";
				return;
			}
		}

		// if there are no matches
		std::cerr << "There are no matches for that book or patron.\n";
		return;
	}

	void Library::print_debt_list()
	{
		if (transactions.empty())
		{
			std::cerr << "There are currently no transactions.\n";
			return;
		}

		std::cout << "\n*PATRONS IN-DEBT*\n"
			      << "------------------\n";
		for (const auto& p : patrons_in_debt) { std::cout << p.get_full_name() << '\n'; }
		std::cout << '\n';

		return;
	}
}
