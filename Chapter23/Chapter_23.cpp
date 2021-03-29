// Author: Hernan Teran
// Date:   2021/03/28
// Chapter 23 Exercise 1

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <exception>
#include <fstream>

using namespace std;

using Line_iter = vector<string>::const_iterator;

class Message
{
public:
	Message(Line_iter p1, Line_iter p2) : first{ p1 }, last{ p2 } {}
	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }

private:
	Line_iter first, last;
};

using Mess_iter = vector<Message>::const_iterator;

struct Mail_file
{
	Mail_file(const string& n)
	{
		in.open(n);
		if (!in)
			throw runtime_error("no " + n + '\n');
		cout << n << " has successfully been opened.\n\n";

		for (string s; getline(in, s);)
			lines.push_back(s);

		auto first = lines.begin();
		for (auto p = lines.begin(); p != lines.end(); ++p)
		{
			if (*p == "----")
			{
				m.push_back(Message{ first, p });
				first = p + 1;
			}
		}
	}

	~Mail_file() { in.close(); }

	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }

	string fname;
	vector<string> lines; // contains the contents of the whole file
	vector<Message> m;    // prints out lines beginning with from: and 1 to:
	ifstream in;
};

int main()
{
	Mail_file mfile{ "my-mail-file.txt" };

	multimap<string, string> sender;

	regex pat{ R"(To: |From: \"?(([A-Z][a-z]+) ?([A-Z]\. )?([A-Z][a-z]+)?)[: \w+]?\"?)" };
	smatch matches;

	for (const auto& f : mfile.m)
	{
		if (regex_search(*f.begin(), matches, pat))
		{
			sender.insert(make_pair(matches[1], *f.begin()));
		}
	}

	for (auto g : sender) cout << "name: " << g.first << '\n' << g.second << "\n\n";

	return 0;
}
