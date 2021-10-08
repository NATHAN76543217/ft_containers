#ifndef BASE_HPP
# define BASE_HPP

#include <stddef.h>
#include "iterator.hpp"

namespace ft {
	
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <class Ite, class C = void>
	struct is_iterator {
		static const bool value = false;
	};

	template <class Ite>
	struct is_iterator<Ite>
	{
		typedef typename std::iterator_traits<Ite>::iterator_category it;
		static const bool value = true;
	};
}

#endif              //BASE_HPP