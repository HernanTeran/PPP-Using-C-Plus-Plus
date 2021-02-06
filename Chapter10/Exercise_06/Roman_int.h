#pragma once
#include <string>
#include <iostream>

namespace Roman_Ints
{
	class Roman_int
	{
	private:
		std::string roman_numeral;
	public:
		class Invalid{};

		Roman_int() = default;

		Roman_int(const std::string& roman_num);

		std::string get_roman_numeral() const { return roman_numeral; }
		int as_int();
	};

	bool is_valid(const std::string& roman_num);

	std::ostream& operator << (std::ostream& os, Roman_int& obj);
	std::istream& operator >> (std::istream& is, Roman_int& obj);
}
