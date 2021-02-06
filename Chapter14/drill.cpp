#include <iostream>
#include <string>

using std::cout;
using std::string;

// ------------------------------------------------------------

class B1
{
public:
	// once created, pvf() caused two compiler errors
	// the first is that B1 can no longer be instantiated
	// because it is now an abstract class
	// the second is that D1 needs to override pvf()
	// since it is derived from B1
	virtual void pvf() = 0;
	virtual void vf() { cout << "I am B1::vf()\n"; }
	void f() { cout << "I am B1::f()\n"; }
};

// ------------------------------------------------------------

class D1 : public B1
{
public:
	void pvf() override { cout << "I am B1::D1::pvf()\n"; }
	void vf() override { cout << "I am B1::D1::vf()\n"; }
	void f() { cout << "I am D1::f()\n"; }
};

// ------------------------------------------------------------

class D2 : public D1
{
public:
	void pvf() override { cout << "I am B1::D1::D2::pvf()\n"; }
	void vf() override { cout << "I am B1::D1::D2::vf()\n"; }
	void f() { cout << "I am D2::f()\n"; }
};

// ------------------------------------------------------------

class B2
{
public:
	virtual void pvf() = 0;
};

// ------------------------------------------------------------

class D21 : public B2
{
public:
	string data;
	void pvf() override { cout << "B2::D21::pvf() str = " << data << '\n'; }
};

// ------------------------------------------------------------

class D22 : public B2
{
public:
	int data{ 0 };
	void pvf() override { cout << "B2::D22::pvf() int = " << data << '\n'; }
};

// ------------------------------------------------------------

int main()
{
	// B1 b1;
	// b1.vf();
	// b1.f();

	// --------------

	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	// --------------

	B1& bref{ d1 };
	bref.vf(); // calls D1 override of vf()
	bref.f(); // calls B1 f() before and after B1 is made abstract
	bref.pvf(); // calls D1 override of pvf()
	 
	// --------------

	D2 d2;
	d2.vf(); // calls D2 override of vf()
	d2.f(); // calls D2 f()
	d2.pvf(); // calls D2 override of pvf()

	// --------------

	D21 d21;
	d21.data = { "coffee" };
	d21.pvf(); // calls D21 override of pvf() and outputs string: "coffee"

	// --------------

	D22 d22;
	d22.data = { 108 };
	d22.pvf(); // calls D22 override of pvf() and outputs int: 108

	return 0;
}
