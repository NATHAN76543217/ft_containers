#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "vector_dclr.hpp"

namespace ft {

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector() : _capacity(0), _alloc(allocator_type()), _size(0)
	{
		this->_data = this->_alloc.allocate(this->_capacity);
	}

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(vector<T, Allocator>::size_type n,
								const vector<T, Allocator>::allocator_type&	alloc)
	: _capacity(n), _alloc(alloc), _size(n)
	{
		this->_data = this->_alloc.allocate(n);
		std::fill(this->begin(), this->end(), 0);
	}

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector<T, Allocator>& src)
	: _capacity(src.capacity), _alloc(src._alloc), _size(src.size)
	{
		this->_data = this->_alloc.allocate(this->_capacity);
	}
	
	template<typename T, typename Allocator>
	vector<T, Allocator>::~vector()
	{
		this->_alloc.deallocate(this->_data, this->_capacity);
	}
	/*
	** ------------------------------- ITERATORS --------------------------------
	*/
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator				vector<T, Allocator>::begin(void)
	{
		return iterator(this->_data);
	}

	// template<typename T, typename Allocator>
	// typename vector<T, Allocator>::const_iterator		vector<T, Allocator>::begin(void) const
	// {
	//		return const_iterator(this->_data); 
	// }
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator				vector<T, Allocator>::end(void)
	{
		return vector<T, Allocator>::iterator(&this->_data[this->_size]);
	}
	
	// template<typename T, typename Allocator>
	// typename vector<T, Allocator>::const_iterator		vector<T, Allocator>::end(void) const
	// {
// 
	// }

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/

	template<typename T, typename Allocator>
	bool		vector<T, Allocator>::empty(void) const{
		return !(this->_size);
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::size(void) const
	{
		return this->_size;
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::max_size(void) const
	{
		return std::numeric_limits<difference_type>::max();
	}

	template<typename T, typename Allocator>
	void											vector<T, Allocator>::reserve(size_type n)
	{
		//REVIEW why deprecated max_size()
		if (n <= this->_capacity)
			return ;
		size_type oldCapacity = this->_capacity;
		if (this->_capacity == 0)
			this->_capacity++;
		while (this->_capacity < n)
			this->_capacity *= 2;
		T* tmp = this->_alloc.allocate(this->_capacity);
		std::memcpy(tmp, this->_data, this->size() * sizeof(T));
		this->_alloc.deallocate(this->_data, oldCapacity);
		this->_data = tmp;
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::capacity(void) const
	{
		return this->_capacity;
	}

	// template<typename T, typename Allocator>
	
	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/

	template<typename T, typename Allocator>
	void			vector<T, Allocator>::push_back(const value_type& val)
	{
		if (this->_size >= this->_capacity)
		{
			this->reserve(this->_size + 1);
		}
		this->_data[this->_size] = val;
		this->_size++;
	}

}

template<typename T, typename Allocator>
std::ostream &			operator<<( std::ostream & o, ft::vector<T, Allocator> const & i )
{
	o << "vector[" << i.size() << "/" << i.capacity() << "]";
}

#endif /* ********************************************************** VECTOR_HPP */