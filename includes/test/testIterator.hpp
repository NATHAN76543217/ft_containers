#ifndef TESTITERATOR
#define TESTITERATOR


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
int		testIterator(std::vector<T>& v1, ft::vector<T>& v2)
{
	std::cout << "Iterator" << std::endl;
	printIterator(v1);
	printIterator(v2);
	std::cout << "const Iterator" << std::endl;
	printConstIterator(v1);
	printConstIterator(v2);
	std::cout << "Reverse Iterator" << std::endl;
	rprintIterator(v1);
	rprintIterator(v2);
	std::cout << "const reverse Iterator" << std::endl;
	rprintConstIterator(v1);
	rprintConstIterator(v2);
	return 0;
}

#endif