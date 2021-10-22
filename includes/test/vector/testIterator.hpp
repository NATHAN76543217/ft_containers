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
void	constructRIterator(ft::vector<T> &v)
{
	typename ft::vector<T>::reverse_iterator it = v.rbegin();
	typename ft::vector<T>::reverse_iterator end = v.rend();
	typename ft::vector<T>::reverse_iterator other;
	other = end;

	for (; it != other; ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
}

template<typename T>
void	constructCRIterator(const ft::vector<T> &v)
{
	typename ft::vector<T>::const_reverse_iterator it = v.rbegin();
	typename ft::vector<T>::const_reverse_iterator end = v.rend();
	typename ft::vector<T>::const_reverse_iterator other;
	other = end;

	for (; it != other; ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
}

template<typename T>
void	constructCIterator(const ft::vector<T> &v)
{
	typename ft::vector<T>::const_iterator it = v.begin();
	typename ft::vector<T>::const_iterator end = v.end();
	typename ft::vector<T>::const_iterator other;
	other = end;

	for (; it != other; ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
}

template<typename T>
void	constructIterator(ft::vector<T> &v)
{
	typename ft::vector<T>::iterator it = v.begin();
	typename ft::vector<T>::iterator end = v.end();
	typename ft::vector<T>::iterator other;
	other = end;

	for (; it != other; ++it)
		std::cout << *it << " ";
	std::cout << "\n" << std::endl;
}

template<typename T>
int		testIterator(ft::vector<T>& v)
{
	std::cout << "Iterator" << std::endl;
	constructIterator(v);
	printIterator(v);
	std::cout << "\nconst Iterator" << std::endl;
	constructCIterator(v);
	printConstIterator(v);
	std::cout << "\nReverse Iterator" << std::endl;
	constructRIterator(v);
	rprintIterator(v);
	std::cout << "\nconst reverse Iterator" << std::endl;
	constructCRIterator(v);
	rprintConstIterator(v);
	return 0;
}

#endif