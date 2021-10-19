#ifndef MAP_HPP
#define MAP_HPP

#include "map_dclr.hpp"
//TODO implement class redBlackTree
namespace ft {

	/*
	** ------------------------------- CONSTRUCT/DESTROY/COPY --------------------------------
	*/
		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::map(const map::key_compare & comp, const map::allocator_type& alloc) : _tree(alloc), _comp(comp) {
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
		map<Key, T, Compare, Allocator>::map(const map<Key, T, Compare, Allocator>& src) : _tree(src._tree), _comp(src._comp)
		{

		}

		template<class Key, class T, class Compare, class Allocator>
		map<Key, T, Compare, Allocator>::~map( void )
		{

		}
	/*
	** ------------------------------- ITERATORS --------------------------------
	*/
	
	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
		map<Key, T, Compare, Allocator>::begin(void)
	{
		return  map<Key, T, Compare, Allocator>::iterator(this->_data);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
		map<Key, T, Compare, Allocator>::begin(void) const
	{
		return  map<Key, T, Compare, Allocator>::const_iterator(this->_data); 
	}
	
	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator
		map<Key, T, Compare, Allocator>::end(void)
	{
		return map<Key, T, Compare, Allocator>::iterator(&this->_data[this->_size]);
	}
	
	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator
		map<Key, T, Compare, Allocator>::end(void) const
	{
		return map<Key, T, Compare, Allocator>::const_iterator(&this->_data[this->_size]);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator
		map<Key, T, Compare, Allocator>::rbegin(void)
	{
		return  map<Key, T, Compare, Allocator>::reverse_iterator(&this->_data[this->_size]);
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator
		map<Key, T, Compare, Allocator>::rbegin(void) const
	{
		return  map<Key, T, Compare, Allocator>::const_reverse_iterator(&this->_data[this->_size]); 
	}
	
	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator
		map<Key, T, Compare, Allocator>::rend(void)
	{
		return map<Key, T, Compare, Allocator>::reverse_iterator(this->_data);
	}
	
	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator
		map<Key, T, Compare, Allocator>::rend(void) const
	{
		return map<Key, T, Compare, Allocator>::const_reverse_iterator(this->_data);
	}

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/


	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
		map<Key, T, Compare, Allocator>::size(void) const
	{
		return this->_tree._size;
	}

	template<class Key, class T, class Compare, class Allocator>
	typename map<Key, T, Compare, Allocator>::size_type
		map<Key, T, Compare, Allocator>::max_size(void) const
	{
		return std::min<size_type>(
			allocator_type::max_size(),
			std::numeric_limits<difference_type>::max());
	}

	template<class Key, class T, class Compare, class Allocator>
	bool
		map<Key, T, Compare, Allocator>::empty(void) const
	{
		return !(this->_size);
	}


	template<class Key, class T, class Compare, class Allocator>
	void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
	{
		x.swap(y);
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