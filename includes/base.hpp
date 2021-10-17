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
	bool equal (
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first1,
		InputIterator1 last1,
		typename ft::enable_if< is_iterator<InputIterator2>::value, InputIterator2 >::type first2,
		BinaryPredicate pred)
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
	bool lexicographical_compare (
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first1,
		InputIterator1 last1,
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first2,
		InputIterator2 last2)
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
	bool lexicographical_compare (
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first1,
		InputIterator1 last1,
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first2,
		InputIterator2 last2,
		Compare comp)
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
	template<class T1, class T2> struct pair
	{
		typedef T1			first_type;
		typedef T2			second_type;

		T1		first;
		T2		second;
		
		pair() : first(), second() { }
		pair(const T1& a, const T2& b) : first(a), second(b) { }
		template<class U1, class U2>
        pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }
    };

	  /// Two pairs of the same type are equal iff their members are equal.
	template<class T1, class T2>
		inline bool
		operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{ return x.first == y.first && x.second == y.second; }

	template<class T1, class T2>
		inline bool
		operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{ return x.first < y.first
			|| (!(y.first < x.first) && x.second < y.second); }

	template<class T1, class T2>
		inline bool
		operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{ return !(x == y); }

	template<class T1, class T2>
		inline bool
		operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{ return y < x; }

	template<class T1, class T2>
		inline bool
		operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{ return !(y < x); }

	template<class T1, class T2>
		inline bool
		operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{ return !(x < y); }

	template< class T1, class T2 >
		inline pair<T1,T2> make_pair( T1 t, T2 u )
		{ return pair<T1, T2>(t, u); };
}

#endif              //BASE_HPP