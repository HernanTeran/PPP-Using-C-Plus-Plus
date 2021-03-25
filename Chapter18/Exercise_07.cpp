// Author: Hernan Teran
// Date: 2021/03/25
// Chapter 18 Exercise 7

#include <iostream>

using namespace std;

char* cat_dot(const char* s1, const char* s2);
char* cat_dot(const char* s1, const char* s2, const char* delim);

int main()
{
	char* s1 = new char[] { "Neils" };
	char* s2 = new char[] { "Bohr" };
	char* s3 = cat_dot(s1, s2);
	char* delim = new char[] { "MOON" };
	char* s4 = cat_dot(s1, s2, delim);

	cout << "s3: " s3 << "\ns4: " << s4 << endl;

	delete[] s1;
	delete[] s2;
	delete[] s3;
	delete[] delim;
	delete[] s4;

	return 0;
}

char* cat_dot(const char* s1, const char* s2)
{
	// validate pointers
	if (!s1 || !s2) { return nullptr; }

	size_t s1_sz{ 0 },  // s1 size - 1
		     s2_sz{ 0 },  // s2 size - 1
		     x{ 0 };      // loop variable for s2
	
	// get sizes
	for (size_t i{ 0 }; s1[i]; ++i) ++s1_sz;
	for (size_t i{ 0 }; s2[i]; ++i) ++s2_sz;

	// create array
	const size_t SZ = s1_sz + s2_sz + 2;
	char* s3 = new char[SZ];

	// copy to array
	for (size_t i{ 0 }; i != SZ; ++i)
	{
		if (i < s1_sz)
		// copy s1 first
		{
			s3[i] = s1[i];
		}
		else if (i == s1_sz)
		// copy '.'
		{
			s3[i] = '.';
		}
		else
		// copy s2
		{
			s3[i] = s2[x];
			++x;
		}
	}
	return s3; // s3 = s1.s2 or s1 + '.' + s2
}

char* cat_dot(const char* s1, const char* s2, const char* delim)
{
	// validate pointers
	if (!s1 || !s2 || !delim) { return nullptr; }

	size_t s1_sz{ 0 },   // s1 size - 1
		     s2_sz{ 0 },   // s2 size - 1
		     del_sz{ 0 },  // delim size - 1
		     i2{ 0 },      // second loop variable to keep for loop going
		     d{ 0 },       // delim loop variable
		     x{ 0 };       // s2 loop variable

	// get sizes
	for (size_t i{ 0 }; s1[i]; ++i) ++s1_sz;
	for (size_t i{ 0 }; s2[i]; ++i) ++s2_sz;
	for (size_t i{ 0 }; delim[i]; ++i) ++del_sz;

	// create array
	const size_t SZ = s1_sz + s2_sz + del_sz + 3;
	char* s3 = new char[SZ];

	// copy to array
	for (size_t i{ 0 }; i != SZ; ++i)
	{
		if (i < s1_sz)
		// copy s1 first
		{
			s3[i] = s1[i];
		}
		if (i == s1_sz)
		// begin copying delim
		// second loop variable is used to
		// avoid errors in for loop
		// then update i
		{
			i2 = i;
			while (delim[d])
			{
				s3[i2] = delim[d];
				++d;
				++i2;
			}
			i = i2;
		}
		if (i == (s1_sz + del_sz))
		// begin copying s2
		// second loop variable is used again
		// to pick up where it left off
		{
			i2 = i;
			while (s2[x])
			{
				s3[i2] = s2[x];
				++x;
				++i2;
			}
			i = i2;
			s3[i] = '\0';
			// done copying exit for loop
		}
	}
	return s3; // s3 = s1 + delim + s2 or s1delims2
}
