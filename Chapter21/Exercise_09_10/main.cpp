// Hernan Teran
// V1 - 2/15/2021
// V2 - 2/19/2021

#include "practice.h"

void run_program()
{
	try
	{
		std::vector<Orders::Order> v_orders;

		while (v_orders.size() != 3)
		{
			Orders::Order order;
			std::cin >> order;
			std::cout << order;
			Order_files::Order_file order_file;
			std::cin >> order_file;
			order_file.write_file(order);
			std::cin >> order_file;
			order_file.read_file(order, v_orders);
		}

		std::sort(v_orders.cbegin(), v_orders.cend());
		Order_files::Order_file combined_file;
		std::cin >> combined_file;

		for (const auto& o : v_orders)
		{ 
			combined_file.write_file(o);
			std::cout << o; 
		}

		double total_sum{ 0 };

		for (const auto& o : v_orders)
		{
			for (const auto& p : o.get_purchases())
			{
				total_sum += (p.get_unit_price() * p.get_count());
			}
		}

		std::cout << "Sum of all purchases: $" << total_sum << "\n\n";

		// -----------------------------------------------------------------------------

		std::list<Orders::Order> l_orders;
	}
	catch (Orders::Order::Invalid_order)
	{
		std::cerr << "Invalid order\n";
	}
	catch (Purchases::Purchase::Invalid_purchase)
	{
		std::cerr << "Invalid purchase\n";
	}
	catch (Order_files::Order_file::Invalid_file)
	{
		std::cerr << "Invalid order file\n";
	}
	catch (...)
	{
		std::cerr << "Error\n";
	}
}

int main()
{
	run_program();
	return 0;
}
