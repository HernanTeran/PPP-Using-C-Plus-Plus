// Author: Hernan Teran
// Date:   2021/03/26
// Chapter 19 Exercise 1

#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
void f(vector<T>& vt, const vector<U>& vu);

int main()
{
	vector<int> vt, vu;

	for (int i{ 0 }; i != 100; ++i) vt.push_back(i);
	for (int i{ 100 }; i != 200; ++i) vu.push_back(i);

	for (const int x : vt)
		cout << "old: " << x << '\n';
	cout << endl;

	f(vt, vu);

	for (const int x : vt)
		cout << "new: " << x << '\n';

	return 0;
}

/// @brief Adds the elements of one vector<U> to another vector<T>
/// @tparam T 'T'  any numerical element 
/// @tparam U 'U'  any numerical element
/// @param vt 'vt' a vector of type T
/// @param vu 'vu' a vector of type U
/// @return Elements are calculated into 'vt' by reference 
template <typename T, typename U>
void f(vector<T>& vt, const vector<U>& vu)
{
	if (vt.size() != vu.size()) return;

	for (T i{ 0 }; i != vt.size(); ++i)
		vt.at(i) += vu.at(i);
}
