#include <iostream>

using namespace std;

// *READ*
// to read a char* use cin.getline(var, delim)
// the delimiter has to be a constexpr char delim{'0'}
// the integer 0 won't work
// however the integer 0 is used in loops to
// terminate at the end of the array
// char* == char arr[] but these don't get deleted
// because they are not allocated on the free store
// using the new operator

char* str_dup(const char* s, int SZ);

int main()
{
	char* s = new char[] {"ham and apples"};
	
	int SZ{ 1 };
	
	for (int i{ 0 }; s[i] != '\0'; ++i)
		++SZ;

	char* sc = str_dup(s, SZ);

	for (int i{ 0 }; i != SZ; ++i)
		cout << sc[i];
	
	delete[] s;
	delete[] sc;

	return 0;
}

char* str_dup(const char* s, int SZ)
{
	char* c = new char[SZ];

	for (int i{ 0 }; i != SZ; ++i)
		c[i] = s[i];

	return c;
}
