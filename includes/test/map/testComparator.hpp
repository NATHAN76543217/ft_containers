#ifndef TESTCOMPARATOR_HPP
#define TESTCOMPARATOR_HPP

#include "test.hpp"


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
	return 0;
}

#endif