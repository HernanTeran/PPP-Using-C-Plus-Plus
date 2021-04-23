#ifndef VECTOR_H
#define VECTOR_H
#pragma once

class Vector
{
public:
	Vector(int s) : sz{ s }, elem{ new double[s] }
	{
		for (int i{ 0 }; i != s; ++i)
      elem[i] = 0; // initialize elements to 0
	}
  
  ~Vector() { delete[] elem; }
  
public:
	int size() const { return sz; }
	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }
  
private:
	int sz{ 0 };
	double* elem{ nullptr };
};

#endif // VECTOR_H
