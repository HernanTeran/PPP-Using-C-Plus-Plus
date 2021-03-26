#ifndef VECTOR_H
#define VECTOR_H
#pragma once

#include <algorithm>

template<typename T> // requires T<T>()
class Vector
{
public:
	// exception class
	struct out_of_range {};

	// constructors
	Vector() : sz{ 0 }, elem{ nullptr }, space{ 0 } {}
	explicit Vector(size_t s);
	Vector(std::initializer_list<T> lst);

	// copy operations
	Vector(const Vector& arg);
	Vector& operator=(const Vector& arg);

	// move operations
	Vector(Vector&& a) noexcept;
	Vector& operator=(Vector&& a) noexcept;

	// destructor
	~Vector() { delete[] elem; }

	// overloaded operators
	T& operator[](size_t n) { return elem[n]; }
	const T& operator[](size_t n) const { return elem[n]; }

	// public member functions

	// nonmodifying operations
	size_t size() const { return sz; }
	size_t capacity() const { return space; }
	// capacity - size = # of elements we could push_back 
	// without causing reallocation     

	// range-checking
	T& at(size_t n);
	const T& at(size_t n) const;

	// modifying operation
	void reserve(size_t newalloc);
	void resize(size_t newsize);
	void push_back(T d);

private:
	size_t sz, space;
	T* elem;
};

#endif // VECTOR_H