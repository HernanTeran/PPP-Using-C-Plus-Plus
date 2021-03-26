// Author: Hernan Teran
// Date:   2021/03/26
// Chapter 19 Exercise 2

#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
T sum(const vector<T>& vt, const vector<U>& vu);

int main()
{
	vector<int> vt, vu;

	for (int i{ 0 }; i != 100; ++i) vt.push_back(i);
	for (int i{ 100 }; i != 200; ++i) vu.push_back(i);

	vector<double> vdt, vdu;

	for (double d{ 0 }; d != 100; ++d) vdt.push_back(d * 4.64);
	for (double d{ 50 }; d != 150; ++d) vdu.push_back(d * 2.32);

	int is = sum(vt, vu);
	double ds = sum(vdt, vdu);

	cout << "int sum: " << is << "\ndouble sum: " << ds;

	return 0;
}

/// @brief Multiplies vt[i] with vu[i] then result is summed
/// @tparam T 'T'  any numerical element 
/// @tparam U 'U'  any numerical element
/// @param vt 'vt' a vector of type T
/// @param vu 'vu' a vector of type U
/// @return   's'  Contains the sum of vt[i] * vu[i]
template <typename T, typename U>
T sum(const vector<T>& vt, const vector<U>& vu)
{
	T s{ 0 };

	for (T i{ 0 }; i != vt.size(); ++i)
    s += (vt.at(i) * vu.at(i));

	return s;
}
