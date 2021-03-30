// Author: Hernan Teran
// Date:   2021/03/30
// Chapter 4 Exercise 13

#include "Main.h"

using namespace std;

vector<int> is_prime(int n);
int sieve(int n, int d);

int main()
{
	vector<int> primes = is_prime(101);

	for (const int x : primes)
		cout << x << '\n';

	return 0;
}

int sieve(int n, int d)
{
	return n * (n + d);
}

vector<int> is_prime(int n)
{
	vector<int> primes, not_prime;
	int p{ 0 };

	for (int i{ 2 }; i != n; ++i)
	{
		int d{ 1 };
		not_prime.push_back(static_cast<int>(pow(i, 2)));
		while (sieve(i, d) <= n)
		{
			not_prime.push_back(sieve(i, d));
			++d;
		}
    
    auto it = find(not_prime.cbegin(), not_prime.cend(), i);
		if (it == not_prime.cend())
			primes.push_back(i);
	}
  
	return primes;
}
