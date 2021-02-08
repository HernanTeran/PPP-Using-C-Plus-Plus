#include <iostream>

using std::cout;
using std::cin;

// *READ*
// cin.getline(arr, sz, delim)
// cin reads until the delimiter or
// until the max characters have been read
// I get an error if I don't allocate
// by specifying an array vs char* arr = new char;
// the latter stills works but I get a 
// weird negative return code

int main()
{
    constexpr int sz{100};
    char* arr = new char[sz];

    constexpr char delim{'!'};
    cin.getline(arr, sz, delim);

    int i{0};
    constexpr int end_of_str{0};

    while (arr[i] != end_of_str)
    {
        cout << arr[i];
        ++i;
    }

    delete[] arr;

    return 0;
}
