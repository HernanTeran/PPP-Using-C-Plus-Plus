#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>
#include <list>

using std::cout;
using std::string;
using std::cin;
using std::ifstream;
using std::cerr;
using std::vector;
using std::size_t;
using std::stringstream;
using std::list;

struct Item
{
	string name;
	int iid{ 0 };
	double value{ 0 };
};

void print(const vector<Item>& v);
void print(const list<Item>& l);
bool sort_by_name(const Item& item1, const Item& item2);
bool sort_by_id(const Item& item1, const Item& item2);
bool sort_by_value(const Item& item1, const Item& item2);

int main()
{
	vector<Item> vi;

	cout << "Please enter the input file name:\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) { cerr << "cannot open file name, " << iname << '\n'; }

	string name;
	int id{ 0 };
	double val{ 0 };

	while (ifs >> name >> id >> val) { vi.push_back(Item{ name, id, val }); }

	print(vi);

	std::sort(vi.begin(), vi.end(), sort_by_name);
	print(vi);

	std::sort(vi.begin(), vi.end(), sort_by_id);
	print(vi);

	std::sort(vi.begin(), vi.end(), sort_by_value);
	print(vi);

	vi.push_back(Item{ "horse shoe", 99, 12.34 });
	vi.push_back(Item{ "Canon S400", 9988, 499.95 });
	
	print(vi);

	for (size_t i{ 0 }; i < vi.size(); ++i)
	{
		if (vi.at(i).name == "pen" || vi.at(i).name == "coffee") { vi.erase(vi.begin() + i); }
	}

	for (size_t i{ 0 }; i < vi.size(); ++i)
	{
		if (vi.at(i).iid == 110 || vi.at(i).iid == 113) { vi.erase(vi.begin() + i); }
	}
	
	print(vi);

	ifs.close();

	// ------------------------------------------------------------------------------------

	list<Item> li;

	cout << "Please enter the input file name:\n";
	cin >> iname;
	ifs.open({ iname });
	if (!ifs) { cerr << "cannot open file name, " << iname << '\n'; }

	name = "";
	id = 0;
	val = 0;

	while (ifs >> name >> id >> val) { li.push_back(Item{ name, id, val }); }

	print(li);

	li.sort(sort_by_name);
	print(li);

	li.sort(sort_by_id);
	print(li);

	li.sort(sort_by_value);
	print(li);

	li.push_back(Item{ "horse shoe", 99, 12.34 });
	li.push_back(Item{ "Canon S400", 9988, 499.95 });

	print(li);

	li.remove_if([](Item& item) {return item.name == "pen" || item.name == "coffee"; });

	print(li);
  
  return 0;
}

void print(const list<Item>& l)
{
	for (const auto& i : l)
	{
		cout << "List Item: " << i.name << '\t' << i.iid << "\t$" << i.value << '\n';
	}
	cout << '\n';
}

bool sort_by_name(const Item& item1, const Item& item2) { return item1.name < item2.name; }

bool sort_by_id(const Item& item1, const Item& item2) { return item1.iid < item2.iid; }

bool sort_by_value(const Item& item1, const Item& item2) { return item1.value > item2.value; }

void print(const vector<Item>& v)
{
	for (const auto& i : v)
	{
		cout << "Vector Item: " << i.name << '\t' << i.iid << "\t$" << i.value << '\n';
	}
	cout << '\n';
}

void error(const string& s)
{
	throw std::runtime_error(s);
}
  
