// Chapter 8 Exercise 9
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fill(vector<double>& v, const size_t SZ, const string& prompt);

int main()
{
	vector<double> prices, weights, sums;

	cout << "Enter the total items that will be entered: ";
	size_t SZ{ 0 };
	cin >> SZ;

	fill(prices, SZ, "Enter prices:\n");
	fill(weights, SZ, "Enter weights of items:\n");

	for (size_t i{ 0 }; i != weights.size(); ++i)
		sums.push_back(prices.at(i) * weights.at(i));

	for (const double sum : sums)
		cout << "sum: " << sum << '\n';

	return 0;
}

void fill(vector<double>& v, const size_t SZ, const string& prompt)
{
	cout << prompt;
	for (double d{ 0 }; cin >> d;)
	{
		v.push_back(d);
		if (v.size() == SZ) { break; }
	}
}
