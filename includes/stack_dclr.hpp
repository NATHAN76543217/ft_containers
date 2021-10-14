#ifndef STACK_DCLR_HPP
# define STACK_DCLR_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "base.hpp"
# include "reverse_iterator.hpp"
# include "vector.hpp"

namespace ft {
	
	template< class T, class Container = ft::vector<T> >
	class stack 
	{
		public:
			typedef Container									container_type;
			typedef typename Container::value_type				value_type;
			typedef typename Container::size_type				size_type;
			typedef typename Container::reference				reference;
			typedef typename Container::const_reference			const_reference;

			explicit stack(const Container & cont = Container());
			stack( const stack & src );
			~stack();

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/

			size_type				size(void) const;
			bool					empty(void) const;

	/*
	** ------------------------------- ELEMENT ACCESS --------------------------------
	*/

		reference					top(void);
		const_reference				top(void) const;
	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/
		void						pop( void );
		void						push( const value_type& value );

	/*
	** ------------------------------- OPERATORS --------------------------------
	*/
		stack						&operator=( stack const & rhs );
	/*
	** ------------------------------- PRIVATE --------------------------------
	*/
		protected:
			Container 	c;


	};
	
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	// template<typename T, typename Allocator>
	// std::ostream &			operator<<( std::ostream & o, stack<T, Allocator> const & i );
}

#endif /* ********************************************************** STACK_DCLR_HPP */

/*
** Notes
** - stack capacity is doubled each time
** - stack capacity start at 0 for default constructor
*/