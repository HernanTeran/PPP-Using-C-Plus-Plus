#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::cerr;
using std::vector;
using std::size_t;

class Bad_Input
// simple exception class
{
private:
	int value;

public:
	Bad_Input(int val) : value(val) {}

    int get_error_value() { return value; }
};

int get_value();
int sum_n_values();
void display_numbers(vector<int>&, int);

int main()
{
	try
	{
		int n_total{ 0 };
		n_total = sum_n_values();
		
		unsigned int u_total{ 0 };
		u_total = n_total;

		vector<int> values;

		int value{ 0 };

		while (values.size() < u_total)
		{
			value = get_value();
			values.push_back(value);
		}

		int sum{ 0 };

		for (const auto& v : values)
		{
			sum += v;
		}

		cout << "The sum of the first " << n_total << " numbers ";
		display_numbers(values, n_total);
		cout << " is " << sum << '\n';

		values.clear();
	}
	catch (Bad_Input& error)
	{
		cerr << "[invalid input]: " << error.get_error_value() << '\n';
	}
	
	return 0;
}

int sum_n_values()
{
	cout << "Please enter the number of values you want to sum:\n";

	int n{ 0 };
	cin >> n;

	if (!cin || n < 0) { throw Bad_Input(n); }

	return n;
}

int get_value()
{	
	cout << "Please enter some integers (press '|' to stop):\n";

	int value{ 0 };
	cin >> value;
	
	if (!cin || value < 0) { throw Bad_Input(value); }

	return value;
}

void display_numbers(vector<int>& values, int count)
{
	unsigned int u_count{ 0 };
	u_count = count;

	cout << "( ";

	for (size_t i{ 0 }; i < u_count; ++i)
	{
		cout << values.at(i) << " ";
	}

	cout << ')';
}
