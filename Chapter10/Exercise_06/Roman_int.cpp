#include "Roman_int.h"

namespace Roman_Ints
{
	Roman_int::Roman_int(const std::string& roman_num) : roman_numeral(roman_num)
	{
		if (!is_valid(roman_num)) { throw Invalid{}; }
	}

	int Roman_int::as_int()
	{
		int rn_as_int{ 0 };

		for (const auto& c : roman_numeral)
		{
			switch (c)
			{
			case 'i':
			case 'I':
				++rn_as_int;
				break;
			case 'v':
			case 'V':
				rn_as_int += 5;
				break;
			case 'x':
			case 'X':
				rn_as_int += 10;
				break;
			case 'l':
			case 'L':
				rn_as_int += 50;
				break;
			case 'c':
			case 'C':
				rn_as_int += 100;
				break;
			case 'd':
			case 'D':
				rn_as_int += 500;
				break;
			case 'm':
			case 'M':
				rn_as_int += 1000;
				break;
			default:
				rn_as_int = 0;
				std::cerr << "error unknown character\n";
				break;
			}
		}
		return rn_as_int;
	}

	bool is_valid(const std::string& roman_num)
	{
		for (const auto& c : roman_num)
		{
			switch (c)
			{
			case 'i':
			case 'I':
			case 'v':
			case 'V':
			case 'x':
			case 'X':
			case 'l':
			case 'L':
			case 'c':
			case 'C':
			case 'd':
			case 'D':
			case 'm':
			case 'M':
				continue;
			default:
				return false;
			}
		}
		return true;
	}

	std::ostream& operator <<(std::ostream& os, Roman_int& obj)
	{
		os << "Roman " << obj.get_roman_numeral()
			<< " equals " << obj.as_int() << '\n';
		return os;
	}

	std::istream& operator >>(std::istream& is, Roman_int& obj)
	{
		std::cout
			<< "Convert a Roman Numeral to an Integer\n"
			<< "-------------------------------------\n"
			<< "i, I\t\t=\t\t1\n"
			<< "v, V\t\t=\t\t5\n"
			<< "x, X\t\t=\t\t10\n"
			<< "l, L\t\t=\t\t50\n"
			<< "c, C\t\t=\t\t100\n"
			<< "d, D\t\t=\t\t500\n"
			<< "m, M\t\t=\t\t1000\n\n"
			<< "Enter:\n";

		std::string roman_num;

		is >> roman_num;
		if (!is) { return is; }

		obj = Roman_int{ roman_num };

		return is;
	}
}
