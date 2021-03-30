// Author: Hernan Teran
// Date:   2021/03/30
// Chapter 4 Exercise 11

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_prime(int x);
string prime_rep(bool ip);

int main()
{
	vector<int> primes;

	for (int i{ 1 }; i != 101; ++i)
		if (is_prime(i))
			primes.push_back(i);
		else
			cout << i << " = " << prime_rep(is_prime(i)) << '\n';

	cout << endl;

	for (const int i : primes)
		cout << i << " = " << prime_rep(is_prime(i)) << '\n';

	return 0;
}

bool is_prime(int x)
{
	if (x == 1) return false;

	for (int y{ x - 1 }; y != 1; --y)
		if (x % y == 0)
			return false;
	return true;
}

string prime_rep(bool ip)
{
	return ip ? "prime" : "not prime";
}
