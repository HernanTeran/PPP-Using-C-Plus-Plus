#include "practice.h"

void run_program()
{
	using namespace Currency;

	try
	{
		Money usd;
		std::cin >> usd;
		std::cout << usd;

		Money dkk;
		std::cin >> dkk;
		std::cout << dkk;
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
