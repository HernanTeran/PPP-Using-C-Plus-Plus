#include <iostream>

// *READ*
// this program took FOREVER
// 1) use while-loops and iterate until end of string ( 0 )
// 2) instead of using integers to represent letters positions
//    in ASCII code just use the actual letters!!!!!!!!!!!!!!!
//    'a' = 32 so the whole time you could've USED it as an int
//    instead of trying to REPRESENT it as an int

void to_lower(char* s);

int main()
{
	char* c_str = new char[]{"Hello, World!"};
	to_lower(c_str);

	int i{ 0 };
	constexpr int end_of_str{ 0 };

	while (c_str[i] != end_of_str)
	{
		std::cout << c_str[i];
		++i;
	}

	delete[] c_str;

	return 0;
}

void to_lower(char* s)
{
	constexpr char upper_beg{ 'A'};
	constexpr char upper_end{ 'Z' };
	constexpr char lower_beg{ 'a' };

	int i{ 0 };
	constexpr int end_of_str{ 0 };

	while (s[i] != end_of_str)
	{
		if ((s[i] >= upper_beg) && (s[i] <= upper_end)) 
		{ 
			s[i] += lower_beg - upper_beg;
		}
		++i;
	}
}
