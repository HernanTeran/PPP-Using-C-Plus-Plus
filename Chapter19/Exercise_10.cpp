// Author: Hernan Teran
// Date:   2021/03/26
// Chapter 19 Exercise 10

#include <iostream>
#include <vector>

template<class T>
class Unique_ptr
{
public:
	// constructors
	Unique_ptr() : p{ nullptr } {}
	explicit Unique_ptr(T* pt) : p{ pt } {}

	// destructor
	~Unique_ptr() { delete p; }

	// copy operations deleted
	Unique_ptr(const Unique_ptr<T>&) = delete;
	Unique_ptr& operator = (const Unique_ptr&) = delete;

public:
	// public member functions

	T* release()
	{
		T* tp{ p };
		p = nullptr;
		return tp;
	}

	T& operator*() { return *p; }
	T* operator->() { return p; }

private:
	T* p;
};

using namespace std;

int main()
{
	Unique_ptr<int> ptr{ new int{25} };

	cout << *ptr << '\n'; // * works

	Unique_ptr<vector<int>> vptr{ new vector<int>{ 400, 302, 42 } };
	
	cout << vptr->at(0); // -> works

	return 0;
}
