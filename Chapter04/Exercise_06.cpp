#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> str_values{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<int> int_values{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (;;)
	{
		int digit{ 0 };
		cout << "Enter a digit 0-9: ";
		cin >> digit;
		if (!cin) { break; }

		string str_digit;
		cout << "Enter a digit zero-nine: ";
		cin >> str_digit;

		for (int i{ 0 }; i != str_values.size(); ++i)
		{
			if (digit == int_values.at(i))
			{
				cout << "Your digit " << digit << " is " << str_values.at(i) << '\n';
			}
			if (str_digit == str_values.at(i))
			{
				cout << "Your digit " << str_digit << " is " << int_values.at(i) << '\n';
			}
		}
		cout << endl;
  }
  
	return 0;
}
