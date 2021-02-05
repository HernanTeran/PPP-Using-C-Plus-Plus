// Hernan Teran
// V1 - 1/26/2021
// V2 - 2/5/2021
// Excercises 5-7

#include "practice.h"
#include <vector>
#include <iostream>

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
        using Books::Book;
        using Patrons::Patron;
        using std::cout;
        using std::cin;

        Book book;
        //cin >> book;

        Patron patron{ "Chucky Lryoer", 123456, 12.54 };
       
        Patrons::pay_fee(patron);
       
    }
    catch (Books::Book::Invalid)
    {
        std::cerr << "[Error: failed book instantiation]\n";
    }
    catch (Patrons::Patron::Invalid)
    {
        std::cerr << "[Error: failed patron instantiation]\n";
    }
}
