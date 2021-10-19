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
	class map : public  RBTree<ft::pair<const Key, T>, Allocator>
	{
		public:
				// types:
			typedef Key                                      key_type;
			typedef T                                        mapped_type;
			typedef ft::pair<const key_type, mapped_type>        value_type;
			typedef Compare                                  key_compare;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;

		// typedef implementation-defined                   iterator;
		// typedef implementation-defined                   const_iterator;
		// typedef std::reverse_iterator<iterator>          reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

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
			
		class iterator
		{
			public:
				typedef ptrdiff_t							difference_type;
				typedef T									value_type;
				typedef value_type*							pointer;
				typedef value_type&							reference;
				typedef std::random_access_iterator_tag		iterator_category;

			protected:
				value_type 		*_value;
				
			public:
				iterator()
				{
					this->_value = NULL;
				}
				iterator(value_type* value)
				{
					this->_value = value;
				}
				iterator(const iterator& src)
				{
					this->_value = src._value;
				}
				~iterator()
				{}

				reference							operator*(void) const
				{
					return *(this->_value);
				}

				pointer								operator->(void) const
				{
					return (this->value);
				}
				
				iterator::difference_type			operator+(const iterator & rhs)
				{
					return (this->_value + rhs._value);
				}
				
				iterator::difference_type			operator-(const iterator & rhs)
				{
					return (this->_value - rhs._value);
				}
				
				iterator							operator+(difference_type n)
				{
					return iterator(this->_value + n);
				}
				
				iterator							operator-(difference_type n)
				{
					return iterator(this->_value - n);
				}
				
				iterator							&operator+=(difference_type n)
				{
					this->_value += n;
					return *this;
				}

				iterator							&operator-=(difference_type n)
				{
					this->_value -= n;
					return *this;
				}

				bool								operator!=(const iterator &rhs) const {
					return (this->_value != rhs._value);
				}

				bool								operator==(const iterator &rhs) const {
					return (this->_value == rhs._value);
				}
				
				iterator			&operator++(void)
				{
					++this->_value;
					return *this;
				}

				iterator			operator++(int)
				{
					iterator cpy(*this);
					++this->_value;
					return cpy;
				}

				iterator			&operator--(void)
				{
					--this->_value;
					return *this;
				}

				iterator			operator--(int)
				{
					iterator cpy(*this);
					--this->_value;
					return cpy;
				}
				bool				operator<(const iterator& rhs)
				{
					return (this->_value < rhs._value);
				}
				
				bool				operator>(const iterator& rhs)
				{
					return (this->_value > rhs._value);
				}
				
				bool				operator<=(const iterator& rhs)
				{
					return (this->_value <= rhs._value);
				}
				
				bool				operator>=(const iterator& rhs)
				{
					return (this->_value >= rhs._value);
				}

		};

		class const_iterator
			{
				public:
					typedef const T			value_type;
					typedef value_type&		reference;
					typedef value_type*		pointer;
					typedef ptrdiff_t		difference_type;
					typedef std::random_access_iterator_tag		iterator_category;
					//TODO change random_tag with ft:

				protected:
					value_type 		*_value;
					
				public:
					const_iterator()
					{
						this->_value = NULL;
					}
					const_iterator(value_type* value)
					{
						this->_value = value;
					}
					const_iterator(const const_iterator& src)
					{
						this->_value = src._value;
					}
					~const_iterator()
					{}

					reference								operator*(void) const
					{
						return *(this->_value);
					}

					pointer									operator->(void) const
					{
						return (this->value);
					}
					
					const_iterator::difference_type			operator+(const const_iterator & rhs)
					{
						return (this->_value + rhs._value);
					}
					
					const_iterator::difference_type			operator-(const const_iterator & rhs)
					{
						return (this->_value - rhs._value);
					}
					
					const_iterator							operator+(difference_type n)
					{
						return const_iterator(this->_value + n);
					}
					
					const_iterator							operator-(difference_type n)
					{
						return const_iterator(this->_value - n);
					}
					
					const_iterator							&operator+=(difference_type n)
					{
						this->_value += n;
						return *this;
					}

					const_iterator							&operator-=(difference_type n)
					{
						this->_value -= n;
						return *this;
					}

					bool									operator!=(const const_iterator &rhs) const {
						return (this->_value != rhs._value);
					}
					
					bool									operator==(const const_iterator &rhs) const {
						return (this->_value == rhs._value);
					}
					const_iterator							&operator++(void)
					{
						++this->_value;
						return *this;
					}

					const_iterator							operator++(int)
					{
						const_iterator cpy(*this);
						++this->_value;
						return cpy;
					}

					const_iterator							&operator--(void)
					{
						--this->_value;
						return *this;
					}

					const_iterator							operator--(int)
					{
						const_iterator cpy(*this);
						--this->_value;
						return cpy;
					}

					bool									operator<(const const_iterator& rhs)
					{
						return (this->_value < rhs._value);
					}
					
					bool									operator>(const const_iterator& rhs)
					{
						return (this->_value > rhs._value);
					}
					
					bool									operator<=(const const_iterator& rhs)
					{
						return (this->_value <= rhs._value);
					}
					
					bool									operator>=(const const_iterator& rhs)
					{
						return (this->_value >= rhs._value);
					}

//TODO implement comparator in iterator and const iterator

			};

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

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
		iterator					begin( void );
		const_iterator				begin( void ) const;
		iterator					end( void );
		const_iterator				end( void )   const;
		reverse_iterator			rbegin( void );
		const_reverse_iterator		rbegin( void ) const;
		reverse_iterator			rend( void );
		const_reverse_iterator		rend( void )   const;

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/
    	// bool						empty( void )    const;
    	// size_type					size( void )     const;
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

		void						erase(iterator position);
		size_type					erase(const key_type& k);
		void						erase(iterator first, iterator last);
		void						clear();

	/*
	** ------------------------------- ALLOCATORS --------------------------------
	*/

		allocator_type				get_allocator() const;
	/*
	** ------------------------------- OBSERVERS --------------------------------
	*/
	    key_compare					key_comp()      const;
	    value_compare				value_comp()    const;
	/*
	** ------------------------------- OPERATIONS --------------------------------
	*/
    	iterator					find(const key_type& k);
    	const_iterator				find(const key_type& k) const;
    	size_type					count(const key_type& k) const;
		iterator					lower_bound(const key_type& k);
		const_iterator				lower_bound(const key_type& k) const;
		iterator					upper_bound(const key_type& k);
		const_iterator				upper_bound(const key_type& k) const;

		pair<iterator,iterator>             equal_range(const key_type& k);	
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const;

	/*
	** ------------------------------- PRIVATE --------------------------------
	*/
		private:
			key_compare									_comp;
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

