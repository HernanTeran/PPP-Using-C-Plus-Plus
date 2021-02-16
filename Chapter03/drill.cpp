// Hernan Teran 2/16/2021
// Chapter 3 Drill
// The drill is to write a simple letter based on user input

#include <iostream>
#include <string>
#include <exception>

using std::string;
using std::cout;
using std::cin;
using std::cerr;

void error(const std::string& message);

int main()
{
	try
	{
		cout << "Enter the name of the person you want to write to:\n";
		string first_name;
		cin >> first_name;
		cout
			<< "Dear, " << first_name << '\n'
			<< "How are you? I am fine. I miss you.\n";

		cout << "Enter the name of another friend:\n";
		string friend_name;
		cin >> friend_name;

		cout << "Have you seen " << friend_name << " lately?\n";
		char friend_sex{ '0' };
		cout << "Enter 'm' for male or 'f' for female:\n";
		cin >> friend_sex;

		switch (friend_sex)
		{
		case 'm':
			cout << "If you see " << friend_name << " please ask him to call me.\n";
			break;
		case 'f':
			cout << "If you see " << friend_name << " please ask her to call me.\n";
			break;
		default:
			error("unknown character\n");
			break;
		}

		cout << "Enter the age of the recipient:\n";
		int age{ 0 };
		cin >> age;
		constexpr int min_age{ 0 }, max_age{ 110 };

		if (age <= min_age || age >= max_age) { error("you're kidding!\n"); }

		cout << "I hear you just had a birthday and you are " << age << " years old.\n";

		if (age > 0 && age < 12) { cout << "Next year you will be " << age + 1 << ".\n"; }
		if (age >= 12 && age < 17) { cout << "You are currently a teenager.\n"; }
		if (age == 17) { cout << "Next year you will be able to vote.\n"; }
		if (age >= 18 && age < 70) { cout << "I hope you are enjoying adulthood.\n"; }
		if (age >= 70) { cout << "I hope you are enjoying retirement.\n"; }

		cout << "Yours sincerely,\n\n" << "Hernan Teran\n";
	}
	catch (std::exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

void error(const std::string& message) { throw std::runtime_error(message); }
