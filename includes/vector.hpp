#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include "vector_dclr.hpp"

namespace ft {

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector() : _capacity(0), _alloc(allocator_type()), _size(0)
	{
		this->_data = this->_alloc.allocate(this->_capacity);
	}

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(
		vector<T, Allocator>::size_type				n,
		const vector<T, Allocator>::allocator_type&	alloc)
	: _alloc(alloc)
	{
		this->_alloc.allocate(n);
	}

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector<T, Allocator>& src)
	{
		;
	}
	
	template<typename T, typename Allocator>
	vector<T, Allocator>::~vector()
	{
		this->_alloc.deallocate(this->_data);
	}

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::size(void) const
	{
		return this->_size;
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::capacity(void) const
	{
		return this->_capacity;
	}

}

template<>
std::ostream &			operator<<( std::ostream & o, vector const & i );

#endif /* ********************************************************** VECTOR_HPP */