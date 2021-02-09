// Hernan Teran
// V1 - 1/26/2021
// V2 - 2/5/2021
// V3 - 2/8/2021
// V4 - 2/9/2021

#include "practice.h"

int main()
{
	run_program();

	return 0;
}

void run_program()
{
	try
	{
		// test cases ------------------------------------------------------------------
		Books::Book rand_book{ "1-2-2-2-F", "The Shining", "Stephen King", 1805, Books::Genre::Biography };
		Patrons::Patron rand_patron{ "Gene Belcher", 123456 };
		// ------------------------------------------------------------------------------

		Books::Book book1;
		std::cin >> book1;
		std::cout << book1;

		Patrons::Patron patron1{ "Bob Belcher", 434323 };

		Local_Library::Library library;
		library.add_book(book1);
		library.add_patron(patron1);
		library.check_out_book(book1, patron1);

		// test case ------------------------------------------------------------------
		library.check_out_book(rand_book, rand_patron);
		// ----------------------------------------------------------------------------

		Books::Book book2;
		std::cin >> book2;
		std::cout << book2;

		Patrons::Patron patron2{ "Linda Belcher", 785342 };
		library.add_book(book2);
		library.add_patron(patron2);
		library.check_out_book(book2, patron2);

		library.print_debt_list();

		library.check_in_book(book1, patron1);
		library.check_in_book(book2, patron2);

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
