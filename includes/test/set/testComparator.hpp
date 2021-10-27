#ifndef TESTCOMPARATOR_SET_HPP
#define TESTCOMPARATOR_SET_HPP

#include "test.hpp"

template<class Cnt>
int		testBoundsConst_set(const Cnt &cnt)
{
	std::cout << "\nTEST bouds const" << std::endl;
	typename Cnt::const_iterator it = cnt.lower_bound("A");
	std::cout << "lower_bound of `A` = (" << *it << ")" << std::endl;
	it = cnt.lower_bound("f");
	std::cout << "lower_bound of `f` = (" << *it << ")" << std::endl;
	it = cnt.upper_bound("E");
	std::cout << "upper_bound of `E` = (" << *it << ")" << std::endl;
	it = cnt.upper_bound("Z");
	std::cout << "upper_bound of `Z` = (" << *it << ")" << std::endl;
	ft::pair<typename Cnt::const_iterator, typename Cnt::const_iterator> range = cnt.equal_range("coucouKey");
	std::cout << "equal_range of `coucouKey` = ((" << *range.first << "), " << "(" << *range.second << "))" << std::endl;
	range = cnt.equal_range("salut");
	std::cout << "equal_range of `salut` = ((" << *range.first << ", " << "), " << "(" << *range.second << "))" << std::endl;

	return 0;
}


template<class Cnt>
int		testBounds_set(Cnt &cnt)
{
	std::cout << "\nTEST bouds" << std::endl;
	typename Cnt::iterator it = cnt.lower_bound("A");
	std::cout << "lower_bound of `A` = (" << *it << ")" << std::endl;
	it = cnt.lower_bound("f");
	std::cout << "lower_bound of `f` = (" << *it << ")" << std::endl;
	it = cnt.upper_bound("E");
	std::cout << "upper_bound of `E` = (" << *it << ")" << std::endl;
	it = cnt.upper_bound("Z");
	std::cout << "upper_bound of `Z` = (" << *it << ")" << std::endl;
	ft::pair<typename Cnt::iterator, typename Cnt::iterator> range = cnt.equal_range("coucouKey");
	std::cout << "equal_range of `coucouKey` = ((" << *range.first << "), " << "(" << *range.second << ", " << *range.second << "))" << std::endl;
	range = cnt.equal_range("salut");
	std::cout << "equal_range of `salut` = ((" << *range.first << "), " << "(" << *range.second << ", " << *range.second << "))" << std::endl;
	return 0;
}

template<class Cnt>
int		testKeyComparator_set(Cnt &cnt)
{

	std::cout << std::endl << "-- test key Comparator --" << std::endl;
	typename Cnt::key_compare comp = cnt.key_comp();
	typename Cnt::iterator end = cnt.begin();
	typename Cnt::iterator srt = end++;
	std::cout << "comp(" << *srt << ", " << *end << ") = " << comp(*srt, *end) << std::endl;
	std::cout << "comp(" << *end << ", " << *srt << ") = " << comp(*end, *srt) << std::endl;
	return 0;

}

template<class Cnt>
int		testValueComparator_set(Cnt &cnt)
{
	std::cout << std::endl << "-- test value Comparator --" << std::endl;
	typename Cnt::value_compare comp = cnt.value_comp();
	typename Cnt::iterator end = cnt.begin();
	typename Cnt::iterator srt = end++;
	std::cout << "comp(" << *srt << ", " << *end << ") = " << comp((*srt), (*end)) << std::endl;
	std::cout << "comp(" << *end << ", " << *srt << ") = " << comp((*end), (*srt)) << std::endl;
	return 0;
}

template<class Cnt>
int		testComparator_set(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Comparator" << std::endl;
	
	testKeyComparator_set(cnt);
	testValueComparator_set(cnt);
	testBounds_set(cnt);
	testBoundsConst_set(cnt);
	return 0;
}

#endif