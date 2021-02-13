#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>

using std::cout;
using std::string;
using std::cin;
using std::ifstream;
using std::cerr;
using std::vector;

void read_file(const string& prompt, vector<double>& v);
void print(const vector<double>& v);
void print(const vector<int>& v);

int main()
{
	vector<double> vd;
	read_file("Please enter the input file name:\n", vd);
	print(vd);

	double vd_sum{ 0 };

	vector<int> vi;
	for (const auto& d : vd) { vi.push_back(d); vd_sum += d; }
	print(vi);

	int vi_sum{ 0 };
	for (const auto& i : vi) { vi_sum += i; }

	cout << "vd sum: " << vd_sum << '\n';
	cout << "vd - vi = " << vd_sum - vi_sum << "\n\n";
	
	std::reverse(vd.begin(), vd.end());
	print(vd);

	double vd_mean = vd_sum / vd.size();

	cout << "vd mean value: " << vd_mean << '\n';

	vector<double> vd2(vd.size());
	auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), [vd_mean](double d) {return d < vd_mean; });
	vd2.resize(std::distance(vd2.begin(), it));
	print(vd2);
	
	std::sort(vd.begin(), vd.end());
	print(vd);

	return 0;
}

void read_file(const string& prompt, vector<double>& v)
{
	cout << prompt;
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) { cerr << "cannot open file name, " << iname << '\n'; }

	for (double d{ 0 }; ifs >> d;) { v.push_back(d); }
}

void print(const vector<double>& v)
{
	for (const auto& d : v) { cout << "double value: " << d << '\n'; }
	cout << '\n';
}

void print(const vector<int>& v)
{
	for (const auto& d : v) { cout << "int value: " << d << '\n'; }
	cout << '\n';
}
