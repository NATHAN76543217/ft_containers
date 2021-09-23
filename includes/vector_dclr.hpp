#ifndef VECTOR_DCLR_HPP
# define VECTOR_DCLR_HPP

# include <iostream>
# include <string>
// # include "iterator.hpp"

namespace ft {

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
					typedef T				value_type;
					typedef value_type&		reference;
					typedef value_type*		pointer;
					typedef ptrdiff_t		difference_type;

				protected:
					value_type 		*_value;
				public:
					iterator()
					{
						this->_value = NULL;
					}
					iterator(value_type* src)
					{
						this->_value = src;
					}
					iterator(const iterator& src)
					{
						this->_value = src._value;
					}
					~iterator()
					{}

					reference			operator*(void) const
					{
						return *(this->_value);
					}
					pointer				operator->(void) const;
					iterator			&operator+=(difference_type n);
					iterator			&operator-=(difference_type n);
					reference			operator[](difference_type n) const;
					bool				operator!=(const iterator &rhs) const {
						return (this->_value != rhs._value);
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
			};


			explicit vector();
			explicit vector(size_t n, const allocator_type& alloc = allocator_type());
			vector(size_t n, const value_type& value);
    		vector(size_t n, const value_type& value, const allocator_type& alloc = allocator_type());

			vector( vector const & src );
			~vector();

			vector &		operator=( vector const & rhs );

	/*
	** ------------------------------- ITERATORS --------------------------------
	*/
			iterator				begin(void);
			// const_iterator			begin(void) const;
			iterator				end(void);
			// const_iterator			end(void) const;

			// reverse_iterator		rbegin(void);
			// const_reverse_iterator	rbegin(void) const;
			// reverse_iterator		rend(void);
			// const_reverse_iterator	rend(void) const;	
	/*
	** ------------------------------- CAPACITY --------------------------------
	*/

			size_type				size(void) const;
			size_type				capacity(void) const;
			size_type				max_size(void) const;
			void					resize(size_type size, value_type val = value_type());
			bool					empty(void) const;
			void					reserve(size_type n);

			// typedef typename std::stack<T>::container_type::iterator iterator;


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
			void push_back(const value_type& val);

		private:
			T 				*_data;
			size_type		_capacity;
			allocator_type	_alloc;
			size_type		_size;

	};

	template<typename T, typename Allocator>
	std::ostream &			operator<<( std::ostream & o, vector<T, Allocator> const & i );
}

#endif /* ********************************************************** VECTOR_DCLR_HPP */

/*
** Notes
** - vector capacity is doubled each time
** - vector capacity start at 0 for default constructor
*/