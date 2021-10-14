#ifndef TESTRESIZING_HPP
#define TESTRESIZING_HPP

#include "test.hpp"

/*
** ------------------------------- VECTOR GLOBAL--------------------------------
*/

template<typename T>
static void	printState(ft::vector<T> &v)
{
	std::cout <<
	std::right << std::setw(3)
	<< v.size() << "/" << std::left << std::setw(3) 
	<< v.capacity() << " is empty: " << std::setw(6) 
	<< (v.empty() ? "true" : "false") << std::endl;
	
}

template<typename T>
static void	loopPushBack(ft::vector<T> &v, T value, int loop)
{
	while (loop-- > 0)
	{
		v.push_back(value);
		printState<T>(v);
	}
}

/*
** ------------------------------- VECTOR INT--------------------------------
*/

template<typename T>
int		test_resizing(ft::vector<T>& v)
{
	T	value = static_cast<T>(6.7f);

	std::cout.setf(std::ios::boolalpha);
	printState<T>(v);
	loopPushBack<T>(v, value, 1);
	loopPushBack<T>(v, value, 1);
	loopPushBack<T>(v, value, 1);
	loopPushBack<T>(v, value, 1);
	loopPushBack<T>(v, value, 1);
		value = static_cast<T>(7.9f);
	loopPushBack<T>(v, value, 1);
	loopPushBack<T>(v, value, 3);
	loopPushBack<T>(v, value, 2);
	loopPushBack<T>(v, value, 8);
	loopPushBack<T>(v, value, 1);
	return 0;}

/*
** ------------------------------- VECTOR STRING --------------------------------
*/



template<typename T>
int		test_resizing(ft::vector<std::string>& v)
{
	std::string value = "six";

	std::cout.setf(std::ios::boolalpha);
	printState<std::string>(v);
	loopPushBack< std::string>(v, value, 1);
	loopPushBack< std::string>(v, value, 1);
	loopPushBack< std::string>(v, value, 1);
	loopPushBack< std::string>(v, value, 1);
	loopPushBack< std::string>(v, value, 1);
	value = "sept";
	loopPushBack< std::string>(v, value, 1);
	loopPushBack< std::string>(v, value, 3);
	loopPushBack< std::string>(v, value, 2);
	loopPushBack< std::string>(v, value, 8);
	loopPushBack< std::string>(v, value, 1);
	return 0;
}

#endif