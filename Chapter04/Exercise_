#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::vector;
using std::size_t;

void run_program();
void prompt();
void display_results(const vector<string>&, const vector<int>&);
void search_for_name(const vector<string>&);
void search_for_score(const vector<int>&);

int main()
{
	run_program();
	
	return 0;
}

void prompt()
{
	cout << "input a name followed by a score (enter NoName 0 to terminate)\n\n";
}

void run_program()
{
	vector<string> names;
	vector<int> scores;

	string name;
	int score{ 0 };

	prompt();

	while (cin >> name >> score)
	{
		if (name == "NoName" && score == 0) { break; }

		if (names.empty() && scores.empty())
		{
			names.push_back(name);
			scores.push_back(score);
			name = name.erase();
			score = 0;
		}
		else
		{
			auto it = std::find(names.begin(), names.end(), name);

			if (it != names.end())
			{
				cerr << "[error: duplicate found try again]\t[" << name << "]\n";
			}
			else
			{
				names.push_back(name);
				scores.push_back(score);
			}
		}
	}

	display_results(names, scores);
	search_for_name(names);
	search_for_score(scores);
}

void display_results(const vector<string>& names, const vector<int>& scores)
{
	cout
		<< "\nnames\tscores\n"
		<< "--------------\n";

	for (size_t i{ 0 }; i < names.size(); ++i)
	{
		cout << names.at(i) << '\t' << scores.at(i) << '\n';
	}
}

void search_for_name(const vector<string>& names)
{
	cout << "enter a name:\n";

	string name;
	cin >> name;

	auto it = std::find(names.begin(), names.end(), name);

	if (it != names.end())
	{
		cout << "[name found]: " << *it << '\n';
	}
	else
	{
		cerr << "[name not found]\n";
	}
}

void search_for_score(const vector<int>& scores)
{
	cout << "enter a score:\n";

	int score{ 0 };
	cin >> score;

	auto it = std::find(scores.begin(), scores.end(), score);

	if (it != scores.end())
	{
		cout << "[score found]: " << *it << '\n';
	}
	else
	{
		cerr << "[score not found]\n";
	}
}
