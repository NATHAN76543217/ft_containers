#ifndef TEST_HPP
#define TEST_HPP

#ifdef STL
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
	#include <set.hpp>
#endif


#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>

#include "vector/testAccess.hpp"
#include "vector/testResize.hpp"
#include "vector/testPrint.hpp"
#include "vector/testIterator.hpp"
#include "vector/testModifier.hpp"
#include "vector/vector_constructor.hpp"
#include "vector/overload_op.hpp"
#include "stack/testAccess.hpp"
#include "stack/testResize.hpp"
#include "stack/testPrint.hpp"
#include "stack/testIterator.hpp"
#include "stack/testModifier.hpp"
#include "stack/stack_constructor.hpp"
#include "stack/overload_op.hpp"
#include "map/testIteratorRBT.hpp"
#include "map/testInsert.hpp"
#include "map/testComparator.hpp"
#include "set/testIteratorRBT.hpp"
#include "set/testInsert.hpp"
#include "set/testComparator.hpp"

//TODO for iterator: test 20 000 elements
/*
** ------------------------------- SET --------------------------------
*/

template<typename Cnt>
int		testIteratorRBT_set(Cnt &cnt);

template<class Cnt, class Ite>
int		testPrintState_set(const Cnt &cnt, Ite &start, Ite &end);

template<class Cnt, class Ite>
int		testPrintState_set(const Cnt &cnt, Ite start, Ite end);

template<typename Cnt>
int		testInsertion_set(Cnt &cnt);

template<typename Cnt>
int		testComparator_set(Cnt &cnt);


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

/*
** ------------------------------- STACK --------------------------------
*/

template<typename T>
void	test_op_vector(ft::stack<T> &v, T &value);

template<typename T>
void	printElem(ft::stack<T>& v2);

template<typename T>
int		test_resizing(ft::stack<T>& v);

template<typename T>
void	accessTest(ft::stack<T>& stack_me);

template<typename T>
void	accessTestConst(ft::stack<T> const &  stack_me);

template<typename T>
int		testIterator(ft::stack<T>& v2);

template<typename T>
int		testModifier(ft::stack<T>& v, T &value);

template<typename T, typename U>
void    stack_constructor(T& v, U value);

#endif