// Chapter 8 Exercise 5
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fibonacci(int x, int y, vector<int>& v, size_t n);
void print(const vector<int>& v, const string& label);
vector<int> reverse_copy(const vector<int>& v);

int main()
{
	vector<int> fib_nums;

	int ind_0{ 0 }, ind_1{ 0 };
	size_t MAX_SZ{ 0 };
	cout << "enter v[0] and v[1] (v[0] < v[1])\n"
		<< "then enter total numbers to calculate\n"
		<< "> ";
	cin >> ind_0 >> ind_1 >> MAX_SZ;

	fibonacci(ind_0, ind_1, fib_nums, MAX_SZ);
	print(fib_nums, "[O] index #");

	cout << endl;

	vector<int> rc_fib_nums = reverse_copy(fib_nums);
	print(rc_fib_nums, "[RC] index #");

	cout << endl;

	return 0;
}

void fibonacci(int x, int y, vector<int>& v, size_t n)
{
	v.push_back(x);
	v.push_back(y);

	for (size_t i{ 2 }; v.size() != n; i++)
		v.push_back(v.at(i - 1) + v.at(i - 2));
}

void print(const vector<int>& v, const string& label)
{
	for (size_t i{ 0 }; i != v.size(); ++i)
		cout << label << i << ": " << v.at(i) << '\n';
}

vector<int> reverse_copy(const vector<int>& v)
{
	vector<int> new_v;
	for (size_t i{ v.size() - 1 }; i != 0; --i)
		new_v.push_back(v.at(i));
	new_v.push_back(v.at(0));
	return new_v;
}
