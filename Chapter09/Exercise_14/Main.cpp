#include "Main.h"

using namespace std;
using namespace Currency;

void driver()
{
	for (;;)
	{
		try
		{
			Money money;
			cin >> money;
			cout << money;
		}
		catch (Money::Invalid_Amount)
		{
			cerr << "Invalid amount. Try again.\nEnter 'c' to continue...\n";
			char a{ '0' };
			cin >> a;
			if (a != 'c') { break; }
			cout << endl;
		}
		catch (...)
		{
			cerr << "An unexpected error occurred.\n";
		}
	}
}

int main()
{
	driver();

	return 0;
}
