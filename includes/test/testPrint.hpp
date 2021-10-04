#ifndef TESTPRINT
# define TESTPRINT

template<typename T>
void		printElem(std::vector<T>& v1, ft::vector<T>& v2)
{
	;
	typename ft::vector<T>::iterator it2 = v2.begin();

	for (typename std::vector<T>::iterator it1 = v1.begin(); it1 != v1.end(); it1++)
	{
		std::cout << std::setw(3) << *it1 << " ";
	}
	std::cout << "\n";
	for (typename ft::vector<T>::iterator it2 = v2.begin(); it2 != v2.end(); it2++)
	{
		std::cout << std::setw(3) << *it2 << " ";
	}
	std::cout << "\n";
	std::cout << std::endl;
}

#endif