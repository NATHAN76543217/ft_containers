#ifndef TESTCOMPARATOR_HPP
#define TESTCOMPARATOR_HPP

#include "test.hpp"

template<class Cnt>
int		testBoundsConst(const Cnt &cnt)
{
	std::cout << "\nTEST bouds const" << std::endl;
	typename Cnt::const_iterator it = cnt.lower_bound("A");
	std::cout << "lower_bound of `A` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	it = cnt.lower_bound("f");
	std::cout << "lower_bound of `f` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	it = cnt.upper_bound("E");
	std::cout << "upper_bound of `E` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	it = cnt.upper_bound("Z");
	std::cout << "upper_bound of `Z` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	ft::pair<typename Cnt::const_iterator, typename Cnt::const_iterator> range = cnt.equal_range("coucouKey");
	std::cout << "equal_range of `coucouKey` = ((" << (*range.first).first << ", " << (*range.first).second << "), " << "(" << (*range.second).first << ", " << (*range.second).second << "))" << std::endl;
	range = cnt.equal_range("salut");
	std::cout << "equal_range of `salut` = ((" << (*range.first).first << ", " << (*range.first).second << "), " << "(" << (*range.second).first << ", " << (*range.second).second << "))" << std::endl;

	return 0;
}


template<class Cnt>
int		testBounds(Cnt &cnt)
{
	std::cout << "\nTEST bouds" << std::endl;
	typename Cnt::iterator it = cnt.lower_bound("A");
	std::cout << "lower_bound of `A` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	it = cnt.lower_bound("f");
	std::cout << "lower_bound of `f` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	it = cnt.upper_bound("E");
	std::cout << "upper_bound of `E` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	it = cnt.upper_bound("Z");
	std::cout << "upper_bound of `Z` = (" << (*it).first << ", " << (*it).second << ")" << std::endl;
	ft::pair<typename Cnt::iterator, typename Cnt::iterator> range = cnt.equal_range("coucouKey");
	std::cout << "equal_range of `coucouKey` = ((" << (*range.first).first << ", " << (*range.first).second << "), " << "(" << (*range.second).first << ", " << (*range.second).second << "))" << std::endl;
	range = cnt.equal_range("salut");
	std::cout << "equal_range of `salut` = ((" << (*range.first).first << ", " << (*range.first).second << "), " << "(" << (*range.second).first << ", " << (*range.second).second << "))" << std::endl;
	return 0;
}

template<class Cnt>
int		testKeyComparator(Cnt &cnt)
{

	std::cout << std::endl << "-- test key Comparator --" << std::endl;
	typename Cnt::key_compare comp = cnt.key_comp();
	typename Cnt::iterator end = cnt.begin();
	typename Cnt::iterator srt = end++;
	std::cout << "comp(" << (*srt).first << ", " << (*end).first << ") = " << comp((*srt).first, (*end).first) << std::endl;
	std::cout << "comp(" << (*end).first << ", " << (*srt).first << ") = " << comp((*end).first, (*srt).first) << std::endl;
	return 0;

}

template<class Cnt>
int		testValueComparator(Cnt &cnt)
{
	std::cout << std::endl << "-- test value Comparator --" << std::endl;
	typename Cnt::value_compare comp = cnt.value_comp();
	typename Cnt::iterator end = cnt.begin();
	typename Cnt::iterator srt = end++;
	std::cout << "comp(" << (*srt).first << ", " << (*end).first << ") = " << comp((*srt), (*end)) << std::endl;
	std::cout << "comp(" << (*end).first << ", " << (*srt).first << ") = " << comp((*end), (*srt)) << std::endl;
	return 0;
}

template<class Cnt>
int		testComparator(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Comparator" << std::endl;
	
	testKeyComparator(cnt);
	testValueComparator(cnt);
	testBounds(cnt);
	testBoundsConst(cnt);
	return 0;
}

#endif