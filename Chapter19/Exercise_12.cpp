// Author: Hernan Teran
// Date:   2021/03/26
// Chapter 19 Exercise 12

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class File_handle
{
public:
	class Invalid_file {};

	File_handle(const std::string& fnm) : fn{ fnm }
	{
		fst.open(fnm, std::ios_base::app);
		if (!fst) throw Invalid_file{};
	}

	~File_handle() { fst.close(); }

public:
	void writef(const std::vector<std::string>& vs)
	{
		for (const std::string& s : vs)
			fst  << s;
	}

private:
	std::string fn;
	std::fstream fst;
};

int main()
{
	try
	{
		vector<string> wv1{ "Define a File_handle class with a constructor and destructor" };

		File_handle fh{ "f.txt" };
		fh.writef(wv1);

	}
	catch (File_handle::Invalid_file)
	{
		cerr << "Invalid file name.\n";
	}

	return 0;
}
