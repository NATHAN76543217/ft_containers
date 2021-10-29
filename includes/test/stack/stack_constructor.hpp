#ifndef STACK_CONTRUCTOR_HPP
#define STACK_CONTRUCTOR_HPP

#include "test.hpp"

template<typename T, typename U>
void    stack_constructor(T& v, U value)
{
    std::cout << "default stack" << std::endl;
    ft::stack<U> s1;
    ft::stack<U, T> s2;
    ft::stack<U, T> s3(v);
    std::cout << "default() stack" << std::endl;
    ft::stack<T> v2 = ft::stack<T>();
    std::cout << "val() stack" << std::endl;
    ft::stack<U> v31 = ft::stack<U>();
    ft::stack<U> v34 = ft::stack<U>();
    ft::stack<U, T> v33 = ft::stack<U, T>(s3);
    ft::stack<U, T> v32 = ft::stack<U, T>(T(3, value));
    std::cout << "copy() stack" << std::endl;
    ft::stack<U, T> v4 = ft::stack<U, T>(s2);
    ft::stack<U> v5 = ft::stack<U>(s1);
    ft::stack<U, T> v6 = ft::stack<U, T>(v32);
    std::cout << "range() stack" << std::endl;
    // T vR = T(v1.begin() + 1, v1.end() -1);
    //TODO check range constructor and other constructors
	//TODO implement test for every stack functions 
    return ;
}

#endif 