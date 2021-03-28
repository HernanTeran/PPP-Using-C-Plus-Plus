// Author: Hernan Teran
// Date:   2021/03/28
// Chapter 21 Exercise 3

#include <iostream>
#include <vector>

template <class In, class T>
// requires Input_iterator<In>() && Value_type<T>()
T my_count(In first, In last, T val);

int main()
{
	vector<int> v{ 2,4,5,6,5,32,5,8,7,6 };

	int n{ 5 };
	int ct = my_count(v.cbegin(), v.cend(), n);

	cout << n << " was found " << ct << " times.\n";
	
	return 0;
}

// using a for-loop
template <class In, class T>
// requires Input_iterator<In>() && Value_type<T>()
T my_count(In first, In last, T val)
{
	T ct{ 0 };
	for (first; first != last; ++first)
		if (*first == val) ++ct;
	return ct;
}

// using a while-loop
template <class In, class T>
// requires Input_iterator<In>() && Value_type<T>()
T my_count(In first, In last, T val)
{
	T ct{ 0 };
	while (first != last)
  {
    if (*first == val) ++ct;
    ++first;
  }
	return ct;
}
