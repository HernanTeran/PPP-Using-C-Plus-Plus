#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cout;

void run_program();
void display_menu();
int get_input();

int main()
{
	run_program();

	return 0;
}

void display_menu()
{
	cout
		<< "add to your sum\n"
		<< "---------------\n"
		<< "1. penny\n"
		<< "2. nickel\n"
		<< "3. dime\n"
		<< "4. quarter\n"
		<< "5. half-dollar\n"
		<< "6. one-dollar\n"
		<< "7. exit\n\n";
}

int get_input()
{
	cout << "make your selection:\n";
	int selection{ 0 };
	std::cin >> selection;

	return selection;
}

void run_program()
{
	int pennies{ 0 },
		nickels{ 0 },
		dimes{ 0 },
		quarters{ 0 },
		half_dollars{ 0 },
		dollars{ 0 };

	constexpr double penny{ 0.01 },
		         nickel{ 0.05 },
		         dime{ 0.10 },
			 quarter{ 0.25 },
			 half_dollar{ 0.50 },
			 one_dollar{ 1 };

	int selection{ 0 };
	double sum{ 0 };

	while (selection != 7)
	{
		display_menu();
		
		selection = get_input();

		switch (selection)
		{
		case 1:
			++pennies;
			sum += penny;
			cout << "+1 penny\n\n";
			break;
		case 2:
			++nickels;
			sum += nickel;
			cout << "+1 nickel\n\n";
			break;
		case 3:
			++dimes;
			sum += dime;
			cout << "+1 dime\n\n";
			break;
		case 4:
			++quarters;
			sum += quarter;
			cout << "+1 quarter\n\n";
			break;
		case 5:
			++half_dollars;
			sum += half_dollar;
			cout << "+1 half-dollar\n\n";
			break;
		case 6:
			++dollars;
			sum += one_dollar;
			cout << "+1 dollar\n\n";
			break;
		case 7:
			cout << "[goodbye]\n\n";
			break;
		default:
			cout << "[invalid input try again]\n\n";
			break;
		}
	}

	string penny_type,
		   nickel_type,
		   dime_type,
		   quarter_type,
		   half_dollar_type,
		   dollar_type;

	penny_type = pennies > 1 || pennies == 0 ? " pennies.\n" : " penny.\n";
	nickel_type = nickels > 1 || nickels == 0 ? " nickels.\n" : " nickel.\n";
	dime_type = dimes > 1 || dimes == 0 ? " dimes.\n" : " dime.\n";
	quarter_type = quarters > 1 || quarters == 0 ? " quarters.\n" : " quarter.\n";
	half_dollar_type = half_dollars > 1 || half_dollars == 0 ? " half-dollars.\n" : " half-dollar.\n";
	dollar_type = dollars > 1 || dollars == 0 ? " one-dollars.\n" : " one-dollar.\n";

	const string statement{ "You have " };

	cout
		<< statement << pennies << penny_type
		<< statement << nickels << nickel_type
		<< statement << dimes << dime_type
		<< statement << quarters << quarter_type
		<< statement << half_dollars << half_dollar_type
		<< statement << dollars << dollar_type
		<< "[sum: $" << std::fixed << std::setprecision(2) << sum << "]\n";
}
