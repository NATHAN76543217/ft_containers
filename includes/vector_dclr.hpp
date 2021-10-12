#ifndef VECTOR_DCLR_HPP
# define VECTOR_DCLR_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "base.hpp"
# include "reverse_iterator.hpp"

namespace ft {
//TODO add operator= on iterattor and add tests for this operator 
	template<class T, typename Allocator = std::allocator<T> >
	class vector 
	{
		public:

			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ptrdiff_t										difference_type;
			typedef	size_t											size_type;

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
			
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_t n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type());
	//TODO add range constructors
			vector( const vector & src );
			~vector();


	/*
	** ------------------------------- ITERATORS --------------------------------
	*/
			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;

			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;	
	/*
	** ------------------------------- CAPACITY --------------------------------
	*/

			size_type				size(void) const;
			size_type				max_size(void) const;
			void					resize(size_type n, value_type value = value_type());
			size_type				capacity(void) const;
			bool					empty(void) const;
			void					reserve(size_type n);


	/*
	** ------------------------------- ELEMENT ACCESS --------------------------------
	*/
			reference			operator[](size_type n);
			const_reference		operator[](size_type n) const;
			reference			at(size_type n);
			const_reference		at(size_type n) const;
			reference			front(void);
			const_reference		front(void) const;
			reference			back(void);
			const_reference		back(void) const;

	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/
			template <class InputIterator>
			void			assign (typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator >::type first, InputIterator last);
			void			assign (size_type n, const value_type& val);
			void			push_back(const value_type& val);
			void			pop_back(void);

		    void			insert(iterator position, size_type n, const value_type& val);
			iterator		insert(iterator position, const value_type& val);
			// template <class InputIterator>
		    // void insert (iterator position, InputIterator first, InputIterator last);
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			void			swap (vector& x);
			void			clear( void );

	
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
			// vector<T>				&operator=( vector const & rhs );
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
	
	template<typename T, typename Allocator>
	void					swap (vector<T,Allocator>& x, vector<T,Allocator>& y);
	
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	// template<typename T, typename Allocator>
	// std::ostream &			operator<<( std::ostream & o, vector<T, Allocator> const & i );
}

#endif /* ********************************************************** VECTOR_DCLR_HPP */

/*
** Notes
** - vector capacity is doubled each time
** - vector capacity start at 0 for default constructor
*/