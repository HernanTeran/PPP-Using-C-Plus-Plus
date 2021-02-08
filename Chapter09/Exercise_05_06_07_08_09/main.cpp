// Hernan Teran
// V1 - 1/26/2021
// V2 - 2/5/2021
// V3 - 2/8/2021
// Excercises 5-7

#include "practice.h"

// next time implement a second book and patron
// make sure there are no bugs when running any of the
// functions intended to work with only matches
// implement static variables to replace repetitive variables

int main()
{
	try
	{
		Books::Book book1;
		std::cin >> book1;
		std::cout << book1;

		Patrons::Patron patron1{"Bob Belcher", 434323};

		Local_Library::Library library;
		library.add_book(book1);
		library.add_patron(patron1);
		library.check_out_book(book1, patron1);

		std::vector<Patrons::Patron> in_debt = library.patrons_in_debt(library);

		for (const auto& p : in_debt)
		{
			std::cout 
				<< "\n*patrons in debt*\n"
				<< "-----------------\n"
				<< p.get_full_name() << '\n';
			std::cout << '\n';
		}

		library.check_in_book(book1, patron1);
	}
	catch (Books::Book::Invalid)
	{
		std::cerr << "What are you thinking?\n";
	}
	catch (Patrons::Patron::Invalid)
	{
		std::cerr << "WHAT.ARE.YOU.DOING?\n";
	}
}
