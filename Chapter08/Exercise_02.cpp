#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

void print(const string& label, const vector<int>& numbers);

int main()
{
	vector<int> numbers;

	for (int i{ 0 }; cin >> i;) { numbers.push_back(i); }
	print("index ", numbers);

	return 0;
}

void print(const string& label, const vector<int>& numbers)
{
	for (std::size_t i{ 0 }; i < numbers.size(); ++i)
	{
		cout << label << i << ": " << numbers.at(i) << '\n';
	}
}
