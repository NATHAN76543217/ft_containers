#include <iostream>
#include <string>
#include <vector>
// #include "vector.hpp"
#include <stdlib.h>

int main()
{
	std::vector<int>	vector_stl(107);
	// ft::vector<int>		vector_me;


	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(6);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(6);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(6);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(6);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(7);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	vector_stl.push_back(7);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;
	vector_stl.push_back(7);
	std::cout << vector_stl.size() << "/" << vector_stl.capacity() << std::endl;

	std::cout << (sizeof(int) / 2 ?: -1) << std::endl;
	std::cout << (-1 ?: -1) << std::endl;
	std::cout << (0 ?: -1) << std::endl;
	std::cout << (1 ?: -1) << std::endl;
	std::cout << (2 ?: -1) << std::endl;
	std::cout << (3 ?: -1) << std::endl;
	return 0;
}
