#ifndef TEST_HPP
#define TEST_HPP

#if STL
	// #include <map>
	// #include <stack>
	#include <vector>
	namespace ft = std;
#else
	// #include <map.hpp>
	// #include <stack.hpp>
	#include <vector.hpp>
#endif


#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "testAccess.hpp"
#include "testResize.hpp"
#include "testPrint.hpp"
#include "testIterator.hpp"
#include "testModifier.hpp"
#include "vector/vector_constructor.hpp"

/*
** ------------------------------- VECTOR --------------------------------
*/

template<typename T>
void    vector_constructor(ft::vector<T>& v, T value);

template<typename T>
void	printElem(ft::vector<T>& v2);

template<typename T>
int		test_resizing(ft::vector<T>& v);

template<typename T>
void	accessTest(ft::vector<T>& vector_me);

template<typename T>
void	accessTestConst(ft::vector<T> const &  vector_me);

template<typename T>
int		testIterator(ft::vector<T>& v2);

template<typename T>
int		testModifier(ft::vector<T>& v2);

//TODO testTimimg
#endif