#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "vector_dclr.hpp"

namespace ft {

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const allocator_type& alloc) : _data(NULL), _capacity(0), _alloc(alloc), _size(0)
	{
		this->_initData(0);
	}

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(vector<T, Allocator>::size_type			n,
								const vector<T, Allocator>::value_type&		value,
								const vector<T, Allocator>::allocator_type&	alloc)
	: _data(NULL), _capacity(n), _alloc(alloc), _size(n)
	{
		this->_initData(n, value);
	}

	template<typename T, typename Allocator>
	vector<T, Allocator>::vector(const vector<T, Allocator>& src)
	: _data(NULL), _capacity(src._capacity), _alloc(src._alloc), _size(src.size())
	{
		this->_data = this->_alloc.allocate(this->_capacity);
		std::copy(src.begin(), src.end(), this->begin());
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
		return  vector<T, Allocator>::iterator(this->_data);
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator		vector<T, Allocator>::begin(void) const
	{
		return  vector<T, Allocator>::const_iterator(this->_data); 
	}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator				vector<T, Allocator>::end(void)
	{
		return vector<T, Allocator>::iterator(&this->_data[this->_size]);
	}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_iterator		vector<T, Allocator>::end(void) const
	{
		return vector<T, Allocator>::const_iterator(&this->_data[this->_size]);
	}

		template<typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator				vector<T, Allocator>::rbegin(void)
	{
		return  vector<T, Allocator>::reverse_iterator(&this->_data[this->_size]);
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator		vector<T, Allocator>::rbegin(void) const
	{
		return  vector<T, Allocator>::const_reverse_iterator(&this->_data[this->_size]); 
	}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reverse_iterator				vector<T, Allocator>::rend(void)
	{
		return vector<T, Allocator>::reverse_iterator(this->_data);
	}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reverse_iterator		vector<T, Allocator>::rend(void) const
	{
		return vector<T, Allocator>::const_reverse_iterator(this->_data);
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
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::max_size(void) const
	{
		return std::numeric_limits<difference_type>::max();
	}

	template<typename T, typename Allocator>
	void											vector<T, Allocator>::resize(size_type n, value_type value)
	{
		if (n <= this->_size)
		{
			//reduce
			while (this->_size > n)
				--this->_size;
			return ;
		}
		this->reserve(n);
		while (this->_size < n)
		{
			this->_data[this->_size] = value;
			this->_size++;
		}
		return ;

	}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::size_type		vector<T, Allocator>::capacity(void) const
	{
		return this->_capacity;
	}

	template<typename T, typename Allocator>
	bool		vector<T, Allocator>::empty(void) const{
		return !(this->_size);
	}

	template<typename T, typename Allocator>
	void											vector<T, Allocator>::reserve(size_type n)
	{
		if (n <= this->_capacity)
			return ;
		if (n > this->max_size())
			n = this->max_size();
		typename vector<T, Allocator>::size_type oldCapacity = this->_capacity;
		if (this->_capacity == 0)
			this->_capacity++;
		while (this->_capacity < n)
			this->_capacity *= 2;
		T	*tmp = this->_alloc.allocate(this->_capacity);
		std::memcpy(tmp, this->_data, this->size() * sizeof(T));
		this->_alloc.deallocate(this->_data, oldCapacity);
		this->_data = tmp;
	}

	// template<typename T, typename Allocator>
	/*
	** ------------------------------- ELEMENT ACCESS --------------------------------
	*/

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reference		vector<T, Allocator>::operator[](vector<T, Allocator>::size_type n)
	{
		return this->_data[n];
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference		vector<T, Allocator>::operator[](vector<T, Allocator>::size_type n) const
	{
		return this->_data[n];
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reference			vector<T, Allocator>::at(vector<T, Allocator>::size_type n)
	{
		if (n >= this->_size)
			throw std::out_of_range("vector") ;
		return this->_data[n];
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference		vector<T, Allocator>::at(vector<T, Allocator>::size_type n) const
	{
		if (n >= this->_size)
			throw std::out_of_range("vector") ;
		return this->_data[n];
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reference			vector<T, Allocator>::front(void)
	{
		return this->_data[0];
	}
	
	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference		vector<T, Allocator>::front(void) const
	{
		return this->_data[0];
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::reference			vector<T, Allocator>::back(void)
	{
		return this->_data[this->_size - 1];
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::const_reference		vector<T, Allocator>::back(void) const
	{
		return this->_data[this->_size - 1];
	}
	
	// reference			operator[](size_type n);
	// reference			at(size_type n);

	// reference			back(void);
	
	/*
	** ------------------------------- MODIFIERS --------------------------------
	*/
	template<typename T, typename Allocator>
	template <class InputIterator>
	void												vector<T, Allocator>::assign(
		typename ft::enable_if< is_iterator<InputIterator>::value, InputIterator >::type first, InputIterator last)
	{
		typename vector<T, Allocator>::size_type i = 0;
		typename vector<T, Allocator>::difference_type size = std::abs(first - last);
		this->resize(size);
		// std::cout << "first = " << *first << std::endl;
		// std::cout << "last = " << *last << std::endl;
		// std::cout << this->_size << std::endl;
		while (first != last )
		{
			this->_data[i] = *first;
			// std::cout << this->_data[i] << std::endl;
			++first;
			++i;
			// std::cout << "new i = " << i << std::endl;
		}
		
	}

	template<typename T, typename Allocator>
	void												vector<T, Allocator>::assign(size_type n, const value_type& val)
	{
		size_type i = 0;
		this->reserve(n);
		this->resize(n);
		while ( i < n)
		{
			this->_data[i] = value_type(val);
			i++;
		}
	}
			
	template<typename T, typename Allocator>
	void												vector<T, Allocator>::push_back(const value_type& val)
	{
		if (this->_size == this->_capacity)
		{
			this->reserve(this->_size + 1);
		}
		this->_data[this->_size] = val;
		this->_size++;
	}

	template<typename T, typename Allocator>
	void												vector<T, Allocator>::pop_back(void)
	{
		if (this->_size > 0)
			--(this->_size);
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator				vector<T, Allocator>::insert(iterator position, const value_type& val)
	{
		typename vector<T, Allocator>::iterator	first = position;
		value_type	tmp; 
		value_type	precedent;

		this->reserve(this->_size + 1);
		++this->_size;
		tmp = *position;
		precedent = tmp;
		*position = value_type(val);
		++position;
		while (position != this->end())
		{
			tmp = precedent;
			precedent = *position;
			*position = tmp;
			++position;
		}
		return first;
	}

	template<typename T, typename Allocator>
	void												vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
	{
		size_type	positionIdx;
		size_type	oldsize = this->size();

		if (n == 0)
			return ;
		this->reserve(this->_size + n);
		this->_size += n;
		positionIdx = position - this->begin();
		while (--oldsize >= positionIdx)
			this->_data[oldsize + n] = this->_data[oldsize];
		oldsize = positionIdx + n ;
		while (--oldsize >= positionIdx)
			this->_data[oldsize] = value_type(val);
		return ;
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator				vector<T, Allocator>::erase(iterator position) {
		typename vector<T, Allocator>::iterator ret_value = this->begin();
		iterator it = ret_value;
		for (; it != this->end() && it != position; ++it)
			;
		if (it == this->end())
			return ret_value;
		ret_value = it + 1;
		while (it != this->end() - 1)
		{
			*it = *(it + 1);
			++it;
		}
		--this->_size;
		return ret_value;
	}

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::iterator				vector<T, Allocator>::erase(iterator first, iterator last) {
		typename vector<T, Allocator>::iterator ret_value = this->begin();
		iterator itf = ret_value;
		iterator itl = ret_value;

		for (; itf != this->end() && itf != first; ++itf)
			;
		for (; itl != this->end() && itl != last; ++itl)
			;
		if (itf == this->end() || itl == this->end())
			return ret_value;
		while (itf != this->end() && itl != this->end())
		{
			*itf = *itl;
			++itf;
			++itl;
		}
		this->_size -= std::abs(last - first);
		return itf;
	}

	template<typename T, typename Allocator>
	void											vector<T, Allocator>::swap(vector<T, Allocator> &x)
	{
		T 			*dtmp = x._data;
		size_type	ctmp = x._capacity;
		size_type	stmp = x._size;

		x._data = this->_data; 
		x._capacity = this->_capacity; 
		x._size = this->_size; 
		this->_data = dtmp; 
		this->_capacity = ctmp; 
		this->_size = stmp; 
	}

	/*
	** ------------------------------- ALLOCATOR --------------------------------
	*/

	template<typename T, typename Allocator>
	typename vector<T, Allocator>::allocator_type		vector<T, Allocator>::get_allocator() const
	{
		return	this->_alloc;
	}

	/*
	** ------------------------------- NON-MEMBER --------------------------------
	*/
	template<typename T, typename Allocator>
	void												vector<T, Allocator>::swap(vector<T, Allocator>&x, vector<T, Allocator>&y)
	{
		x.swap(y);
	}
	
	/*
	** ------------------------------- OPERATORS --------------------------------
	*/

	// template<typename T, typename Allocator>
	// vector<T, Allocator>&		vector<T, Allocator>::operator=( vector<T, Allocator> const & rhs )
	// {
	// 	if (this != &rhs)
	// 	{
	// 		this->assign(rhs.begin(), rhs.end());
	// 	}
	// 	return *this;
	// }

	/*
	** ------------------------------- PRIVATE --------------------------------
	*/

	template<typename T, typename Allocator>
	void		vector<T, Allocator>::_initData(size_type N, const value_type &value)
	{
		this->_data = this->_alloc.allocate(N);
		if (N != 0)
			std::fill(this->begin(), this->end(), value);
	}


}

// template<typename T, typename Allocator>
// std::ostream &			operator<<( std::ostream & o, ft::vector<T, Allocator> const & i )
// {
// 	o << "vector[" << i.size() << "/" << i.capacity() << "]";
// }

#endif /* ********************************************************** VECTOR_HPP */