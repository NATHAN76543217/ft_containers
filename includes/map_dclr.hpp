#ifndef MAP_DCLR_HPP
# define MAP_DCLR_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "base.hpp"
# include "RBTree.hpp"

namespace ft {
//TODO add operator= on iterattor and add tests for this operator 
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map : public  RBTree<ft::pair<const Key, T>, &ft::pair<const Key, T>::KeyCompare, Allocator>
	{
		public:
				// types:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef bool(*Checker)(value_type, value_type);
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			// friend class map;
			protected:
		        key_compare comp;
		
		        value_compare(key_compare c);
		    public:
		        bool operator()(const value_type& x, const value_type& y) const;
				//TODO verifier attentivement ce qu'il y a à faire ici
		};
			
		typedef	typename RBTree<value_type, &ft::pair<const Key, T>::KeyCompare, Allocator>::iterator					iterator;
		typedef	typename RBTree<value_type, &ft::pair<const Key, T>::KeyCompare, Allocator>::const_iterator				const_iterator;
		typedef	typename RBTree<value_type, &ft::pair<const Key, T>::KeyCompare, Allocator>::reverse_iterator			reverse_iterator;
		typedef	typename RBTree<value_type, &ft::pair<const Key, T>::KeyCompare, Allocator>::const_reverse_iterator		const_reverse_iterator;

	/*
	** ------------------------------- CONSTUCT/COPY/DESTROY --------------------------------
	*/	
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
		map(const map& src);
		virtual ~map( void );

    	map						&operator=(const map& rhs);

	/*
	** ------------------------------- ITERATORS --------------------------------
	*/

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/
    	size_type					max_size( void ) const;

	/*
	** ------------------------------- ELEMENT ACCESS --------------------------------
	*/
		mapped_type&				operator[](const key_type& k);

	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/
		pair<iterator, bool>		insert(const value_type& v);
		iterator					insert(iterator position, const value_type& v);
		template <class InputIterator>
		void						insert(InputIterator first, InputIterator last);

		void						swap(map& x);

		// template< class InputIterator >
		// void						erase<ft::enable_if< is_iterator< InputIterator >::value, InputIterator>::type>( InputIterator position);

		//NOTE	All possibilities founded for enable_if here are minimum c++11
		void						erase(iterator position);
		size_type					erase(const key_type& k);
		template<class InputIterator>
		void						erase(typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type first, InputIterator last);


	/*
	** ------------------------------- ALLOCATORS --------------------------------
	*/

	/*
	** ------------------------------- OBSERVERS --------------------------------
	*/
	    key_compare					key_comp()      const;
	    value_compare				value_comp()    const;
	/*
	** ------------------------------- OPERATIONS --------------------------------
	*/
    	iterator							find(const key_type& k);
    	const_iterator						find(const key_type& k) const;
    	size_type							count(const key_type& k) const;
		iterator							lower_bound(const key_type& k);
		const_iterator						lower_bound(const key_type& k) const;
		iterator							upper_bound(const key_type& k);
		const_iterator						upper_bound(const key_type& k) const;

		pair<iterator,iterator>             equal_range(const key_type& k);	
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

	/*
	** ------------------------------- PRIVATE --------------------------------
	*/
		private:
			key_compare							_comp;
			// size_type		_capacity;
			// allocator_type	_alloc;
						
			// void		_initData(size_type N, const value_type &value = value_type());
			// void		_destroy_data();


	};
	template <class Key, class T, class Compare, class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator< (const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator> (const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);
	template <class Key, class T, class Compare, class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	// specialized algorithms:
	template <class Key, class T, class Compare, class Allocator>
	void swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y);

};

#endif /* ********************************************************** MAP_DCLR_HPP */

/*
** Notes
*/

