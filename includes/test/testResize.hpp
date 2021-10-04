#ifndef TESTRESIZING_HPP
#define TESTRESIZING_HPP

#include "test.hpp"


/*
** ------------------------------- VECTOR GLOBAL--------------------------------
*/

template<typename T, typename U>
static void	printState(T &v1, U &v2)
{
	std::cout	<< std::right << std::setw(3) << v1.size() << "/" << std::left << std::setw(3) << v1.capacity() << " is empty: " << std::setw(6) << (v1.empty() ? "true" : "false")
				<< std::right << std::setw(3) << v2.size() << "/" << std::left << std::setw(3) << v2.capacity() << " is empty: " << v2.empty() << std::endl;
	
}

template<typename T, typename U, typename X>
static void	loopPushBack(T &v1, U &v2, X value, int loop)
{
	while (loop-- > 0)
	{
		v1.push_back(value);
		v2.push_back(value);
		printState<std::vector<X>, ft::vector<X> >(v1, v2);
	}
}

/*
** ------------------------------- VECTOR INT--------------------------------
*/

template<typename T>
int		test_resizing(std::vector<T>& v1, ft::vector<T>& v2)
{
	T	value = static_cast<T>(6.7f);

	std::cout.setf(std::ios::boolalpha);
	printState<std::vector<T>, ft::vector<T> >(v1, v2);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	
	value = static_cast<T>(7.9f);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 3);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 2);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 8);
	loopPushBack<std::vector<T>, ft::vector<T>, T>(v1, v2, value, 1);
	return 0;
}

/*
** ------------------------------- VECTOR STRING --------------------------------
*/



template<typename T>
int		test_resizing(std::vector<std::string>& v1, ft::vector<std::string>& v2)
{
	std::string value = "six";

	std::cout.setf(std::ios::boolalpha);
	printState<std::vector<std::string>, ft::vector<std::string> >(v1, v2);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	value = "sept";
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 3);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 2);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 8);
	loopPushBack<std::vector<std::string>, ft::vector<std::string>, std::string>(v1, v2, value, 1);
	return 0;
}

#endif