#include <utility>
#include <vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <map>
#include <functional>

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::regex;
using std::smatch;
using std::vector;
using std::size_t;

// namespace make header namespace.h
// enum class
// class
// data members
// class Invalid{}
// constructors
// nonmodifying/modifying operations
// bool is_valid(same parameters as constructor) function
// is_valid returns true and has multiple returns for false
// overloaded operators
// Class_Object functions(const Class& c);
// helper functions

#include "Books.h"

void run_program();

int main()
{
    run_program();

    return 0;
}

void run_program()
{
    try
    {
        Books::Book book;

        cin >> book;

        Books::Book_Collection my_books;

        if (!book.is_checked_out())
        {
            Books::check_out(book, my_books);
            book.set_checked_out(true);
        }

        for (const auto &bo : my_books.book_collection)
        {
            cout << bo;
        }

        Books::return_book(book, my_books);
        book.set_checked_out(false);

    }
    catch (Books::Book::Invalid)
    {
        cerr << "[Error]: invalid input\n";
    }
}