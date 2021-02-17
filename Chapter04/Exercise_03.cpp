// Hernan Teran 2/17/2021
// Chapter 4 Exercise 3

// ------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using std::vector;
using std::size_t;
using std::cout;
using std::cin;

// ------------------------------------------------------------------------------------------------------------

struct Results
{
	vector<double> cities;
	double sum{ 0 };

	vector<double> distances;
	double min_distance{ 0 };
	double max_distance{ 0 };
	double mean_distance{ 0 };
};

// ------------------------------------------------------------------------------------------------------------

void fill_vector(vector<double>& v);
void get_sum(const vector<double>& v, double& sum);
void fill_results(Results& results);
void get_min_distance(const Results& results_rd, Results& results_wr);
void get_max_distance(const Results& results_rd, Results& results_wr);
void get_mean_distance(const Results& results_rd, Results& results_wr);

// ------------------------------------------------------------------------------------------------------------

void fill_vector(vector<double>& v) { for (double val{ 0 }; cin >> val;) { v.push_back(val); } }

void get_sum(const vector<double>& v, double& sum) { for (const auto& d : v) { sum += d; } }

void fill_results(Results& results)
{
	size_t x{ 0 };

	for (size_t y{ 1 }; y < results.cities.size(); ++y)
	{
		double distance = abs(results.cities.at(x) - results.cities.at(y));
		results.distances.push_back(distance);
		++x;
	}
}

void get_min_distance(const Results& results_rd, Results& results_wr)
{
	size_t x{ 1 };
	size_t y{ 2 };
	results_wr.min_distance = std::max(results_rd.distances.at(0), results_rd.distances.at(1));

	while (x < results_rd.distances.size() && y < results_rd.distances.size())
	{
		double temp = std::min(results_rd.distances.at(x), results_rd.distances.at(y));
		results_wr.min_distance = std::min(results_rd.min_distance, temp);
		++x;
		++y;
	}
}

void get_max_distance(const Results& results_rd, Results& results_wr)
{
	size_t x{ 1 };
	size_t y{ 2 };
	results_wr.max_distance = std::max(results_rd.distances.at(0), results_rd.distances.at(1));

	while (x < results_rd.distances.size() && y < results_rd.distances.size())
	{
		double temp = std::max(results_rd.distances.at(x), results_rd.distances.at(y));
		results_wr.max_distance = std::max(results_rd.max_distance, temp);
		++x;
		++y;
	}
}

void get_mean_distance(const Results& results_rd, Results& results_wr)
{
	results_wr.mean_distance =  results_rd.sum / results_rd.cities.size();
}

// -----------------------------------------------------------------------------------------------------------------------------

int main()
{
	Results results;
	fill_vector(results.cities);
	fill_results(results);
	get_sum(results.cities, results.sum);
	get_min_distance(results, results);
	get_max_distance(results, results);
	get_mean_distance(results, results);

	cout
		<< "sum of all distances: " << results.sum << '\n'
		<< "smallest distance between two neighboring cities: " << results.min_distance << '\n'
		<< "greatest distance between two neighboring cities: " << results.max_distance << '\n'
		<< "mean distance between two neighboring cities: " << results.mean_distance << '\n';

	return 0;
}
