#include <iostream>

using std::cout;

// ------------------------------------------------------------------------

class Rational
{
public:
	Rational() : numerator{0}, denominator{0} {}

	Rational(int num, int den) : numerator{num}, denominator{den} {}

	double to_double(int n, int d) 
	{ 
		double n_temp = n + 0.0;
		double d_temp = d + 0.0;
		return n_temp / d_temp; 
	}

	int get_denominator() const { return denominator; }
	int get_numerator() const { return numerator; }

	void reset(const int n, const int d)
	{
		numerator = n;
		denominator = d;
	}

	Rational operator - (Rational& right)
	{
		Rational temp;
		while (denominator != right.denominator)
		{
			int temp_d1 = denominator;
			int temp_d2 = right.denominator;

			numerator *= temp_d2;
			right.numerator *= temp_d1;

			denominator *= temp_d2;
			right.denominator *= temp_d1;
		}
		temp.numerator = numerator - right.numerator;
		temp.denominator = denominator;
		return temp;
	}

	Rational operator + (Rational& right)
	{
		Rational temp;

		while (denominator != right.denominator)
		{
			int temp_d1 = denominator;
			int temp_d2 = right.denominator;

			numerator *= temp_d2;
			right.numerator *= temp_d1;

			denominator *= temp_d2;
			right.denominator *= temp_d1;
		}
		temp.numerator = numerator + right.numerator;
		temp.denominator = denominator;
		
		return temp;
	}

	Rational operator * (const Rational& right)
	{
		Rational temp;
		temp.numerator = numerator * right.numerator;
		temp.denominator = denominator * right.denominator;
		return temp;
	}

	Rational operator / (Rational& right)
	{
		Rational temp;
		int temp_d1 = denominator;
		int temp_d2 = right.denominator;
		int temp_n2 = right.numerator;

		numerator *= temp_d2;
		denominator *= temp_n2;

		if (numerator % 2 == 0 && denominator % 2 == 0)
		{
			numerator /= 2;
			denominator /= 2;
		}

		temp.numerator = numerator;
		temp.denominator = denominator;
		return temp;
	}

	bool operator == (const Rational& arg) 
	{ 
		return numerator == arg.numerator && denominator == arg.denominator;
	}


private:
	int numerator{ 0 };
	int denominator{ 0 };
};

// ------------------------------------------------------------------------

int main()
{
	constexpr int n1{ 2 };
	constexpr int d1{ 5 };
	constexpr int n2{ 4 };
	constexpr int d2{ 3 };

	Rational r1{ n1, d1 };
	Rational r2{ n2, d2 };

	cout << n1 << " / " << d1 << " = " << r1.to_double(n1, d1) << '\n';
	cout << n2 << " / " << d2 << " = " <<  r2.to_double(n2, d2) << '\n';

	Rational mul = r1 * r2;
	cout << "[multiplication]: " << mul.get_numerator() << " / " << mul.get_denominator() << '\n';
	r1.reset(n1, d1);
	r2.reset(n2, d2);

	Rational div = r1 / r2;
	cout << "[division]: " << div.get_numerator() << " / " << div.get_denominator() << '\n';
	r1.reset(n1, d1);
	r2.reset(n2, d2);

	Rational add = r1 + r2;
	cout << "[addition]: " << add.get_numerator() << " / " << add.get_denominator() << '\n';
	r1.reset(n1, d1);
	r2.reset(n2, d2);

	Rational sub = r1 - r2;
	cout << "[subtraction]: " << sub.get_numerator() << " / " << sub.get_denominator() << "\n";
	r1.reset(n1, d1);
	r2.reset(n2, d2);

	return 0;
}
