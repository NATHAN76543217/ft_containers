#ifndef OVERLOAD_OP_HPP
#define OVERLOAD_OP_HPP

#include "test.hpp"

template <typename T>
void test_op_vector(ft::vector<T> &v, T &val)
{
    ft::vector<T> v2(6, val); 
    std::cout << std::boolalpha << "Test operator == " << std::endl;
    std::cout << (v == v2) << std::endl;
    std::cout << (v == v) << std::endl;
    std::cout << (v2 == v2) << std::endl;
    std::cout << "Test operator != " << std::endl;
    std::cout << (v2 != v2) << std::endl;
    std::cout << (v != v) << std::endl;
    std::cout << (v != v2) << std::endl;
    std::cout << "Test operator < " << std::endl;
    std::cout << (v2 != v2) << std::endl;
    std::cout << (v != v) << std::endl;
    std::cout << (v != v2) << std::endl;
    std::cout << "Test operator > " << std::endl;
    std::cout << (v2 != v2) << std::endl;
    std::cout << (v != v) << std::endl;
    std::cout << (v != v2) << std::endl;
    std::cout << "Test operator <= " << std::endl;
    std::cout << (v2 != v2) << std::endl;
    std::cout << (v != v) << std::endl;
    std::cout << (v != v2) << std::endl;
    std::cout << "Test operator >= " << std::endl;
    std::cout << (v2 != v2) << std::endl;
    std::cout << (v != v) << std::endl;
    std::cout << (v != v2) << std::endl;
}

#endif