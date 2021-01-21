#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";

	std::string first_name;
	getline(std::cin, first_name);

	std::cout
		<< "Dear " << first_name << ", \n"
		<< "How are you? I am fine.\n"
		<< "I miss you.\n\n";

	std::cout << "Enter the name of another friend (followed by 'enter'):\n";

	std::string friend_name;
	getline(std::cin, friend_name);

	std::cout << "Have you seen " << friend_name << " lately?\n";

	std::cout << "Enter m if the friend is male or an f if the friend is female:\n";

	char friend_sex{ 0 };
	std::cin.get(friend_sex);

	if (friend_sex == 'm')
	{
		std::cout << "If you see " << friend_name << " please ask him to call me.\n";
	}
	else if (friend_sex == 'f')
	{
		std::cout << "If you see " << friend_name << " please ask her to call me.\n";
	}
	else
	{
		std::cout << "Invalid input.\n";
	}

	std::cout << "Enter the age of the recipient:\n";

	int age{ 0 };
	std::cin >> age;

	while (age < 0 || age > 110)
	{
		std::cout << "You're kidding! Enter the real age!\n";
		std::cin >> age;
	}

	std::cout << "I hear you just had a birthday and you are " << age << " years old.\n";

	if (age < 12)
	{
		std::cout << "Next year you will be " << age + 1 << ".\n";
	}
	else if (age == 17)
	{
		std::cout << "Next year you will be able to vote.\n";
	}
	else if (age >= 70)
	{
		std::cout << "I hope you are enjoying retirement.\n";
	}
	else
	{
		std::cout << "I can't believe how much time has passed.\n";
	}

	std::cout << "Yours sincerly,\n\n" << "Hernan Teran\n";

	return 0;
}
