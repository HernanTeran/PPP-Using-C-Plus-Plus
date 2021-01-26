//
// Hernan Teran 1/25/2021
//

#include "Books.h"
#include <utility>
#include <regex>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::regex;
using std::smatch;
using std::vector;

namespace Books
{
    // years/genres in [min:max) range
    static constexpr int min_year{1950};
    static constexpr int max_year{2021};
    static constexpr Genre min_genre{Genre::Fiction};
    static constexpr Genre max_genre{Genre::Children};
    static constexpr int min_name_len{7};
    static constexpr int min_title_len{4};

    // member function definitions

    Books::Book::Book(const string& isbn, const string& title_, const string& author_, int c_date, Genre genre_)
            :
            ISBN(isbn),
            title(title_),
            author(author_),
            copyright_date(c_date),
            genre(genre_)
    {
        if (!is_book(isbn, title_, author_, c_date, genre_)) { throw Invalid{};}
    }

    // helper functions

    bool is_book(const string& isbn_,
                 const string& title_,
                 const string& author_,
                 const int copyright_,
                 const Genre genre_)
    {
        if (copyright_ < min_year || copyright_ > max_year) {return false;} // copyright must be positive
        if (genre_ < min_genre || max_genre < genre_) {return false;}
        if (title_.length() < min_title_len) {return false;}
        if (author_.length() < min_name_len) {return false;}

        regex pat{R"(([0-9])\-([0-9])\-([0-9])\-([0-9])\-([a-zA-z]))"};
        smatch matches;

        if (!regex_match(isbn_, matches, pat)) {return false;} // must match d-d-d-d-l

        return true;
    }

    void check_out(Book& book, Book_Collection& my_books)
    {
        if (!book.is_checked_out())
        {
            my_books.book_collection.push_back(book);
            cout << "You have checked out " << book.get_title() << " by " << book.get_author() << ".\n";
            return;
        }
        else
        {
            cerr << "This book is currently checked out.\n";
            return;
        }
    }

    void return_book(Book& book, Book_Collection& my_books)
    {
        if (my_books.book_collection.empty())
        {
            cerr << "There are currently no books in my collection.\n";
            return;
        }

        for (size_t index{0}; index < my_books.book_collection.size(); ++index)
        {
            if (my_books.book_collection.at(index).get_ISBN() == book.get_ISBN())
            // this if-statement searches for a match
            {
                constexpr int one{1}; // avoiding magic constants
                const size_t end_index{my_books.book_collection.size() - one};

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
            cout << book.get_title() << " has been returned!\n";

            return;
        }
    }

    ostream& operator << (ostream& os, const Book& obj)
    {
        return os << "[Book Info]\n"
                  << "-----------\n"
                  << "[Title]: " << obj.get_title() << '\n'
                  << "[Author]: " << obj.get_author() << '\n'
                  << "[ISBN]: " << obj.get_ISBN() << "\n\n";
    }

    istream& operator >> (istream& is, Book& obj)
    {
        string ISBN,
               title,
               author;
        int copyright{0};
        Books::Genre genre{};

        const vector<string> prompts{"Enter ISBN (d-d-d-l):\n",
                               "Enter book title:\n",
                               "Enter book author:\n",
                               "Enter copyright date (yyyy):\n",
                               "Enter genre (1-5):\nFiction\nNonfiction\nPeriodical\nBiography\nChildren\n\n"};

        const size_t prompts_size{prompts.size() - 1};

        for (size_t input{0}; input < prompts_size; ++input)
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

        int int_genre{0};

        cout << prompts.at(prompts_size);
        cin >> int_genre;

        switch (int_genre)
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
                genre = Books::Genre::Fiction;
                cerr << "[Error]: invalid input\n"
                     << "[Fiction has been chosen as default]\n";
                break;
        }

        obj = Book{ISBN, title, author, copyright, genre};

        return is;
    }

    bool operator == (const Book& obj1, const Book& obj2)
    {
        return obj1.get_ISBN() == obj2.get_ISBN()
               && obj1.get_author() == obj2.get_author()
               && obj1.get_title() == obj2.get_title()
               && obj1.get_copyright_date() == obj2.get_copyright_date()
               && obj1.is_checked_out() == obj2.is_checked_out();
    }

    bool operator != (const Book& obj1, const Book& obj2)
    {
        return !(obj1 == obj2);
    }
}