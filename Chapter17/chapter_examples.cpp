#include <iostream>

using std::cout;

class Container
{
public:
	Container(int s) : sz{ s }, elem{ new double[s] }
	{
		for (int i{ 0 }; i < s; ++i) elem[i] = 0; // initialize elements
	}

	int size() const { return sz; }
	double get(int n) const { return elem[n]; } // read
	void set(int n, double v) { elem[n] = v; } // write

	~Container() { delete[] elem; } // every class that owns a resource needs a destructor
private:
	int sz{ 0 };
	double* elem;
};

int main()
{
	int x{ 17 };
	int* ptr{ &x }; // pointer holds address to x

	*ptr = 27; // dereference operator used on left hand side
	*ptr = 54; // to change value of x otherwise error
	
	// delete only works on objects initialized with the new operator
	// otherwsie error

	// a pointer's size is 8 bytes

	ptr = nullptr;

	double* p = new double[4]; // allocate four doubles on the free store
							   // new operator returns a pointer to the first element
	int* pt = new int; // allocate one int

	*p = 7.7; // write to the first object pointed to by p
	p[2] = 9.32; // write to the third object pointed to by p
				// dereference operator is not used because subscript [] operator is used
	p[1] = 54.32;
	p[3] = 90.444;

	// both loops output the values stored in p
	for (int i{ 0 }; i < 4; ++i) cout << *(p + i) << '\n';
	for (int i{ 0 }; i < 4; ++i) cout << p[i] << '\n';

	// a pointer doesn't know how many elements it points to
	// the subscript operator allows access to out-of-range
	// locations in memory returning junk
	// pointers can also be reassigned which can cause a loss of data

	double* p1; // uninitialized pointer to a double
	double* p2 = new double; // allocate an uninitialized double
	double* p3 = new double[10]; // allocate 10 unintialized doubles
	p3[7] = 7.7;
	delete[] p3; // first delete a pointer before reassigning
	p3 = nullptr; // set = nullptr for safety
	p3 = p2; // p3 now points to the same address as p2
			 // p3 first had to get deleted because I kept getting an error
			 // when assigning a pointer to an array to a regular pointer or vice versa
			 // first delete the one that is not going to be exist anymore
			 // the code in the book is wrong according to this
			 // because Stroustrup just did p3 = p2 which really gives a scalar error
			 // afterwards I tried deleting the new memory since p3 = p2
	         // but I still kept getting a scalar error
			 // so it seems that p3 is deleted when p2 is deleted since p3=p2
	// double d = p3[7]; out-of-range access 

	// initialize pointers
	double* init_d_ptr = new double{ 5.5 }; // initialize a double to 5.5
	double* init_ad_ptr = new double[4]{ 0,1,2,3 }; // initialize an array of 4 doubles
	double* p0 = nullptr; // nullptr = 0 and can be used for initialization

	// if (p0 != nullptr) is the same as if (p0)

	// void* means pointer to some memory that the compiler doesn't
	// know the type of
	// void* cannot be converted to another type for example double*
	// void* can be copied
	// void* cannot be dereferenced or subscripted
	void* pv1 = new int; // int* converts to void*
	void* pv2 = new double[10]; // double* converts to void*
	int* vpv1 = static_cast<int*>(pv1); // no need to double delete pv1 and vpv1
										// explicit type conversion
	*vpv1 = 44;
	cout << *vpv1;

	int h = 10;
	int* ptr1 = &h;
	*ptr1 = 11;
	int x2 = *ptr1;
	int* ptr2 = &x2;
	ptr2 = ptr1;
	cout << *ptr2;

	/*
  * pointers and references
  * -----------------------
	* assignment to a pointer changes the pointer's value not the pointed-to value
	* to get a pointer you need to use either the new operator or reference & operator
	* to access an object pointed to by a pointer you use *, [], or ->
	* assignment to a reference changes the value of the object referred to not the reference itself
	* you cannot make a reference refer to a different object after initialization
	* assignment of references does deep copy, assignment of pointers does not
	*/

	delete[] p;
	delete pt;
	delete p2;
	delete init_d_ptr;
	delete[] init_ad_ptr;
	delete vpv1;
	delete[] pv2;

	return 0;
}
