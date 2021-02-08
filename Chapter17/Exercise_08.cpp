#include <iostream>

// *READ*
// compared to C-style strings...
// much easier..............

int main()
{
    std::string str;
    constexpr char delim{'!'};
    getline(std::cin, str, delim);

    std::cout << str;

    return 0;
}
