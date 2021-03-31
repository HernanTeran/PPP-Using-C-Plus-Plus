// Author:  Hernan Teran
// Date:    2021/03/31
// Chapter 11 Exercise 16

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	cout << "Please enter the output file name:" << endl;
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) cerr << "can't open, " << oname << endl;

	vector<int> test{ 7, 5, 5, 7, 3, 117, 5 };
	for (const int x : test) ofs << x << ' ';

	ofs.close();

	cout << "Please enter the input file name:" << endl;
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) cerr << "can't open, " << iname << endl;

	vector<int> n;
	for (int i{ 0 }; ifs >> i;)
		n.push_back(i);

	sort(n.begin(), n.end());

	int count{ 1 };
	for (size_t i{ 0 }; i != n.size(); ++i)
	{
		if (i == 0 || n.at(i) != n.at(i - 1))
		{
			if (count > 1)
				cout << '\t' << count;
			cout << endl;
			count = 1;
			cout << n.at(i);
		}
		else
			++count;
	}
	return 0;
}
