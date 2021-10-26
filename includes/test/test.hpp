#ifndef TEST_HPP
#define TEST_HPP

#ifdef STL
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif


#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "vector/testAccess.hpp"
#include "vector/testResize.hpp"
#include "vector/testPrint.hpp"
#include "vector/testIterator.hpp"
#include "vector/testModifier.hpp"
#include "vector/vector_constructor.hpp"
#include "vector/overload_op.hpp"
#include "map/testIteratorRBT.hpp"
#include "map/testInsert.hpp"
#include "map/testComparator.hpp"


/*
** ------------------------------- MAP --------------------------------
*/

template<typename Cnt>
int		testIteratorRBT(Cnt &cnt);

template<class Cnt, class Ite>
int		testPrintState(const Cnt &cnt, Ite &start, Ite &end);

template<class Cnt, class Ite>
int		testPrintState(const Cnt &cnt, Ite start, Ite end);

template<typename Cnt>
int		testInsertion(Cnt &cnt);

template<typename Cnt>
int		testComparator(Cnt &cnt);

/*
** ------------------------------- VECTOR --------------------------------
*/

template<typename T>
void	test_op_vector(ft::vector<T> &v, T &value);

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
int		testModifier(ft::vector<T>& v, T &value);

#endif