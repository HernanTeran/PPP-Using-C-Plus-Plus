// Author: Hernan Teran
// Created: 2021/03/24
// Chapter 17 Exercise 5

char* findx(const char* s, const char* x);

int main()
{
	char* s = "Find the first occurrence of the C-style string x in s.";
	char* x = "occurrence";
	char* f = findx(s, x);

	if (f)
		cout << "Found: " << f;
	else
		cerr << "Not found: " << x;

	return 0;
}

char* findx(const char* s, const char* x)
{
	if (!x) { return nullptr; }
	
	bool found{ false };
	size_t y{ 0 };

	for (size_t i{ 0 }; s[i]; ++i)
	{
		if (s[i] == x[y])
		{
			for (size_t p{ y + 1 }; x[p]; ++p)
			{
				if (s[i + p] != x[p])
				{
					found = false;
					break;
				}
				++y;
				found = true;
			}

			if (found)
			{
				switch (s[i + 1])
				{
				case '\0':
				case ' ':
				case '.':
				case ',':
				case ';':
				case ':':
				case '!':
				case '?':
					return const_cast<char*>(x);
				default:
					break;
				}
			}
		}
	}
	return nullptr;
}
