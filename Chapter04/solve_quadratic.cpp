#include <iostream>
#include <cmath>

using std::cout;

void solve_quadratic_func(const double a, const double b, const double c);

int main()
{
	double a{ 2.0 }, b{ -4.0 }, c{ -5.0 };
	solve_quadratic_func(a, b, c);
	
	return 0;
}

void solve_quadratic_func(const double a, const double b, const double c)
{
	constexpr double neg_b{ -1 };
	constexpr double two{ 2 };
	constexpr double four{ 4 };

	const double pos_ans = ((neg_b * b) + sqrt((pow(b, two) - four * (a * c)))) / (two * a);
	const double neg_ans = neg_b * pos_ans;

	cout << "+\t" << pos_ans << "\n-\t" << neg_ans << '\n';
}
