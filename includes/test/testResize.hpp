#ifndef TESTRESIZING_HPP
#define TESTRESIZING_HPP

#include "test.hpp"



/*
** ------------------------------- VECTOR INT--------------------------------
*/

template<typename T>
int		test_resizing(std::vector<T>& v1, ft::vector<T>& v2)
{
	T	value = static_cast<T>(6.7f);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	
	value = static_cast<T>(7.9f);
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v1.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	return 0;
}

/*
** ------------------------------- VECTOR STRING --------------------------------
*/

template<typename T>
int		test_resizing(std::vector<std::string>& v1, ft::vector<std::string>& v2)
{
	std::string value = "six";

	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << " is empty: " << v1.empty() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	value = "sept";
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v1.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v1.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	v1.push_back(value);
	v2.push_back(value);
	std::cout	<< v1.size() << "/" << v1.capacity() << std::setw(10) 
				<< v2.size() << "/" << v2.capacity() << std::endl;
	return 0;
}

#endif