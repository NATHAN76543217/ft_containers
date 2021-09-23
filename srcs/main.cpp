#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include <stdlib.h>


template<typename T>
void		printElem(T& v1)
{
	for (typename T::iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << *it << "\n";
	}	
}

template<typename T>
int		test_resizing(T& v1)
{
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(6);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(6);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(6);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(6);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(7);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(7);
	v1.push_back(7);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	v1.push_back(7);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	v1.push_back(7);
	std::cout << v1.size() << "/" << v1.capacity() << std::endl;
	return 0;
}

int main()
{
	std::vector<int>	vector_stl(10);
	ft::vector<int>		vector_me(10);

	test_resizing<std::vector<int> >(vector_stl);
	std::cout << std::endl;
	test_resizing<ft::vector<int> >(vector_me);
	std::cout << std::endl;
	printElem<std::vector<int> >(vector_stl);
	std::cout << std::endl;
	printElem<ft::vector<int> >(vector_me);

	return 0;
}
