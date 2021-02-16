// Hernan Teran 2/16/2021
// Chapter 4 Exercise 2

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;

int main()
{
	vector<double> temps;
	for (double temp{ 0 }; cin >> temp;) { temps.push_back(temp); }

	double sum{ 0 };
	for (double x : temps) { sum += x; }
	cout << "Average temperature: " << sum / temps.size() << '\n';

	std::sort(temps.begin(), temps.end());

	double median{ 0 };

	if (temps.size() % 2 == 0) { median = temps.at(temps.size() / 2); }
	else { median = (((temps.size() - 1) / 2) + ((temps.size() + 1) / 2)) / 2; }

	cout << "Median teperature: " << median << '\n';

	return 0;
}
