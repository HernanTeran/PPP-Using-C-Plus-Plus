// Chapter 8 Exercise 11
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <vector>

using namespace std;

struct Results
{
	double max{ 0 }, min{ 0 }, mean{ 0 }, median{ 0 };
	friend ostream& operator<<(ostream& os, const Results& results)
	{
		return os << "largest: " << results.max << '\n'
			<< "smallest: " << results.min << '\n'
			<< "mean: " << results.mean << '\n'
			<< "median: " << results.median << '\n';
	}
};

double maxv(const vector<double>& v);
double minv(const vector<double>& v);
double meanv(const vector<double>& v);
double medv(const vector<double>& v);
Results get_stats(const vector<double>& v);

int main()
{
	vector<double> v;
	size_t MAX_SZ{ 10 };

	cout << "input " << MAX_SZ << " numbers:\n";
	for (double n{ 0 }; cin >> n;)
	{
		v.push_back(n);
		if (v.size() == MAX_SZ) { break; }
	}

	sort(v.begin(), v.end());
	cout << endl;

	Results results = get_stats(v);
	cout << results;

	return 0;
}

double maxv(const vector<double>& v)
{
	double max = v.at(0);

	for (size_t i{ 1 }; i != v.size(); ++i)
		max = (max >= v.at(i)) ? max : v.at(i);
	return max;
}

double minv(const vector<double>& v)
{
	double min = v.at(0);

	for (size_t i{ 1 }; i != v.size(); ++i)
		min = (min <= v.at(i)) ? min : v.at(i);
	return min;
}

double meanv(const vector<double>& v)
{
	double mean{ 0 };

	for (const double n : v)
		mean += n;
	return mean / v.size();
}

double medv(const vector<double>& v)
{
	if ((v.size() % 2) == 1)
		return v.at(v.size() / 2);    

	size_t i{ v.size() / 2 };
	return (v.at(i - 1) + v.at(i)) / 2;
}

Results get_stats(const vector<double>& v)
{
	Results results;
	results.max = maxv(v);
	results.min = minv(v);
	results.mean = meanv(v);
	results.median = medv(v);
	return results;
}
