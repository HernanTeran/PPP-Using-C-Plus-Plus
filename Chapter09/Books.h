// Hernan Teran 1/25/2021

#ifndef C___CLION_BOOKS_H
#define C___CLION_BOOKS_H
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;
using std::istream;

namespace Books
{
    enum class Genre {Fiction = 1, Nonfiction, Periodical, Biography, Children};

    class Book
    {
    private:
        string ISBN,
                title,
                author;
        int copyright_date{0};
        Genre genre{};
        bool checked_out{false};

    public:
        class Invalid{}; // to throw as exception

        Book() = default;
        Book(const string& isbn, const string& title_, const string& author_, int c_date, Genre genre_);
        // check for valid input and initialize

        // non-modifying operations
        string get_ISBN() const {return ISBN;}
        string get_title() const {return title;}
        string get_author() const {return author;}
        int get_copyright_date() const {return copyright_date;}
        bool is_checked_out() const {return checked_out;}

        // modifying operation
        void set_checked_out(bool is_out) {checked_out = is_out;}

    };

    bool is_book(const string& isbn_,
                 const string& title_,
                 const string& author_,
                 int copyright_,
                 Genre genre_); // true for valid book

    struct Book_Collection // store data
    {
        vector<Book> book_collection;
    };

    void check_out(Book&, Book_Collection&); // if book isn't checked out add to vector my_books
    void return_book(Book&, Book_Collection&); // book will be removed from my books to "return"

    ostream& operator << (ostream& os, const Book& obj);
    istream& operator >> (istream& is, Book& obj);

    bool operator == (const Book& obj1, const Book& obj2);
    bool operator != (const Book& obj1, const Book& obj2);
}

#endif //C___CLION_BOOKS_H