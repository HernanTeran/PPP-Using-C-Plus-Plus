// Hernan Teran
// V1 - 2/15/2021
// V2 - 2/19/2021
// V3 - 2/20/2021

#include "practice.h"

void run_program()
{
	using Orders::Order;
	using Purchases::Purchase;
	using Order_files::Order_file;
	using All_orders::Order_data;
	using std::vector;
	using std::list;
	using std::sort;
	using std::cin;
	using std::cout;
	using std::cerr;

	// -----------------------------------------------------------------------------------------

	try
	{
		Order_data orders;
		
		orders.create_v_orders("Please enter the amount of orders you would like to add: ");
		orders.write_v_file();

		orders.create_l_orders("Please enter the amount of orders you would like to add: ");
		orders.write_l_file();

		orders.merge_files();

		orders.compute_v_sum();
		orders.compute_l_sum();
		orders.print_sum("{Sum of all purchases: $");
	}
	catch (Order::Invalid_order)
	{
		std::cerr << "Invalid order\n";
	}
	catch (Purchase::Invalid_purchase)
	{
		cerr << "Invalid purchase\n";
	}
	catch (Order_file::Invalid_file)
	{
		cerr << "Invalid order file\n";
	}
	catch (...)
	{
		cerr << "Error\n";
	}
}

int main()
{
	run_program();
	return 0;
}
