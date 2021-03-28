// Author: Hernan Teran
// Date:   2021/03/28
// Chapter 21 Exercise 4

#include <iostream>
#include <vector>

// function object
struct Eq_five
{
	bool operator()(int xx) const { return xx == 5; }
};

template <class In, class Pred>
// requires Input_iterator<In>() && Predicate<Pred>()
typename iterator_traits<In>::difference_type
my_count_if(In first, In last, Pred pred);

int main()
{
	vector<int> v{ 1,5,4,3,6,5,4,2,7,5,77 };

	cout << "5 was found " << my_count_if(v.cbegin(), v.cend(), Eq_five()) << " times.\n";

	return 0;
}

// using for-loop
template <class In, class Pred>
// requires Input_iterator<In>() && Predicate<Pred>()
typename iterator_traits<In>::difference_type
my_count_if(In first, In last, Pred pred)
{
	typename iterator_traits<In>::difference_type ret = 0;
	for (first; first != last; ++first)
		if (pred(*first)) ++ret;
	return ret;
}

// using while-loop
template <class In, class Pred>
// requires Input_iterator<In>() && Predicate<Pred>()
typename iterator_traits<In>::difference_type
my_count_if(In first, In last, Pred pred)
{
	typename iterator_traits<In>::difference_type ret = 0;
	while (first != last)
	{
		if (pred(*first)) ++ret;
		++first;
	}
	return ret;
}
