#include "Roman_int.h"
#include <iostream

using std::cout;
using std::cin;
using std::cerr;

int main()
{
	try
	{
		Roman_Ints::Roman_int roman_numeral;

		cin >> roman_numeral;
		cout << roman_numeral;
	}
	catch (Roman_Ints::Roman_int::Invalid)
	{
		cerr << "[Error: invalid input]\n";
	}

	return 0;
}
