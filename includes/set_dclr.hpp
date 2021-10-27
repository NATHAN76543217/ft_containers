#ifndef SET_DCLR_HPP
# define SET_DCLR_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "base.hpp"
# include "RBTree.hpp"

namespace ft {
	template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set : public  RBTree<Key, Compare, Allocator>
	{
		public:
				// types:
			typedef Key											key_type;
			typedef Key											value_type;
			typedef typename std::size_t						size_type;
			typedef typename std::ptrdiff_t						difference_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			
		typedef	typename RBTree<key_type, Compare, Allocator>::iterator					iterator;
		typedef	typename RBTree<key_type, Compare, Allocator>::const_iterator			const_iterator;
		typedef	typename RBTree<key_type, Compare, Allocator>::reverse_iterator			reverse_iterator;
		typedef	typename RBTree<key_type, Compare, Allocator>::const_reverse_iterator	const_reverse_iterator;

	/*
	** ------------------------------- CONSTUCT/COPY/DESTROY --------------------------------
	*/	
		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
			set(typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type first,
				InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
		set(const set& src);
		virtual ~set( void );

    	set						&operator=(const set& rhs);

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/
    	size_type					max_size( void ) const;

	/*
	** ------------------------------- ELEMENT ACCESS --------------------------------
	*/

	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/
		pair<iterator, bool>		insert(const key_type& v);
		iterator					insert(iterator position, const key_type& v);
		template <class InputIterator>
		void						insert(InputIterator first, typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator>::type last);

		void						swap(set& x);

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
	};

	template <class Key, class Compare, class Allocator>
	void	swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y);

	template <class Key, class Compare, class Allocator>
	bool	operator==(const set<Key, Compare, Allocator>& x,
			const set<Key, Compare, Allocator>& y);

	template <class Key, class Compare, class Allocator>
	bool	operator< (const set<Key, Compare, Allocator>& x,
			const set<Key, Compare, Allocator>& y);

	template <class Key, class Compare, class Allocator>
	bool	operator!=(const set<Key, Compare, Allocator>& x,
			const set<Key, Compare, Allocator>& y);

	template <class Key, class Compare, class Allocator>
	bool	operator> (const set<Key, Compare, Allocator>& x,
			const set<Key, Compare, Allocator>& y);

	template <class Key, class Compare, class Allocator>
	bool	operator>=(const set<Key, Compare, Allocator>& x,
			const set<Key, Compare, Allocator>& y);
	template <class Key, class Compare, class Allocator>
	bool	operator<=(const set<Key, Compare, Allocator>& x,
			const set<Key, Compare, Allocator>& y);

	// specialized algorithms:
	template <class Key, class Compare, class Allocator>
	void swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y);

};

#endif /* ********************************************************** set_DCLR_HPP */

/*
** Notes
*/

