#ifndef ITERATOR_DCLR_HPP
# define ITERATOR_DCLR_HPP

#include <cstddef>

template<typename T>
class iterator
{
	public:
		typedef T				value_type;
		typedef value_type&		reference;
		typedef value_type*		pointer;
		typedef ptrdiff_t		difference_type;

		iterator();
		iterator(const iterator &src);
		~iterator();

		reference			operator*(void) const;
		pointer				operator->(void) const;
		iterator			&operator+=(difference_type n);
		iterator			&operator-=(difference_type n);
		reference			operator[](difference_type n) const;
};

#endif      //ITERATOR_DCLR_HPP