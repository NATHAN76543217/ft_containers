#ifndef MAP_HPP
#define MAP_HPP

#include "map_dclr.hpp"
//TODO implement class redBlackTree
namespace ft {

	/*
	** ------------------------------- CONSTRUCT/DESTROY/COPY --------------------------------
	*/
		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::map(const map::key_compare & comp, const map::allocator_type& alloc) 
			: RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >(alloc), _comp(comp) {
		}

		template<class Key, class T, class Compare, class Allocator>
		template <class InputIterator>
		map<Key, T, Compare, Allocator>::map(
				typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type first,
				InputIterator last,
				const key_compare& comp,
				const allocator_type& alloc)
			: RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >(alloc), _comp(comp)
		{
			this->insert(first, last);
		} 

		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::map(const map<Key, T, Compare, Allocator>& src)
			: RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >(src._alloc), _comp(src._comp)
		{
			this->operator=(src);
		}

		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::~map( void )
		{

		}

		template<class Key, class T, class Compare, class Allocator>
    	map<Key, T, Compare, Allocator>&				map<Key, T, Compare, Allocator>::operator=(const map<Key, T, Compare, Allocator>& rhs)
		{
			if (this == &rhs)
				return *this;
			this->clear();
			this->insert(rhs.begin(), rhs.end());
			return *this;
		}

	/*
	** ------------------------------- ITERATORS --------------------------------
	*/


	/*
	** ------------------------------- CAPACITY --------------------------------
	*/


	// template<class Key, class T, class Compare, class Allocator>
	// typename map<Key, T, Compare, Allocator>::size_type
	// 	map<Key, T, Compare, Allocator>::size(void) const
	// {
	// 	return this->_tree._size;
	// }

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
		map<Key, T, Compare, Allocator>::max_size(void) const
	{
		return std::min<size_type>(
			allocator_type::max_size(),
			std::numeric_limits<difference_type>::max());
	}

	// template<class Key, class T, class Compare, class Allocator>
	// bool
	// 	map<Key, T, Compare, Allocator>::empty(void) const
	// {
	// 	return !(this->_size);
	// }


	template<class Key, class T, class Compare, class Allocator>
	void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
	{
		x.swap(y);
	}

	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/

	template<class Key, class T, class Compare, class Allocator>
	ft::pair< typename map<Key, T, Compare, Allocator>::iterator, bool>
	map<Key, T, Compare, Allocator>::insert(const typename map<Key, T, Compare, Allocator>::value_type& v) {
		iterator it = this->find(v.first);
		if (it == this->end())
		{
			typename map<Key, T, Compare, Allocator>::nodePTR node = &this->RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >::insert(v);
			return ft::make_pair(iterator(node), true);
		}
		return ft::make_pair(it, false);
	}


	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::insert(typename map<Key, T, Compare, Allocator>::iterator position, const typename map<Key, T, Compare, Allocator>::value_type& v)
	{
		static_cast<void>(position);
		return this->insert(v).first;
	}
	
	template<class Key, class T, class Compare, class Allocator>
	template <class InputIterator>
	void
	map<Key, T, Compare, Allocator>::insert(InputIterator first, typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type last)
	{
		for (; first != last; ++first)
		{
			this->insert(*first);
		}	
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::erase(const map<Key, T, Compare, Allocator>::key_type& key) {
		this->RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >::erase(ft::make_pair(key, T()));
		//TODO handle return value
		return 1;
	}

	// template<class Key, class T, class Compare, class Allocator>
	// template<class InputIterator>
	// void
	// map<Key, T, Compare, Allocator>::erase(typename ft::enable_if< is_iterator< InputIterator >::value, InputIterator>::type position)
	// {
	// 	if (position != this->end())
	// 		this->RBTree<typename map<Key, T, Compare, Allocator>::value_type, &ft::pair<const Key, T>::KeyCompare, Allocator >::erase(*position);
	// }

	template<class Key, class T, class Compare, class Allocator>
	void
	map<Key, T, Compare, Allocator>::erase( typename map<Key, T, Compare, Allocator>::iterator position)
	{
		if (position != this->end())
			this->RBTree<typename map<Key, T, Compare, Allocator>::value_type, &ft::pair<const Key, T>::KeyCompare, Allocator >::erase(*position);
	}
	
	template<class Key, class T, class Compare, class Allocator>
	template<typename InputIterator>
	void
	map<Key, T, Compare, Allocator>::erase(
		typename ft::enable_if<is_iterator<InputIterator>::value, InputIterator>::type first, 
		InputIterator last)
	{
		while (first != last && first != this->end())
		{
			// InputIterator next = first;
			// ++next;
			this->RBTree<typename map<Key, T, Compare, Allocator>::value_type, &ft::pair<const Key, T>::KeyCompare, Allocator >::erase(*(first++));
			// first = next;
		}
	}

	/*
	** ------------------------------- ALLOCATORS --------------------------------
	*/

	/*
	** ------------------------------- OPERATIONS --------------------------------
	*/

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
	map<Key, T, Compare, Allocator>::find(const typename map<Key, T, Compare, Allocator>::key_type& k)
	{
		return this->RBTree<typename map<Key, T, Compare, Allocator>::value_type, &ft::pair<const Key, T>::KeyCompare, Allocator >::find(ft::make_pair(k, T()));
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
	map<Key, T, Compare, Allocator>::find(const typename map<Key, T, Compare, Allocator>::key_type& k) const
	{
		return this->RBTree<typename map<Key, T, Compare, Allocator>::value_type, &ft::pair<const Key, T>::KeyCompare, Allocator >::find(ft::make_pair(k, T()));
	}

	template<class Key, class T, class Compare, class Allocator>
    typename map<Key, T, Compare, Allocator>::size_type
	map<Key, T, Compare, Allocator>::count(const typename map<Key, T, Compare, Allocator>::key_type& k) const
	{
		return !(this->find(k) == this->end());
	}

};

#endif		//MAP_HPP;