#ifndef TESTITERATOR
# define TESTITERATOR
# include "test.hpp"


template<typename T>
static void	printConstIterator(const T& v1)
{
	for ( typename T::const_iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
static void	printIterator(T& v1)
{
	for ( typename T::iterator it = v1.begin(); it != v1.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
static void	rprintConstIterator(const T& v1)
{
	for ( typename T::const_reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
static void	rprintIterator(T& v1)
{
	for ( typename T::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
int		testIterator(ft::vector<T>& v)
{
	std::cout << "Iterator" << std::endl;
	printIterator(v);
	std::cout << "\nconst Iterator" << std::endl;
	printConstIterator(v);
	std::cout << "\nReverse Iterator" << std::endl;
	rprintIterator(v);
	std::cout << "\nconst reverse Iterator" << std::endl;
	rprintConstIterator(v);
	return 0;
}

#endif