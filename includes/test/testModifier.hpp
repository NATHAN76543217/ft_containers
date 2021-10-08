#ifndef TESTMODIFIER
#define TESTMODIFIER

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
void    test_vector_erase(T &v)
{
    v.erase(v.begin() + 6);
    v.erase(v.begin() + 10, v.end() - 9);
}

template<typename T>
int		testModifier(std::vector<T>& v1, ft::vector<T>& v2)
{
	std::cout << "push_back" << std::endl;
	test_push_back(v1);
	test_push_back(v2);
	printElem<T>(v1, v2);

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
    test_vector_erase(v1);
    test_vector_erase(v2);
    printElem<T>(v1, v2);

	return 0;
}

#endif