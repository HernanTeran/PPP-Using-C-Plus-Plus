// Author: Hernan Teran
// Date:   2021/03/25
// Chapter 18 Exercise 3

#include <iostream>

using namespace std;

int str_cmp(const char* s1, const char* s2);

int main()
{
	// testing == 
	// res1 = 0
	char* a = "Apple";
	char* b = "Arthur";
	int res1 = str_cmp(a, b);

	// testing <
	// res2 = -1
	char* c = "Chocolate";
	char* d = "Default";
	int res2 = str_cmp(c, d);

	// testing >
	// res3 = 1
	char* e = "Train";
	char* f = "Cabbage";
	int res3 = str_cmp(e, f);

	// testing nullptr
	char* g = nullptr;
	char* h = "Beer";
	int res4 = str_cmp(g, h);

	cout << "res1 (==): " << res1 << '\n'
		<< "res2 (<): " << res2 << '\n'
		<< "res3 (>): " << res3 << '\n'
		<< "res4 (nullptr): " << res4 << '\n';

	return 0;
}

int str_cmp(const char* s1, const char* s2)
{
	if (!s1 || !s2) { return -2; }
	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	return 0; // s1 == s2
}
