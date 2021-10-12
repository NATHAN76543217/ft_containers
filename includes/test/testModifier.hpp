#ifndef TESTMODIFIER
# define TESTMODIFIER

# include "test.hpp"

template<typename T>
void    test_push_back(T &v)
{
    (void) v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);
}

template<typename T>
void    test_vector_swap(ft::vector<T> &v, T &value)
{
	ft::vector<T> cp(4, value);
	
	std::cout << "A = "; 
    printElem<T>(v);
	std::cout << "B = "; 
    printElem<T>(cp);
	std::cout << "Test swapping member" << '\n';
	v.swap(cp);
	std::cout << "A = "; 
    printElem<T>(v);
	std::cout << "B = "; 
    printElem<T>(cp);
	std::cout << "Test swapping non member" << '\n';
	ft::vector<T>::swap(v, cp);
	std::cout << "A = "; 
    printElem<T>(v);
	std::cout << "B = "; 
    printElem<T>(cp);
}

template<typename T>
void    test_vector_erase(T &v)
{
    v.erase(v.begin() + 6);
    v.erase(v.begin() + 10, v.end() - 9);
}

template<typename T>
int		testModifier(ft::vector<T>& v, T &value)
{
	std::cout << "push_back" << std::endl;
	test_push_back(v);
    printElem<T>(v);

	// std::cout << "\npop_back" << std::endl;
	// printConstIterator(v1);
	// printConstIterator(v2);
	// std::cout << "\nassign" << std::endl;
	// rprintIterator(v1);
	// rprintIterator(v2);
	// std::cout << "\ninsert" << std::endl;
	// rprintConstIterator(v1);
	// rprintConstIterator(v2);
	std::cout << "\nerase" << std::endl;
    test_vector_erase(v);
    printElem<T>(v);
    test_vector_swap(v, value);

	return 0;
}

#endif