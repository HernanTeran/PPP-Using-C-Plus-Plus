#include "practice.h"

void run_program()
{
	using namespace Currency;

	try
	{
		Money money;
		std::cin >> money;
		std::cout << money;
	}
	catch (Money::Invalid_amount)
	{
		std::cerr << "invalid amount\n";
	}
	catch (...)
	{
		std::cerr << "error\n";
	}
}

int main()
{
	run_program();
  
	return 0;
}
