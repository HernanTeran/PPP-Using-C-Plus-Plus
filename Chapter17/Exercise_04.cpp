#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;

// *READ*
// to read a char* use cin.getline(var, delim)
// the delimiter has to be a constexpr char delim{'0'}
// the integer 0 won't work
// however the integer 0 is used in loops to
// terminate at the end of the array
// char* == char arr[] but these don't get deleted
// because they are not allocated on the free store
// using the new operator

char* get_str(const std::string& prompt, int sz);
char* str_dup(const char* s);
void print_str(const char* c_s);

int main()
{
	constexpr int sz{ 50 };
	char* c_str_orig = get_str("Please enter your string:\n", sz);

	char* c_str_copy = str_dup(c_str_orig);
	print_str(c_str_copy);

	delete[] c_str_orig;
	delete[] c_str_copy;

	return 0;
}

char* get_str(const std::string& prompt, int sz)
{
	char* temp = new char[sz];
	constexpr char delim{ '0' };
	cout << prompt;
	cin.getline(temp, delim);

	return temp;
}

char* str_dup(const char* s)
{
	int i{ 0 };
	constexpr int end_of_str{ 0 };
	int sz{ 1 };

	while (s[i] != end_of_str)
	{
		++sz;
		++i;
	}

	char* temp_str = new char[sz];
	for (int x{ 0 }; x < sz; ++x) { temp_str[x] = s[x]; }

	return temp_str;
}

void print_str(const char* c_s)
{
	int i{ 0 };
	constexpr int end_of_str{ 0 };

	while (c_s[i] != end_of_str)
	{
		cout << c_s[i];
		++i;
	}
}
