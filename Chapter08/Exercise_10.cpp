// Chapter 8 Exercise 10
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <vector>

using namespace std;

int maxv(const vector<int>& v);

int main()
{
	vector<int> v;
	size_t MAX_SZ{ 10 };

	cout << "input " << MAX_SZ << " numbers:\n";
	for (int n{ 0 }; cin >> n;)
	{
		v.push_back(n);
		if (v.size() == MAX_SZ) { break; }
	}

	cout << endl;

	int max = maxv(v);
	cout << "largest element: " << max << '\n';
	
	return 0;
}

int maxv(const vector<int>& v)
{
	int max = v.at(0);

	for (size_t i{ 1 }; i != v.size(); ++i)
		max = (max >= v.at(i)) ? max : v.at(i);
	return max;
}
