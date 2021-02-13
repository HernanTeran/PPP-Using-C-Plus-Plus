#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::string;
using std::cin;
using std::map;

void print(const map<string, int>& m);
void print(const map<int, string>& m);
void add_pair(map<string, int>& m);

int main()
{
	map<string, int> msi;
	msi.insert(map<string, int>::value_type{ "lecture", 21 });
	msi.insert(map<string, int>::value_type{ "anatomy", 25 });
	msi.insert(map<string, int>::value_type{ "biology", 23 });
	msi.insert(map<string, int>::value_type{ "calculus", 26 });
	msi.insert(map<string, int>::value_type{ "chemistry", 29 });
	msi.insert(map<string, int>::value_type{ "psychology", 36 });
	msi.insert(map<string, int>::value_type{ "english", 11 });
	msi.insert(map<string, int>::value_type{ "spanish", 5 });
	msi.insert(map<string, int>::value_type{ "computer science", 14 });
	msi.insert(map<string, int>::value_type{ "mycology", 19 });

	print(msi);

	msi.clear();
	
	add_pair(msi);

	print(msi);

	int sum_of_values{ 0 };

	for (const auto& p : msi) { sum_of_values += p.second; }

	cout << "sum of values: " << sum_of_values << "\n\n";

	map<int, string> mis;

	for (const auto& p : msi)
	{
		mis.insert(map<int, string>::value_type{ p.second, p.first });
	}
	
	print(mis);

	return 0;
}

void print(const map<string, int>& m)
{
	for (const auto& p : m) { cout << p.first << ": " << p.second << '\n'; }
	cout << '\n';
}

void print(const map<int, string>& m)
{
	for (const auto& p : m) { cout << p.first << ": " << p.second << '\n'; }
	cout << '\n';
}

void add_pair(map<string, int>& m)
{
	string str;
	int n{ 0 };

	while (cin >> str >> n) { m.insert(map<string, int>::value_type{ str, n }); }
}
