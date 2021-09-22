#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_dclr.hpp"

template<typename T>
iterator<T>::iterator()
{
    
}

template<typename T>
iterator<T>::iterator(const iterator& src)
{
    
}

template<typename T>
iterator<T>::~iterator()
{
    
}

template<typename T>
reference			iterator<T>::operator*(void) const
{

}

template<typename T>
pointer				iterator<T>::operator->(void) const
{

}

template<typename T>
iterator			&iterator<T>::operator+=(difference_type n)
{

}

template<typename T>
iterator			&iterator<T>::operator-=(difference_type n)
{

}

template<typename T>
reference			iterator<T>::operator[](difference_type n) const
{

}

#endif      //ITERATOR_HPP