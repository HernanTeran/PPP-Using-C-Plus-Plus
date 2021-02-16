// Hernan Teran 2/16/2021
// Chapter 3 Exercise 9
// This is a simple program that converts and prints
// a string representing a number as an integer.
// The program uses an if/else if/else construct
// but could have been better implemented with a map
// or a pair of vectors.

#include <iostream>
#include <string<

using std::string;
using std::cout;
using std::cin;

int main()
{
	for (string str_num; cin >> str_num;)
		{
			if (str_num == "zero") { cout << 0 << '\n'; }
			else if (str_num == "one") { cout << 1 << '\n'; }
			else if (str_num == "two") { cout << 2 << '\n'; }
			else if (str_num == "three") { cout << 3 << '\n'; }
			else if (str_num == "four") { cout << 4 << '\n'; }
			else if (str_num == "five") { cout << 5 << '\n'; }
			else if (str_num == "six") { cout << 6 << '\n'; }
			else if (str_num == "seven") { cout << 7 << '\n'; }
			else if (str_num == "eight") { cout << 8 << '\n'; }
			else if (str_num == "nine") { cout << 9 << '\n'; }
			else { cout << "not a number I know\n"; }
		}

	return 0;
}
