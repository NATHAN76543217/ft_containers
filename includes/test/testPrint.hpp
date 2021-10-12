#ifndef TESTPRINT
# define TESTPRINT

# include "test.hpp"

template<typename T>
void		printElem(ft::vector<T>& v2)
{
	for (typename ft::vector<T>::iterator it2 = v2.begin(); it2 != v2.end(); it2++)
	{
		std::cout << std::setw(3) << *it2 << " ";
	}
	std::cout << "\n";
	std::cout << std::endl;
}

#endif