#ifndef MAP_DCLR_HPP
# define MAP_DCLR_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "base.hpp"
# include "reverse_iterator.hpp"

namespace ft {
//TODO add operator= on iterattor and add tests for this operator 
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map 
	{
		public:
				// types:
		typedef Key                                      key_type;
		typedef T                                        mapped_type;
		typedef pair<const key_type, mapped_type>        value_type;
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

				reference						operator*(void) const
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
			
		explicit map(const allocator_type& alloc = allocator_type());
		explicit map(size_t n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type());
	//TODO add range constructors
			map( const map & src );
			~map();


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
    	bool						empty( void )    const;
    	size_type					size( void )     const;
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

			allocator_type			get_allocator() const;
	/*
	** ------------------------------- NON-MEMBER --------------------------------
	*/
	/*
	** ------------------------------- OPERATORS --------------------------------
	*/
		map						&operator=( const map& other );
		// map<T>				&operator=( map const & rhs );
	/*
	** ------------------------------- PRIVATE --------------------------------
	*/
		private:
			T 				*_data;
			size_type		_capacity;
			allocator_type	_alloc;
			size_type		_size;
						
			void		_initData(size_type N, const value_type &value = value_type());
			void		_destroy_data();


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
	void
	ft::swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
	{
		x.swap(y);
	}

}

#endif /* ********************************************************** MAP_DCLR_HPP */

/*
** Notes
** - map capacity is doubled each time
** - map capacity start at 0 for default constructor
*/

template <class Key, class T, class Compare = less<Key>,
          class Allocator = allocator<pair<const Key, T>>>
class map
{
public:
    // types:
    typedef Key                                      key_type;
    typedef T                                        mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    typedef Compare                                  key_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;

        value_compare(key_compare c);
    public:
        bool operator()(const value_type& x, const value_type& y) const;
    };

    // construct/copy/destroy:
    map()
        noexcept(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value);
    explicit map(const key_compare& comp);
    map(const key_compare& comp, const allocator_type& a);
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare());
    template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp, const allocator_type& a);
    map(const map& m);
    map(map&& m)
        noexcept(
            is_nothrow_move_constructible<allocator_type>::value &&
            is_nothrow_move_constructible<key_compare>::value);
    explicit map(const allocator_type& a);
    map(const map& m, const allocator_type& a);
    map(map&& m, const allocator_type& a);
    map(initializer_list<value_type> il, const key_compare& comp = key_compare());
    map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
   ~map();

    map& operator=(const map& m);
    map& operator=(map&& m)
        noexcept(
            allocator_type::propagate_on_container_move_assignment::value &&
            is_nothrow_move_assignable<allocator_type>::value &&
            is_nothrow_move_assignable<key_compare>::value);
    map& operator=(initializer_list<value_type> il);








    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // map operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;

    size_type      count(const key_type& k) const;
          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;

          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;

    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
};

