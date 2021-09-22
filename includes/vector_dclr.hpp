#ifndef VECTOR_DCLR_HPP
# define VECTOR_DCLR_HPP

# include <iostream>
# include <string>
# include "iterator.hpp"

namespace ft {

	template<class T, typename Allocator = std::allocator<T> >
	class vector : public iterator
	{
		public:

			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename iterator<T>							iterator;
			typedef ptrdiff_t										difference_type;
			typedef	size_t											size_type;

			explicit vector();

			explicit vector(size_t n, const allocator_type& alloc = allocator_type());
			vector(size_t n, const value_type& value);
    		vector(size_t n, const value_type& value, const allocator_type& alloc = allocator_type());

			vector( vector const & src );
			~vector();

			vector &		operator=( vector const & rhs );
			
			/*
			** ------------------------------- CAPACITY --------------------------------
			*/

			size_type	size(void) const;
			size_type	capacity(void) const;
			size_type	max_size(void) const;
			void		resize(size_type size, value_type val = value_type());
			bool		empty(void) const;
			void		reserve(size_type n);

			// typedef typename std::stack<T>::container_type::iterator iterator;

			iterator	begin( void )
			{
				return this->c.begin();
			}
			iterator	end( void )
			{
				return this->c.end();
			}

		private:
			T 				*_data;
			size_type		_capacity;
			allocator_type	_alloc;
			size_type		_size;

	};

}

template<typename T, typename Allocator>
std::ostream &			operator<<( std::ostream & o, vector<T, Allocator> const & i );

#endif /* ********************************************************** VECTOR_DCLR_HPP */

/*
** Notes
** - vector capacity is doubled each time
** - vector capacity start at 0 for default constructor
*/