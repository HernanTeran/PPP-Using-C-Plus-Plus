#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace Name_pairs
{
	class Name_pair
	{
	public:
		// default constructor is fine

		void read_names(const std::string& prompt);
		void read_ages(const std::string& prompt);
		void print();
		void sort();
	private:
		std::vector<std::string> names;
		std::vector<double> ages;
	};
}
