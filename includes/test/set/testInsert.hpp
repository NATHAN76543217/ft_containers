#ifndef TESTINSERT_SET_HPP
#define TESTINSERT_SET_HPP

#include "test.hpp"

template<class Cnt, class Ite>
 int		testPrintState_set(const Cnt &cnt, Ite start, Ite end)	
{
	std::cout << std::endl << "- size  = " << cnt.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << cnt.empty() << std::endl;
	for (; start != end; start++)
		std::cout << "(" << *start << ") - ";
	std::cout << std::endl;
	return 0;
}

template<class Cnt>
int		testAccess_set(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Access" << std::endl;
	Cnt cnt2(cnt);
	cnt2.insert("S");
	cnt2.insert("W");
	cnt2.insert("A");
	cnt2.insert("P");
	cnt2.insert("E");
	cnt2.insert("D");

	testPrintState_set(cnt, cnt.begin(), cnt.end());	
	std::cout << "test unavailable for set" << std::endl;
	// int ret = cnt["S"];
	// std::cout << "cnt['S'] = " << ret << std::endl;
	// ret = cnt["W"];
	// std::cout << "cnt['W'] = " << ret << std::endl;
	// ret = cnt["A"];
	// std::cout << "cnt['A'] = " << ret << std::endl;
	// ret = cnt["K"];
	// std::cout << "cnt['K'] = " << ret << std::endl;
	testPrintState_set(cnt, cnt.begin(), cnt.end());	
	return 0;
}

template<class Cnt>
int		testSwap_set(Cnt &cnt)
{
	std::cout << "\ntest Swap" << std::endl;
	Cnt cnt2(cnt);
	cnt2.insert("S");
	cnt2.insert("W");
	cnt2.insert("A");
	cnt2.insert("P");
	cnt2.insert("E");
	cnt2.insert("D");
	std::cout << "Cnt 1 = ";
	testPrintState_set(cnt, cnt.begin(), cnt.end());	
	std::cout << "Cnt 2 = ";
	testPrintState_set(cnt2, cnt2.begin(), cnt2.end());
	ft::swap(cnt, cnt2);
	std::cout << "SWAP" << std::endl << "Cnt 1 = ";
	testPrintState_set(cnt, cnt.begin(), cnt.end());	
	std::cout << "Cnt 2 = ";
	testPrintState_set(cnt2, cnt2.begin(), cnt2.end());
	return 0;
}

template<class Cnt>
int		testInsert_set(Cnt &cnt)
{
	std::string p = "coucouKey";
	ft::pair<typename Cnt::iterator, bool>p2 = cnt.insert(p);
	if (p2.second == true)
	{
		std::cout << "a new key '" << *(p2.first) << "' was inserted" << std::endl; 
	}
	else
		std::cout << "the key '" << *(p2.first) << "' already exist and his value is equal to " << *(p2.first) << std::endl; 

	p2 = cnt.insert(p);
	if (p2.second == true)
	{
		std::cout << "a new key '" << *(p2.first) << "' was inserted" << std::endl; 
	}
	else
		std::cout << "the key '" << *(p2.first) << "' already exist and his value is equal to " << *(p2.first) << std::endl; 

	cnt.insert(p2.first, p);
	return 0;
}

template<class Cnt>
int		testInsertion_set(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Insertion" << std::endl;
	Cnt cnt2 = cnt;
	cnt.insert("hun");
	cnt.insert("deu");
	cnt.insert("troa");
	testInsert_set(cnt);
	std::cout << "Cnt 1 = ";
	testPrintState_set(cnt, cnt.begin(), cnt.end());
	std::cout << "Cnt 2 = ";
	testPrintState_set(cnt2, cnt2.begin(), cnt2.end());
	std::cout << "Insert all cnt 1 in cnt2 = ";
	cnt2.insert(cnt.begin(), cnt.end());
	testPrintState_set(cnt2, cnt2.begin(), cnt2.end());
	std::cout << "\ntest create map from range cnt2 -1" << std::endl;
	Cnt cnt3(cnt2.begin(), --cnt2.end());
	std::cout << "Cnt 3 = ";
	testPrintState_set(cnt3, cnt3.begin(), cnt3.end());
	testSwap_set(cnt);
	testAccess_set(cnt);	
	return 0;
}

#endif