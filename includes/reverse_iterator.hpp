#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {

template <class Iterator>
class reverse_iterator
{
	protected:
		typedef Iterator			super;
		super						_base;

	public:
		typedef Iterator							iterator_type;	
		typedef typename super::iterator_category	iterator_category;
		typedef typename super::value_type			value_type;
		typedef typename super::difference_type		difference_type;
		typedef typename super::pointer				pointer;
		typedef typename super::reference			reference;

		reverse_iterator(void);
		explicit reverse_iterator(Iterator x);
		reverse_iterator(const reverse_iterator<Iterator> & src);

	//increment
		reverse_iterator	&operator++(void) {
			this->_base.operator--();
			return *this;
		};
		
		reverse_iterator	operator++(int) {
			return reverse_iterator(this->_base.operator--(0));
		};

		reverse_iterator	&operator--(void) {
			this->_base.operator++();
			return *this;
		};
		
		reverse_iterator	operator--(int) {
			return reverse_iterator(this->_base.operator++(0));
		};

	// pointer
		reference  operator*(void) const {
			return (super(this->_base)).operator*();
		}

		pointer		operator->(void) const {
			return &(this->operator*());
		}

	//operators
		template <class U>
		difference_type		operator-(const reverse_iterator<U> &u) { 
			return u.base().operator-(this->_base);
		};
		
		reverse_iterator	operator+ (difference_type n) const {
			return reverse_iterator(this->_base.operator-(n));
		};
		
		reverse_iterator	&operator+=(difference_type n) {
			this->_base.operator-=(n);
			return *this;
		};
		
		reverse_iterator	operator- (difference_type n) const {
			return reverse_iterator(this->_base.operator+(n));
		};
		
		reverse_iterator	&operator-=(difference_type n) {
			this->_base.operator+=(n); 
			return *this;
		};
		
		reference			operator[](difference_type n) const {
			return *this->operator+(n);
		};
//Comparators
		template <class U> bool	operator==(const reverse_iterator<U> &rhs) const {
			return this->_base.operator==(rhs.base());
		};
		
		template <class U> bool	operator!=(const reverse_iterator<U> &rhs) const {
			return this->_base.operator!=(rhs.base());
		};
		
		template <class U> bool	operator< (const reverse_iterator<U> &rhs) const {
			return this->_base.operator> (rhs.base());
		};
		
		template <class U>
		bool				operator<=(const reverse_iterator<U> &rhs) const {
			return this->_base.operator>=(rhs.base());
		};
		
		template <class U> 
		bool				operator> (const reverse_iterator<U> &rhs) const {
			return this->_base.operator< (rhs.base());
		};
		
		template <class U>
		bool				operator>=(const reverse_iterator<U> &rhs) const {
			return this->_base.operator<=(rhs.base()); 
		};

		iterator_type		base(void) const {
			return this->_base;
		}
};

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(void) : _base() { }

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(Iterator x) : _base(x) { }
}

#endif