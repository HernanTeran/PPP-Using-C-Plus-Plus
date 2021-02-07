#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::vector;

void print_array(ostream& os, int* a, const int sz);
void print_vector(ostream& os, vector<int> v);

int main()
{
	cout << "--------- part 1 ------------------------------------------------\n\n";

	constexpr int size_ten{ 10 };

	int* arr = new int[size_ten];
	for (int i{ 0 }; i < size_ten; ++i) arr[i] = i;
	print_array(cout, arr, size_ten);

	int* arr2 = new int[size_ten];
	constexpr int one_hundred{ 100 };
	for (int x{ 0 }; x < size_ten; ++x) arr2[x] = x + one_hundred;
	print_array(cout, arr2, size_ten);

	constexpr int size_eleven{ 11 };
	int* arr3 = new int[size_eleven] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	print_array(cout, arr3, size_eleven);

	constexpr int size_twenty{ 20 };
	int* arr4 = new int[size_twenty];
	for (int t{ 0 }; t < size_twenty; ++t) arr4[t] = t + one_hundred;
	print_array(cout, arr4, size_twenty);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << "\n---------  part 2 -----------------------------------------------\n\n";

	vector<int> vec(size_ten);
	for (int i{ 0 }; i < size_ten; ++i) vec.at(i) = i + one_hundred;
	print_vector(cout, vec);

	vector<int> vec2(size_eleven);
	for (int x{ 0 }; x < size_eleven; ++x) vec2.at(x) = x + one_hundred;
	print_vector(cout, vec2);

	vector<int> vec3(size_twenty);
	for (int t{ 0 }; t < size_twenty; ++t) vec3.at(t) = t + one_hundred;
	print_vector(cout, vec3);

	cout << "\n---------  part 3 -----------------------------------------------\n\n";

	int n{ 7 };
	int* p1 = &n;
	cout << "address of n: " << p1 << "\tvalue of n: " << *p1 << '\n';

	constexpr int size_seven{ 7 };
	int n_arr[size_seven]{ 1, 2, 4, 6, 8, 10, 12 };
	int* p2 = n_arr; // here the book said to assign the address of n_arr to p2
					 // but I got an error and it turns out that it was because
					 // an array is basically already a pointer so assigning the 
					 // address to a pointer created some confliction
					 // so I just assigned n_arr to p2 and proceeded with no errors
	cout << "address of n_arr: " << p2 << '\n';
	for (int i{ 0 }; i < size_seven; ++i) cout << "n_arr value: " << *(p2 + i) << '\n';

	int* p3 = p2; // p3 points to n_arr
	p1 = p2; // p1 points to n_arr
	p2 = p3; // p2

	for (int i{ 0 }; i < size_seven; ++i) cout << "p3 value: " << *(p3 + i) << '\n';
	for (int i{ 0 }; i < size_seven; ++i) cout << "p1 value: " << *(p1 + i) << '\n';
	for (int i{ 0 }; i < size_seven; ++i) cout << "p2 value: " << *(p2 + i) << '\n';

	int n_arr2[size_ten]{ 3, 6, 9, 12, 15, 18, 21, 44, 54, 32 };
	p1 = n_arr2;
	for (int i{ 0 }; i < size_ten; ++i) cout << "p1 value: " << *(p1 + i) << '\n';

	int n_arr3[size_ten]{ 4, 6, 7, 2, 1, 8, 99, 42, 11, 77 };
	p2 = n_arr3;
	for (int i{ 0 }; i < size_ten; ++i) cout << "p2 value: " << *(p2 + i) << '\n';

	for (int i{ 0 }; i < size_ten; ++i) p2[i] = p1[i];
	for (int i{ 0 }; i < size_ten; ++i) cout << "p2 copy value: " << *(p2 + i) << '\n';

	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;

	cout << "\n---------  part 4 -----------------------------------------------\n\n";

	vector<int> n_vec(size_ten);
	for (int i{ 0 }; i < size_ten; ++i) n_vec.at(i) = i + one_hundred;
	vector<int>* p_vec;
	p_vec = &n_vec;
	for (int i{ 0 }; i < size_ten; ++i) cout << "p_vec value: " << p_vec->at(i) << '\n';

	vector<int> n_vec2(size_ten);
	for (int i{ 0 }; i < size_ten; ++i) n_vec2.at(i) = i + one_hundred;
	vector<int>* p_vec2;
	p_vec2 = &n_vec2;
	for (int i{ 0 }; i < size_ten; ++i) cout << "p_vec2 value: " << p_vec2->at(i) << '\n';
	
	n_vec2 = n_vec;
	for (const auto& n : n_vec2) cout << "n_vec2 copy value: " << n << '\n';

	return 0;
}

void print_array(ostream& os, int* a, const int sz)
{
	for (int i{ 0 }; i < sz; ++i) os << a[i] << '\n';
}

void print_vector(ostream& os, vector<int> v)
{
	for (const auto& n : v) os << n << '\n';
}
