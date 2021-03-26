// Author: Hernan Teran
// Date:   2021/03/26
// Chapter 19 Exercise 1

#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
vector<T> f(const vector<T>& vt, const vector<U>& vu);

int main()
{
	vector<int> vt, vu, vf;

	for (int i{ 0 }; i != 100; ++i) vt.push_back(i);
	for (int i{ 100 }; i != 200; ++i) vu.push_back(i);

	vf = f(vt, vu);

	for (const int x : vf)
		cout << x << '\n';

	return 0;
}

/// @brief Adds the elemnts of one vector<U> to another vector<T>
/// @tparam T 'T'  any numerical element 
/// @tparam U 'U'  any numerical element
/// @param vt 'vt' a vector of type T
/// @param vu 'vu' a vector of type U
/// @return   'vf' a vector of type T containing vt[i] += vu[i] 
template <typename T, typename U>
vector<T> f(const vector<T>& vt, const vector<U>& vu)
{
	vector<T> vf;

	for (T i{ 0 }; i != vt.size(); ++i)
		vf.push_back(vt.at(i) + vu.at(i));

	return vf;
}
