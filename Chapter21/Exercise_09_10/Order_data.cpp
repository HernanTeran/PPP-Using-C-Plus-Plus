#include "Order_data.h"

namespace All_orders
{
	void Order_data::create_v_orders(const std::string& prompt)
	{
		std::cout << prompt;
		std::cin >> orders_to_add;

		while (v_orders.size() != orders_to_add)
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
	}

	void Order_data::create_l_orders(const std::string& prompt)
	{
		std::cout << prompt;
		std::cin >> orders_to_add;

		while (l_orders.size() != orders_to_add)
		{
			Orders::Order order;
			std::cin >> order;
			std::cout << order;
			Order_files::Order_file order_file;
			std::cin >> order_file;
			order_file.write_file(order);
			std::cin >> order_file;
			order_file.read_file(order, l_orders);
		}
	}

	void Order_data::write_v_file()
	{
		std::sort(v_orders.begin(), v_orders.end(),
			[](const Orders::Order& left, const Orders::Order& right)
			{return left.get_customer_name() <= right.get_customer_name(); });

		std::cin >> combined_file;

		for (const auto& o : v_orders)
		{
			combined_file.write_file(o);
			std::cout << o;
		}
	}

	void Order_data::write_l_file()
	{
		l_orders.sort([](const Orders::Order& left, const Orders::Order& right)
			        {return left.get_home_address() <= right.get_home_address(); });

		std::cin >> combined_file;

		for (const auto& o : l_orders)
		{
			combined_file.write_file(o);
			std::cout << o;
		}
	}

	void Order_data::merge_files()
	{
		std::merge(v_orders.begin(), v_orders.end(), 
				   l_orders.begin(), l_orders.end(), 
				   std::back_inserter(combined_orders),
				   [](Orders::Order& o1, Orders::Order& o2)
			       {return o1.get_customer_name() < o2.get_customer_name(); });

		std::cin >> combined_file;

		for (const auto& o : combined_orders)
		{
			combined_file.write_file(o);
			std::cout << o;
		}
	}

	void Order_data::compute_v_sum()
	{
		for (const auto& o : v_orders)
		{
			for (const auto& p : o.get_purchases())
			{
				total_sum += (p.get_unit_price() * p.get_count());
			}
		}
	}

	void Order_data::compute_l_sum()
	{
		for (const auto& o : l_orders)
		{
			for (const auto& p : o.get_purchases())
			{
				total_sum += (p.get_unit_price() * p.get_count());
			}
		}
	}

	void Order_data::print_sum(const std::string& message)
	{
		std::cout << message << total_sum << "}\n\n";
	}
}