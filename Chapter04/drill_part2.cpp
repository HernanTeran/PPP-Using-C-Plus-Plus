#include <iostream>

using std::cout;
using std::cin;

int main()
{
	double val1{ 0 };
	double val2{ 0 };
	double smaller{ 0 };
	double larger{ 0 };

	while (cin >> val1)
	{
		smaller = std::min(val1, val2);
		larger = std::max(val1, val2);

		cout << "the smaller value is: " << smaller << '\n'
			   << "the larger value is: " << larger << '\n';

		if (val1 < smaller)
		{
			cout << "the smallest so far: " << val1 << '\n';
		}
		else
		{
			cout << "the smallest so far: " << smaller << '\n';
		}
	
		if (val1 > larger)
		{
			cout << "the largest so far: " << val1 << '\n';
		}
		else
		{
			cout << "the largest so far: " << larger << '\n';
		}

		val2 = val1;
	}

	return 0;
}
