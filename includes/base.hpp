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

	template <class InputIterator1, class InputIterator2>
	bool equal (
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first1,
		InputIterator1 last1, 
		typename ft::enable_if< is_iterator<InputIterator2>::value, InputIterator2 >::type first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{		
		while (first1 != last1)
		{
			if (! pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);	
	}
}

#endif              //BASE_HPP