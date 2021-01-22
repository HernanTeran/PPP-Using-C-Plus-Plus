#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int val1{ 0 };
	int val2{ 0 };

	while (cin >> val1 >> val2)
	{
		if (val1 == val2)
		{
			cout << "the numbers are equal\n";
		}
		else
		{
			cout
				<< "the smaller value is: " << std::min(val1, val2) << '\n'
				<< "the larger value is: " << std::max(val1, val2) << '\n';
		}
	}

	return 0;
}
