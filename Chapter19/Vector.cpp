#include "Vector.h"

using namespace std;

template<typename T>
Vector<T>::Vector(size_t s) : sz{ s }, elem{ new T[s] }, space{ s }
{
	for (size_t i{ 0 }; i < sz; ++i) elem[i] = 0;
}

template<typename T>
Vector<T>::Vector(initializer_list<T> lst)
	: sz{ lst.size() }, elem{ new T[sz] }, space{ lst.size() }
{
	copy(lst.begin(), lst.end(), elem);
}

template<typename T>
Vector<T>::Vector(const Vector& arg) : sz{ arg.sz }, elem{ new T[arg.sz] }
{
	copy(arg.elem, arg.elem + sz, elem);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& arg)
{
	if (this == &arg) { return *this; } // self-assignment

	if (arg.sz <= space)
		// enough space new need for new allocation
		// copy elements
	{
		for (size_t i{ 0 }; i < arg.sz; ++i) { elem[i] = arg.elem[i]; }
		sz = arg.sz;
		return *this;
	}

	T* p = new T[arg.sz];      // allocate new space
	copy(arg.elem, arg.elem + sz, p);    // copy elements
	delete[] elem;                       // deallocate old space
	space = sz = arg.sz;                 // set new size
	elem = p;                            // reset elem by assignment
	return *this;                        // return a self-reference
}

template<typename T>
Vector<T>::Vector(Vector<T>&& a) noexcept
	: sz{ a.sz }, elem{ a.elem }
// copy a's elem and sz
{
	a.sz = 0;             // make a the empty vector
	a.elem = nullptr;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a) noexcept
// move a to this vector
{
	delete[] elem;       // deallocate old space
	elem = a.elem;       // copy a's elem and sz
	sz = a.sz;           
	a.elem = nullptr;    // make a the empty vector
	a.sz = 0;
	return *this;        // return a self-reference
}

template<typename T>
void Vector<T>::reserve(size_t newalloc)
{
	if (newalloc <= space) { return; }                        // never decrease allocation
	T* p = new T[newalloc];                         // allocate new space
	for (size_t i{ 0 }; i != sz; ++i) { p[i] = elem[i]; }     // copy old elements
	delete[] elem;                                            // deallocate old space
	elem = p;
	space = newalloc;
}

template<typename T>
void Vector<T>::resize(size_t newsize)
// make the vector have newsize elements
// initialize each new element with the default value
{
	reserve(newsize);
	for (size_t i{ sz }; i < newsize; ++i) { elem[i] = 0; } // initialize new elements
	sz = newsize;
}

template<typename T>
void Vector<T>::push_back(T d)
{
	if (space == 0)
		reserve(8);          // start with space for 8 elements
	else if (sz == space)    // get more space
		reserve(2 * space);
	elem[sz] = d;
	++sz;                    // increase the size
}

template<typename T>
T& Vector<T>::at(size_t n)
{
	if (n <= 0 || sz <= n) throw out_of_range{};
	return elem[n];
}

template<typename T>
const T& Vector<T>::at(size_t n) const
{
	if (n <= 0 || sz <= n) throw out_of_range{};
	return elem[n];
}