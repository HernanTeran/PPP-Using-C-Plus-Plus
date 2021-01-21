#include <iostream>

double get_miles();
double convert_mi_to_km(double miles);
void run_program();

int main()
{
	run_program();

	return 0;
}

double get_miles()
{
	std::cout << "Enter miles to convert to kilometers:\n";

	double miles{ 0 };
	std::cin >> miles;

	return miles;
}

double convert_mi_to_km(double miles)
{
	constexpr double kilometers{ 1.609 };

	return miles * kilometers;
}

void run_program()
{
	double miles{ 0 };
	miles = get_miles();

	double mi_to_km{ 0 };
	mi_to_km = convert_mi_to_km(miles);

	std::cout
		<< "Miles: " << miles << '\n'
		<< "Kilometers " << mi_to_km << '\n';
}
