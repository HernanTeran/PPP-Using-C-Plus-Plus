// Author: Hernan Teran
// Date:   2021/03/25

#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string& s);
bool is_palindrome(const char s[]);
bool is_palindrome(const char* s);

istream& read_word(istream& is, char* buffer, size_t max);

int main()
{
  // testing strings
	for (string s; cin >> s;)
	{
		if (!is_palindrome(s))
			cout << s << " is not a palindrome.\n";
		else
			cout << s << " is a palindrome.\n";
	}
  
  constexpr size_t MAX{ 128 };
  
  // testing arrays
	for (char s[MAX]; read_word(cin, s, MAX);)
	{
		if (!is_palindrome(s))
			cout << s << " is not a palindrome.\n";
		else
			cout << s << " is a palindrome.\n";
	}
  
  // testing pointers
	for (char s[MAX]; read_word(cin, s, MAX);)
	{
		if (!is_palindrome(s))
			cout << s << " is not a palindrome.\n";
		else
			cout << s << " is a palindrome.\n";
	}

	return 0;
}

bool is_palindrome(const string& s)
{
  size_t LAST{ s.size() - 1 };
  
	for (size_t i{ 0 }; i != s.size(); ++i)
	{
		if (s.at(i) != s.at(LAST)) return false;
		--LAST;
	}

	return true;
}

bool is_palindrome(const char s[])
{
	size_t LAST{ 0 };
	for (size_t i{ 0 }; s[i]; ++i) ++LAST; 

	for (size_t i{ 0 }; s[i]; ++i)
	{
		if (s[i] != s[LAST - 1]) return false;
		--LAST;
	}
	
	return true;
}

bool is_palindrome(const char* s)
{
	size_t LAST{ 0 };
	for (size_t i{ 0 }; *(s + i); ++i) ++LAST;

	for (size_t i{ 0 }; *(s + i); ++i)
	{
		if (*(s + i) != *(s + LAST - 1)) return false;
		--LAST;
	}

	return true;
}

istream& read_word(istream& is, char* buffer, size_t max)
{
	is.width(max);
	is >> buffer;
	return is;
}
