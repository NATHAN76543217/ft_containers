#ifndef MAP_HPP
#define MAP_HPP

#include <map_dclr.hpp>

namespace ft {

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
		return this->_size;
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
};

#endif		//MAP_HPP;