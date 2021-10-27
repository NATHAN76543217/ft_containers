#ifndef SET_HPP
#define SET_HPP

#include "set_dclr.hpp"
namespace ft {

	/*
	** ------------------------------- CONSTRUCT/DESTROY/COPY --------------------------------
	*/
		template<class Key, class Compare, class Allocator>
		set<Key, Compare, Allocator>::set(const set::key_compare & comp, const set::allocator_type& alloc) 
			: RBTree<Key, Compare, Allocator >(alloc) {
				this->_comp = comp;
		}

		template<class Key, class Compare, class Allocator>
		template <class InputIterator>
		set<Key, Compare, Allocator>::set(
				typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type first,
				InputIterator last,
				const key_compare& comp,
				const allocator_type& alloc)
			: RBTree<Key, Compare, Allocator >(alloc)
		{
			this->_comp = comp;
			this->insert(first, last);
		} 

		template<class Key, class Compare, class Allocator>
		set<Key, Compare, Allocator>::set(const set<Key, Compare, Allocator>& src)
			: RBTree<Key, Compare, Allocator >(src._alloc)
		{
			this->operator=(src);
		}

		template<class Key, class Compare, class Allocator>
		set<Key, Compare, Allocator>::~set( void )
		{

		}

		template<class Key, class Compare, class Allocator>
    	set<Key, Compare, Allocator>&				set<Key, Compare, Allocator>::operator=(const set<Key, Compare, Allocator>& rhs)
		{
			if (this == &rhs)
				return *this;
			this->clear();
			this->insert(rhs.begin(), rhs.end());
			return *this;
		}

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
		set<Key, Compare, Allocator>::max_size(void) const
	{
		return std::min<size_type>(
			allocator_type::max_size(),
			std::numeric_limits<difference_type>::max());
	}

	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/

	template<class Key, class Compare, class Allocator>
	ft::pair< typename set<Key, Compare, Allocator>::iterator, bool>
	set<Key, Compare, Allocator>::insert(const typename set<Key, Compare, Allocator>::key_type& v) {
		iterator it = this->find(v);
		if (it == this->end())
		{
			typename set<Key, Compare, Allocator>::nodePTR node = &this->RBTree<Key, Compare, Allocator >::insert(v);
			return ft::make_pair(iterator(node), true);
		}
		return ft::make_pair(it, false);
	}


	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::insert(typename set<Key, Compare, Allocator>::iterator position, const typename set<Key, Compare, Allocator>::key_type& v)
	{
		static_cast<void>(position);
		return this->insert(v).first;
	}
	
	template<class Key, class Compare, class Allocator>
	template <class InputIterator>
	void
	set<Key, Compare, Allocator>::insert(InputIterator first, typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type last)
	{
		for (; first != last; ++first)
		{
			this->insert(*first);
		}	
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::erase(const set<Key, Compare, Allocator>::key_type& key) {
		return this->RBTree<Key, Compare, Allocator >::erase(key);
	}

	// template<class Key, class Compare, class Allocator>
	// template<class InputIterator>
	// void
	// set<Key, Compare, Allocator>::erase(typename ft::enable_if< is_iterator< InputIterator >::value, InputIterator>::type position)
	// {
	// 	if (position != this->end())
	// 		this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >::erase(*position);
	// }

	template<class Key, class Compare, class Allocator>
	void
	set<Key, Compare, Allocator>::erase( typename set<Key, Compare, Allocator>::iterator position)
	{
		if (position != this->end())
			this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >::erase(*position);
	}
	
	template<class Key, class Compare, class Allocator>
	template<typename InputIterator>
	void
	set<Key, Compare, Allocator>::erase(
		typename ft::enable_if<is_iterator<InputIterator>::value, InputIterator>::type first, 
		InputIterator last)
	{
		while (first != last && first != this->end())
		{
			this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >::erase(*(first++));
		}
	}

//TODO see for moving map's and set's swap function to RBTree
	template<class Key, class Compare, class Allocator>
	void		set<Key, Compare, Allocator>::swap(set<Key, Compare, Allocator>& x)
	{
		typename set<Key, Compare, Allocator>::nodePTR rootTmp = x._root;
		x._root = this->_root;
		this->_root = rootTmp;
		typename set<Key, Compare, Allocator>::nodePTR nullTmp = x.TNULL;
		x.TNULL = this->TNULL;
		this->TNULL = nullTmp;
		typename set<Key, Compare, Allocator>::size_type sizeTmp = x._size;
		x._size = this->_size;
		this->_size = sizeTmp;
		this->_end.left = this->_root;
		x._end.left = x._root;
		x._root->parent = &x._end;
		this->_root->parent = &this->_end;
	}

	/*
	** ------------------------------- ALLOCATORS --------------------------------
	*/

	/*
	** ------------------------------- OBSERVERS --------------------------------
	*/
	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::key_compare
	set<Key, Compare, Allocator>::key_comp( void )      const
	{
		return Compare();
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::value_compare
	set<Key, Compare, Allocator>::value_comp( void )   const
	{
		return set<Key, Compare, Allocator>::value_compare(this->key_comp());
	}

	/*
	** ------------------------------- OPERATIONS --------------------------------
	*/

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::find(const typename set<Key, Compare, Allocator>::key_type& k)
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::find(k);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::find(const typename set<Key, Compare, Allocator>::key_type& k) const
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::find(k);
	}

	template<class Key, class Compare, class Allocator>
    typename set<Key, Compare, Allocator>::size_type
	set<Key, Compare, Allocator>::count(const typename set<Key, Compare, Allocator>::key_type& k) const
	{
		return !(this->find(k) == this->end());
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::lower_bound(const key_type& k)
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::lower_bound(k);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::lower_bound(const key_type& k) const
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::lower_bound(k);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::iterator
	set<Key, Compare, Allocator>::upper_bound(const key_type& k)
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::upper_bound(k);
	}

	template<class Key, class Compare, class Allocator>
	typename set<Key, Compare, Allocator>::const_iterator
	set<Key, Compare, Allocator>::upper_bound(const key_type& k) const
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::upper_bound(k);
	}

	template<class Key, class Compare, class Allocator>
	typename ft::pair<typename set<Key, Compare, Allocator>::iterator, typename set<Key, Compare, Allocator>::iterator>
	set<Key, Compare, Allocator>::equal_range(const key_type& k)
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::equal_range(k);
	}

	template<class Key, class Compare, class Allocator>
	typename ft::pair<typename set<Key, Compare, Allocator>::const_iterator, typename set<Key, Compare, Allocator>::const_iterator>
	set<Key, Compare, Allocator>::equal_range(const key_type& k) const
	{
		return this->RBTree<typename set<Key, Compare, Allocator>::key_type, Compare, Allocator >
			::equal_range(k);
	}


	/*
	** ------------------------------- NON-MEMBER --------------------------------
	*/


	template<class Key, class Compare, class Allocator>
	void swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y)
	{
		x.swap(y);
	}
};

#endif		//set_HPP;