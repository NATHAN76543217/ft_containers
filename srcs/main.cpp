#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "vector.hpp"
#include <stdlib.h>


template<typename T, typename C>
void		printElem(T& v1, C& v2)
{
	typename T::iterator it1 = v1.begin();
	typename C::iterator it2 = v2.begin();
	while (it1 != v1.end() && it2 != v2.end())
	{
		std::cout << *it1 << std::setw(10) << *it2 << "\n";
		it1++;
		it2++;
	}
}

template<typename LIB, typename CNT>
int		test_resizing(LIB& v1, CNT& v2)
{
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(6);
	v2.push_back(6);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(6);
	v2.push_back(6);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(6);
	v2.push_back(6);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(6);
	v2.push_back(6);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(7);
	v2.push_back(7);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(7);
	v1.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	v2.push_back(7);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(7);
	v2.push_back(7);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	return 0;
}

int main()
{
	std::vector<int>	vector_stl_1;
	ft::vector<int>		vector_me_1;

	test_resizing<std::vector<int>, ft::vector<int> >(vector_stl_1, vector_me_1);
	std::cout << std::endl;
	printElem<std::vector<int>, ft::vector<int> >(vector_stl_1, vector_me_1);
	std::vector<int>	vector_stl_2(7);
	ft::vector<int>		vector_me_2(7);
	test_resizing<std::vector<int>, ft::vector<int> >(vector_stl_1, vector_me_1);
	printElem<std::vector<int>, ft::vector<int> >(vector_stl_1, vector_me_1);

	return 0;
}
