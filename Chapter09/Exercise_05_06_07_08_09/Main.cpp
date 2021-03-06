// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 5 - 9
//
// Author: Hernan Teran
// Created: 2021/02/09
// Updated: 2021/03/22
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
* Create a Patron class for the library.
* The class will have a user's name, library card number, and library fees (if owed).
* Have functions that access this data, as well as a function to set the fee of the user.
* Have a helper function that returns a Boolean (bool) depending on whether or not the user owes a fee.
* Create a Library class.
* Include vectors of Books and Patrons.
* Include a struct called Transaction.
* Have it include a Book, a Patron, and a Date from the chapter.
* Make a vector of Transactions.
* Create functions to add books to the library, add patrons to the library, and check out books.
* Whenever a user checks out a book, have the library make sure that both the user
* and the book are in the library.
* If they aren't, report an error. Then check to make sure that the user owes no fees.
* If the user does, report an error.
* If not, create a Transaction, and place it the vector of Transactions.
* Also write a function that will return a vector that contains the names of all Patrons who owe fees.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#include "Main.h"

int main()
{
	Local_Library::driver("\nUnable to identify Book.\n",
		"\nUnable to identify Patron.\n",
		"\nUnable to complete Library transaction.\n");

	return 0;
}
