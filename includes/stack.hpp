#ifndef STACK_HPP
# define STACK_HPP

# include "stack_dclr.hpp"

namespace ft {

	template<typename T, typename Container>
	stack<T, Container>::stack(const Container & cont)
	{
		this->_c = cont;
	}
	
	template<typename T, typename Container>
	stack<T, Container>::stack( const stack<T, Container> & src )
	{
		this->_c = src._c;
	}
	
	template<typename T, typename Container>
	stack<T, Container>::~stack()
	{
		this->_destroy_data();
		this->_alloc.deallocate(this->_data, this->_capacity);
	}


	/*
	** ------------------------------- CAPACITY --------------------------------
	*/


	template<typename T, typename Container>
	typename stack<T, Container>::size_type		stack<T, Container>::size(void) const
	{
		return this->_c.size();
	}
	
	template<typename T, typename Container>
	bool		stack<T, Container>::empty(void) const{
		return this->_c.empty();
	}

	/*
	** ------------------------------- ELEMENT ACCESS --------------------------------
	*/

	template<typename T, typename Container>
	typename stack<T, Container>::reference			stack<T, Container>::top(void)
	{
		return this->_c.back();
	}

	template<typename T, typename Container>
	typename stack<T, Container>::const_reference		stack<T, Container>::top(void) const
	{
		return this->_c.back();
	}
	
	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/

			
	template<typename T, typename Container>
	void												stack<T, Container>::push(const value_type& val)
	{
		this->_c.push_back(val);
	}

	template<typename T, typename Container>
	void												stack<T, Container>::pop(void)
	{
		this->_c.pop_back();
	}

	/*
	** ------------------------------- OPERATORS --------------------------------
	*/

	template<typename T, typename Container>
	stack<T, Container>&		stack<T, Container>::operator=( stack<T, Container> const & rhs )
	{
		if (this != &rhs)
		{
			this->_c = rhs._c;
		}
		return *this;
	}
	
	/*
	** ------------------------------- NON-MEMBER --------------------------------
	*/

	template <class T, class Alloc>
	bool operator== (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return (ft::equal<
			typename stack<T, Alloc>::const_iterator,
			typename stack<T, Alloc>::const_iterator >(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator< (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<= (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator> (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}


}

// template<typename T, typename Container>
// std::ostream &			operator<<( std::ostream & o, ft::stack<T, Container> const & i )
// {
// 	o << "stack[" << i.size() << "/" << i.capacity() << "]";
// }

#endif /* ********************************************************** STACK_HPP */