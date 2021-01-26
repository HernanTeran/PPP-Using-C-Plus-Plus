// Hernan Teran 1/26/2021
// V1
// Excercises 5-7

#include "Books.h"
#include <vector>
#include <iostream>

using std::cin;
using std::cerr;
using std::vector;

void run_program();

int main()
// The purpose of the program is to instantiate a book object to "check out" and then "return"
// If the invariant is not established an exception will be thrown to terminate the program
{
    run_program();

    return 0;
}

void run_program()
{
    try
    {
        Books::Book book; 
        cin >> book; // overloaded >> operator

        Books::Book_Collection my_books; // vector: hold books

        if (!book.is_checked_out())
        {
            Books::check_out(book, my_books);
            book.set_checked_out(true);
        }

        for (const auto &bo : my_books.book_collection)
        // outputting book data through overloaded << operator
        {
            cout << bo;
        }

        Books::return_book(book, my_books);
        book.set_checked_out(false);

    }
    catch (Books::Book::Invalid)
    // catch exception then terminate
    {
        cerr << "[Error]: invalid input\n";
    }
}
