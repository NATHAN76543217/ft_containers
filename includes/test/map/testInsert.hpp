#ifndef TESTINSERT_HPP
#define TESTINSERT_HPP

#include "test.hpp"

template<class Cnt, class Ite>
 int		testPrintState(const Cnt &cnt, Ite start, Ite end)	
{
	std::cout << std::endl << "- size  = " << cnt.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << cnt.empty() << std::endl;
	for (; start != end; start++)
		std::cout << "(" << (*start).first << ", " << (*start).second << ") - ";
	std::cout << std::endl;
	return 0;
}

template<class Cnt>
int		testAccess(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Access" << std::endl;
	Cnt cnt2(cnt);
	cnt2.insert(ft::make_pair("S", 30));
	cnt2.insert(ft::make_pair("W", 31));
	cnt2.insert(ft::make_pair("A", 32));
	cnt2.insert(ft::make_pair("P", 32));
	cnt2.insert(ft::make_pair("E", 31));
	cnt2.insert(ft::make_pair("D", 30));

	testPrintState(cnt, cnt.begin(), cnt.end());	
	int ret = cnt["S"];
	std::cout << "cnt['S'] = " << ret << std::endl;
	ret = cnt["W"];
	std::cout << "cnt['W'] = " << ret << std::endl;
	ret = cnt["A"];
	std::cout << "cnt['A'] = " << ret << std::endl;
	ret = cnt["K"];
	std::cout << "cnt['K'] = " << ret << std::endl;
	testPrintState(cnt, cnt.begin(), cnt.end());	
	return 0;
}

template<class Cnt>
int		testSwap(Cnt &cnt)
{
	std::cout << "\ntest Swap" << std::endl;
	Cnt cnt2(cnt);
	cnt2.insert(ft::make_pair("S", 30));
	cnt2.insert(ft::make_pair("W", 31));
	cnt2.insert(ft::make_pair("A", 32));
	cnt2.insert(ft::make_pair("P", 32));
	cnt2.insert(ft::make_pair("E", 31));
	cnt2.insert(ft::make_pair("D", 30));
	std::cout << "Cnt 1 = ";
	testPrintState(cnt, cnt.begin(), cnt.end());	
	std::cout << "Cnt 2 = ";
	testPrintState(cnt2, cnt2.begin(), cnt2.end());
	ft::swap(cnt, cnt2);
	std::cout << "SWAP" << std::endl << "Cnt 1 = ";
	testPrintState(cnt, cnt.begin(), cnt.end());	
	std::cout << "Cnt 2 = ";
	testPrintState(cnt2, cnt2.begin(), cnt2.end());
	return 0;
}

template<class Cnt>
int		testInsert(Cnt &cnt)
{
	ft::pair<std::string, int> p = ft::make_pair("coucouKey", 50);
	ft::pair<typename Cnt::iterator, bool>p2 = cnt.insert(p);
	if (p2.second == true)
	{
		std::cout << "a new key '" << (*(p2.first)).first << "' was inserted" << std::endl; 
	}
	else
		std::cout << "the key '" << (*(p2.first)).first << "' already exist and his value is equal to " << (*(p2.first)).second << std::endl; 

	p2 = cnt.insert(p);
	if (p2.second == true)
	{
		std::cout << "a new key '" << (*(p2.first)).first << "' was inserted" << std::endl; 
	}
	else
		std::cout << "the key '" << (*(p2.first)).first << "' already exist and his value is equal to " << (*(p2.first)).second << std::endl; 

	cnt.insert(p2.first, p);
	return 0;
}

template<class Cnt>
int		testInsertion(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Insertion" << std::endl;
	Cnt cnt2 = cnt;
	cnt.insert(ft::make_pair("hun", 1));
	cnt.insert(ft::make_pair("deu", 2));
	cnt.insert(ft::make_pair("troa", 3));
	testInsert(cnt);
	std::cout << "Cnt 1 = ";
	testPrintState(cnt, cnt.begin(), cnt.end());
	std::cout << "Cnt 2 = ";
	testPrintState(cnt2, cnt2.begin(), cnt2.end());
	std::cout << "Insert all cnt 1 in cnt2 = ";
	cnt2.insert(cnt.begin(), cnt.end());
	testPrintState(cnt2, cnt2.begin(), cnt2.end());
	std::cout << "\ntest create map from range cnt2 -1" << std::endl;
	Cnt cnt3(cnt2.begin(), --cnt2.end());
	std::cout << "Cnt 3 = ";
	testPrintState(cnt3, cnt3.begin(), cnt3.end());
	testSwap(cnt);
	testAccess(cnt);	
	return 0;
}

#endif