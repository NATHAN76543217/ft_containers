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

void	accessTestConst(std::vector<int> const vector_stl, ft::vector<int> const vector_me)
{
	std::cout << "-- size: --" << std::endl;
	std::cout << vector_stl.size() << std::setw(10) << vector_me.size() << std::endl;

	std::cout << "-- Front: --" << std::endl;
	std::cout << vector_stl.front() << std::setw(10) << vector_me.front() << std::endl;
	std::cout << "--operator[7]: " << std::endl;
	std::cout << vector_stl[7] << std::setw(10) << vector_me[7] << std::endl;
	std::cout << "--at(19): " << std::endl;
	std::cout << vector_stl.at(19) << std::setw(10) << vector_me.at(19) << std::endl;
	std::cout << "--at(30): " << std::endl;
	try {
		std::cout << vector_stl.at(30) << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "catch: " << e.what() << "\n";
	}
	try {
		std::cout << vector_me.at(30) << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "catch: " << e.what() << "\n";
	}
	std::cout << "-- Back: --" << std::endl;
	std::cout << vector_stl.back() << std::setw(10) << vector_me.back() << std::endl;
}

void	accessTest(std::vector<int> vector_stl, ft::vector<int> vector_me)
{
	std::cout << "-- size: --" << std::endl;
	std::cout << vector_stl.size() << std::setw(10) << vector_me.size() << std::endl;

	std::cout << "-- Front: --" << std::endl;
	std::cout << vector_stl.front() << std::setw(10) << vector_me.front() << std::endl;
	std::cout << "--operator[7]: " << std::endl;
	std::cout << vector_stl[7] << std::setw(10) << vector_me[7] << std::endl;
	std::cout << "--at(19): " << std::endl;
	std::cout << vector_stl.at(19) << std::setw(10) << vector_me.at(19) << std::endl;
	std::cout << "--at(30): " << std::endl;
	try {
		std::cout << vector_stl.at(30) << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "catch: " << e.what() << "\n";
	}
	try {
		std::cout << vector_me.at(30) << std::endl;
	}
	catch(std::out_of_range & e)
	{
		std::cout << "catch: " << e.what() << "\n";
	}
	std::cout << "-- Back: --" << std::endl;
	std::cout << vector_stl.back() << std::setw(10) << vector_me.back() << std::endl;
	vector_stl[25] = 99;
	vector_me[25] = 99;
	std::cout << "-- Back: --" << std::endl;
	std::cout << vector_stl.back() << std::setw(10) << vector_me.back() << std::endl;
}


int main()
{
	std::vector<int>	vector_stl_1;
	ft::vector<int>		vector_me_1;

	test_resizing<std::vector<int>, ft::vector<int> >(vector_stl_1, vector_me_1);
	std::cout << std::endl;
	printElem<std::vector<int>, ft::vector<int> >(vector_stl_1, vector_me_1);

	std::vector<int>	vector_stl_2(7, 3);
	ft::vector<int>		vector_me_2(7, 3);
	test_resizing<std::vector<int>, ft::vector<int> >(vector_stl_2, vector_me_2);
	printElem<std::vector<int>, ft::vector<int> >(vector_stl_2, vector_me_2);

	std::cout << "---- TEST access" << std::endl;
	accessTest(vector_stl_2, vector_me_2);
	std::cout << "---- TEST access CONST" << std::endl;
	accessTestConst(vector_stl_2, vector_me_2);
	return 0;
}
