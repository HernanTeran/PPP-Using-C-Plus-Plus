#include "Name_pairs.h"

int main()
{
	Name_pairs::Name_pair pairs;
	
	pairs.read_names("Please enter names ('stop' to terminate):\n");
	pairs.read_ages("Please enter ages according to name entered ('|' to terminate):\n");
	pairs.print();
	pairs.sort();
	pairs.print();

	return 0;
}
