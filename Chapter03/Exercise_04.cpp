#include <iostream>

void run_program();
int get_input();
int get_smaller(int val1, int val2);
int get_larger(int val1, int val2);
int get_sum(int val1, int val2);
int get_difference(int val1, int val2);
int get_product(int val1, int val2);
double get_ratio(int val1, int val2);
void display_results(int sm, int lg, int su, int df, int pd, double rt);

int main()
{
	run_program();

	return 0;
}

int get_input()
{
	std::cout << "Enter a value:\n";

	int val{ 0 };
	std::cin >> val;

	return val;
}

void run_program()
{
	int val1{ 0 };
	val1 = get_input();

	int val2{ 0 };
	val2 = get_input();

	int smaller{ 0 };
	smaller = get_smaller(val1, val2);

	int larger{ 0 };
	larger = get_larger(val1, val2);

	int sum{ 0 };
	sum = get_sum(val1, val2);

	int difference{ 0 };
	difference = get_difference(val1, val2);

	int product{ 0 };
	product = get_product(val1, val2);

	double ratio{ 0 };
	ratio = get_ratio(val1, val2);

	display_results(smaller, larger, sum, difference, product, ratio);
}

int get_smaller(int val1, int val2)
{
	if (val1 == val2)
	{
		return val1;
	}
	return val1 < val2 ? val1 : val2;
}

int get_larger(int val1, int val2)
{
	if (val1 == val2)
	{
		return val1;
	}
	return val1 > val2 ? val1 : val2;
}

int get_sum(int val1, int val2)
{
	return val1 + val2;
}

int get_difference(int val1, int val2)
{
	return val1 > val2 ? val1 - val2 : val2 - val1;
}

int get_product(int val1, int val2)
{
	return val1 * val2;
}

double get_ratio(int val1, int val2)
{
	double d_val1{ val1 + 0.0 };
	double d_val2{ val2 + 0.0 };

	if (d_val1 > d_val2)
	{
		
		return d_val1 / d_val2;
	}
	return d_val2 / d_val1;
}

void display_results(int sm, int lg, int su, int df, int pd, double rt)
{
	std::cout
		<< "smaller: " << sm << '\n'
		<< "larger: " << lg << '\n'
		<< "sum: " << su << '\n'
		<< "difference: " << df << '\n'
		<< "product: " << pd << '\n'
		<< "ratio: " << rt << '\n';
}
