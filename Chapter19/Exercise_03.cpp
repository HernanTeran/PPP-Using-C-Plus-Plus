// Author: Hernan Teran
// Date:   2021/03/26
// Chapter 19 Exercise 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T, class U>
class Pair
{
	friend ostream& operator<<(ostream& os, const Pair<T, U>& p)
	{
		return os << '(' << p.p1() << ", " << p.p2() << ')';
	}

public:
	Pair() = default;
	Pair(T tt, U uu) : t{tt}, u{uu} {}

public:
	T p1() const { return t; }
	U p2() const { return u; }

	void set_p1(T tt) { t = tt; }
	void set_p2(U uu) { u = uu; }

	Pair& operator()(T tt, U uu)
	{
		t = tt;
		u = uu;
		return *this;
	}

private:
	T t;
	U u;
};

int main()
{
	Pair<char, int> p('y', 899);
	cout << p << '\n';
	p = p('e', 423);
	cout << p << '\n';
	
	Pair<double, int> p2(0.00234, 562);
	cout << p2 << '\n';
	p2 = p2(-42.32452, 9);
	cout << p2 << '\n';
	
	Pair<char, string> p3('k', "linger");
	cout << p3 << '\n';
	p3 = p3('l', "kite");
	cout << p3 << '\n';

	return 0;
}
