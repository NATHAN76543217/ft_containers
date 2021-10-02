#ifndef TEST_HPP
#define TEST_HPP

#include <iomanip>

#include <string>
#include <vector>

#include "vector.hpp"

#include "testAccess.hpp"
#include "testResize.hpp"
#include "testPrint.hpp"

template<typename T>
void	printElem(std::vector<T>& v1, ft::vector<T>& v2);

template<typename T>
int		test_resizing(std::vector<T>& v1, ft::vector<T>& v2);

template<typename T>
void	accessTest(std::vector<T>& vector_stl, ft::vector<T>& vector_me);

template<typename T>
void	accessTestConst(std::vector<T> const &  vector_stl, ft::vector<T> const &  vector_me);

#endif