// Author: Hernan Teran
// Date:   2021/03/25
// Chapter 18 Exercise 3

// Same as Exercise_03 but with char* allocated on the heap.

using namespace std;

int str_cmp(const char* s1, const char* s2);

int main()
{
	//Vector v;

	// testing == 
	// res1 = 0
	char* a = new char[] { "Apple" };
	char* b = new char[] { "Arthur" };
	int res1 = str_cmp(a, b);

	// testing <
	// res2 = -1
	char* c = new char[] { "Chocolate" };
	char* d = new char[] { "Default" };
	int res2 = str_cmp(c, d);

	// testing >
	// res3 = 1
	char* e = new char[] { "Train" };
	char* f = new char[] { "Cabbage" };
	int res3 = str_cmp(e, f);

	// testing for nullptr
	char* g = nullptr;
	char* h = new char[] {"Beer" };
	int res4 = str_cmp(g, h);

	cout << "res1 (==): " << res1 << '\n'
		<< "res2 (<): " << res2 << '\n'
		<< "res3 (>): " << res3 << '\n'
		<< "res4 (nullptr): " << res4 << '\n';

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
	delete[] e;
	delete[] f;
	delete[] g;
	delete[] h;

	return 0;
}

int str_cmp(const char* s1, const char* s2)
{
	if (!s1 || !s2) { return -2; }
	if (*s1 < *s2) return -1;
	if (*s1 > *s2) return 1;
	return 0; // s1 == s2
}
