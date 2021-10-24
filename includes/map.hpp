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

		// template<class Key, class T, class Compare, class Allocator>
		// template <class InputIterator>
		// map<Key, T, Compare, Allocator>::map(
		// 		InputIterator first,
		// 		InputIterator last,
		// 		const key_compare& comp,
		// 		const allocator_type& alloc) : _tree(alloc)
		// {
		// } 
		// TODO

		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::map(const map<Key, T, Compare, Allocator>& src)
			: RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >(src._alloc), _comp(src._comp)
		{

		}

		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::~map( void )
		{

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
	map<Key, T, Compare, Allocator>::insert(const map<Key, T, Compare, Allocator>::value_type& v) {
		this->RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator >::insert(v);
		//TODO handle return value
		return ft::pair<iterator, bool>(iterator(), true);
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
	template<class Key, class T, class Compare, class Allocator>
		typename map<Key, T, Compare, Allocator>::allocator_type		map<Key, T, Compare, Allocator>::get_allocator() const {
			return this->_tree.getAllocator();
		}
};

#endif		//MAP_HPP;