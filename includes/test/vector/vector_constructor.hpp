#ifndef VECTOR_CONTRUCTOR_HPP
#define VECTOR_CONTRUCTOR_HPP

#include "test.hpp"

template<typename T>
void    vector_constructor(ft::vector<T>& v, T value)
{
    std::cout << "default vector" << std::endl;
    ft::vector<T> v1;
    std::cout << "default() vector" << std::endl;
    ft::vector<T> v2 = ft::vector<T>();
    std::cout << "val() vector" << std::endl;
    ft::vector<T> v31 = ft::vector<T>(0, value);
    ft::vector<T> v32 = ft::vector<T>(1, value);
    ft::vector<T> v33 = ft::vector<T>(10, value);
    std::cout << "copy() vector" << std::endl;
    ft::vector<T> v4 = ft::vector<T>(v);
    ft::vector<T> v5 = ft::vector<T>(v1);
    //TODO check range constructor and other constructors
    return ;
}

#endif 