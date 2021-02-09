#include "Name_pairs.h"

namespace Name_pairs
{
	void Name_pair::read_names(const std::string& prompt)
	{
		std::cout << prompt;

		for (std::string name; getline(std::cin, name);) 
		{ 
			const std::string stop{ "stop" };

			if (name == stop) { break; }
			names.push_back(name); 
		}
	}

	void Name_pair::read_ages(const std::string& prompt)
	{
		std::cout << prompt;

		for (int age{ 0 }; std::cin >> age;) { ages.push_back(age); }
	}

	void Name_pair::print()
	{
		if (names.empty()) { std::cerr << "There are no names to print.\n"; }
		if (ages.empty()) { std::cerr << "There are no ages to print.\n"; }

		if (names.empty() && ages.empty())
		{
			std::cerr << "There are no names or ages to print.\n";
			return;
		}

		if (names.size() > ages.size() || ages.size() > names.size())
		{
			std::cerr << "The lists are uneven. Unable to print.\n";
			return;
		}

		for (std::size_t i{ 0 }; i < names.size(); ++i)
		{
			std::cout << names.at(i) << '\t' << ages.at(i) << '\n';
		}
		std::cout << '\n';
	}

	void Name_pair::sort()
	{
		std::size_t min_index{ 0 };
		std::string min_value;
		int temp_age{ 0 };
		constexpr std::size_t one_name{ 1 };

		for (std::size_t start{ 0 }; start < (names.size() - one_name); ++start)
    // first loop excludes the last element
		{
      // these variables update every iteration
			min_index = start;
			min_value = names.at(start);
			temp_age = ages.at(start);

			for (std::size_t index{ start + one_name }; index < names.size(); ++index)
      // this loop iterates through all the elements
      // this loop begins after the first element
			{
				if (names.at(index) < min_value)
        // make changes
				{
					min_value = names.at(index);
					min_index = index;
					temp_age = ages.at(index);
				}
			}
      // confirm changes
			std::swap(names.at(min_index), names.at(start));
			std::swap(ages.at(min_index), ages.at(start));
		}
	}
}
