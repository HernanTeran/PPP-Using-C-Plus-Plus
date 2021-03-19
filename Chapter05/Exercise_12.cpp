// Chapter 5 Exercise 12
// Author: Hernan Teran
// Created on: 2021/03/19

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> get_number(const size_t MAX_SZ);
vector<int> get_guess(const string& prompt, const size_t MAX_SZ);

int main()
{
	constexpr size_t MAX_SZ{ 4 };
	vector<int> number = get_number(MAX_SZ);
	
	int bulls{ 0 }, cows{ 0 };
	constexpr int MAX_BULLS{ 4 };

	vector<int> found_nums;

	while (bulls != MAX_BULLS)
	{
		vector<int> guess = get_guess("input 4 unique digits:", MAX_SZ);

		for (size_t i{ 0 }; i != number.size(); ++i)
		{
			if (number.at(i) == guess.at(i))
			{
				if (found_nums.empty())
				{
					found_nums.push_back(guess.at(i));
					++bulls;
					cout << "(first) +1 bull at index #" << i << '\n';
				}
				else
				{
					auto it = find(found_nums.cbegin(), found_nums.cend(), guess.at(i));
					if (it == found_nums.cend())
					{
						found_nums.push_back(guess.at(i));
						++bulls;
						cout << "+1 bull at index #" << i << '\n';
					}
				}
			}
			else
			{
				auto it = find(number.cbegin(), number.cend(), guess.at(i));
				if (it != number.cend())
				{
					++cows;
					cout << "+1 cow at index #" << i << '\n';
				}
			}
		}
		cout << "[current bulls: " << bulls << "]\n\n";
	}

	cout << "\nYou guessed the number ";
	for (const int num : number)
		cout << num;
	cout << endl;
	
	return 0;
}

vector<int> get_number(const size_t MAX_SZ)
{
	vector<int> v;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> rand(0, 9);

	while (v.size() != MAX_SZ)
	{
		int rand_num = rand(gen);
		if (v.empty())
			v.push_back(rand_num);
		else
		{
			auto it = find(v.cbegin(), v.cend(), rand_num);
			if (it == v.cend())
				v.push_back(rand_num);
		}
	}
	return v;
}

vector<int> get_guess(const string& prompt, const size_t MAX_SZ)
{
	cout << prompt << '\n';
	vector<int> v;

	for (int i{ 0 }; cin >> i;)
	{
		if (v.empty())
			v.push_back(i);
		else
		{
			auto it = find(v.cbegin(), v.cend(), i);
			if (it == v.cend())
				v.push_back(i);
			if (v.size() == MAX_SZ)
				break;
		}
	}
	return  v;
}
