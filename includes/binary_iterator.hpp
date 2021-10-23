#ifndef BINARY_ITERATOR_HPP
#define BINARY_ITERATOR_HPP

template<class T, class NODEPTR>
class binary_iterator
{
	public:
		typedef ptrdiff_t							difference_type;
		typedef NODEPTR								value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		binary_iterator_category;

	protected:
		value_type 		_value;
		value_type		TNULL;
		
	public:
		binary_iterator() : _value(nullptr), TNULL(nullptr) {}

		binary_iterator(value_type value, value_type TNULL = nullptr) : _value(value), TNULL(TNULL) {
			// std::cout << "construct binary_iterator" << std::endl;
		}

		binary_iterator(const binary_iterator& src) : _value(src._value), TNULL(src.TNULL) {}

		~binary_iterator() {}

		binary_iterator		&operator=(const binary_iterator & rhs)
		{
			if (this != &rhs)
			{
				this->_value = rhs._value;
				this->TNULL = rhs.TNULL;
			}
			return *this;
		}

		reference							operator*(void) const
		{
			return *(this->_value->value);
		}

		pointer								operator->(void) const
		{
			if (this->_value != nullptr)
				return (this->value->value);
			return nullptr;
		}
		
		// binary_iterator::difference_type			operator+(const binary_iterator & rhs)
		// {
		// 	return (this->_value + rhs._value);
		// }
		
		binary_iterator::difference_type			operator-(const binary_iterator & rhs)
		{
			binary_iterator::difference_type i = 0;
			binary_iterator cpy(*this);
			if (cpy > rhs)
			{
				while (cpy != rhs)
				{
					++i;
					--cpy;
				}
			}else {
				while (cpy != rhs)
				{
					--i;
					++cpy;
				}
			}
			return i;
		}
		
		binary_iterator							operator+(difference_type n)
		{
			binary_iterator cpy(this->_value, this->TNULL);
			while (--n >= 0)
				++cpy;
			return cpy;
		}
		
		binary_iterator							operator-(difference_type n)
		{
			binary_iterator cpy(this->_value, this->TNULL);
			while (--n >= 0)
				--cpy;
			return cpy;
		}
		
		binary_iterator							&operator+=(difference_type n)
		{
			while (--n >= 0)
				this->operator++();
			return *this;
		}

		binary_iterator							&operator-=(difference_type n)
		{
			while (--n >= 0)
				this->operator--();
			return *this;
		}

		bool								operator!=(const binary_iterator &rhs) const {
			return (this->_value != rhs._value);
		}

		bool								operator==(const binary_iterator &rhs) const {
			return (this->_value == rhs._value);
		}
		
		binary_iterator			&operator++(void)
		{	
			if (this->_value == nullptr)
				return *this;
			if (this->_value->right == this->TNULL
				&& this->_value->parent != nullptr) //no child
			{
				while (this->_value->parent != nullptr && this->_value->parent->right == this->_value) //come from right child
					this->_value = this->_value->parent;
				this->_value = this->_value->parent;
				return *this;
			}
			else if (this->_value->right != this->TNULL && this->_value->right != nullptr) // have a right child
				this->_value = this->_value->right;
			//its _end
			while (this->_value->left != this->TNULL)
				this->_value = this->_value->left;
			return *this;
		}

		binary_iterator			operator++(int)
		{
			binary_iterator cpy(*this);
			if (this->_value == nullptr)
				return cpy;
			if (this->_value->right == this->TNULL
				&& this->_value->parent != nullptr) //no child
			{
				while (this->_value->parent != nullptr && this->_value->parent->right == this->_value) //come from right child
					this->_value = this->_value->parent;
				this->_value = this->_value->parent;
				return cpy;
			}
			else if (this->_value->right != this->TNULL && this->_value->right != nullptr) // have a right child
				this->_value = this->_value->right;
			//its _end
			while (this->_value->left != this->TNULL)
				this->_value = this->_value->left;
			return cpy;
		}

		binary_iterator			&operator--(void)
		{
			if (this->_value == nullptr)
				return *this;
			if (this->_value->left == this->TNULL
				&& this->_value->parent != nullptr) //no child
			{
				while (this->_value->parent != nullptr && this->_value->parent->left == this->_value) //come from left child
					this->_value = this->_value->parent;
				if (this->_value->parent != nullptr)
					this->_value = this->_value->parent;
				return *this;
			}
			else if (this->_value->left != this->TNULL && this->_value->left != nullptr) // have a left child
				this->_value = this->_value->left;
			//its _end
			while (this->_value->right != this->TNULL)
				this->_value = this->_value->right;
			return *this;
		}

		binary_iterator			operator--(int)
		{
			binary_iterator cpy(*this);
			if (this->_value == nullptr)
				return cpy;
			if (this->_value->left == this->TNULL
				&& this->_value->parent != nullptr) //no child
			{
				while (this->_value->parent != nullptr && this->_value->parent->left == this->_value) //come from left child
					this->_value = this->_value->parent;
				if (this->_value->parent != nullptr)
					this->_value = this->_value->parent;
				return cpy;
			}
			else if (this->_value->left != this->TNULL && this->_value->left != nullptr) // have a left child
				this->_value = this->_value->left;
			//its _end
			while (this->_value->right != this->TNULL)
				this->_value = this->_value->right;
			return cpy;
		}

		bool				operator<(const binary_iterator& rhs)
		{
			if (this->_value == nullptr && rhs._value == nullptr)
				return false;
			else if (this->_value == nullptr || rhs._value == nullptr)
				return (this->_value == nullptr ? true : false);
			else if (this->_value->value == nullptr && rhs._value->value == nullptr)
				return false;
			else if (this->_value->value == nullptr || rhs._value->value == nullptr)
				return (this->_value->value == nullptr ? false : true);
			else
				return (*(this->_value->value) < *(rhs._value->value));
		}
		
		bool				operator>(const binary_iterator& rhs)
		{
			if (this->_value == nullptr && rhs._value == nullptr)
				return false;
			else if (this->_value == nullptr || rhs._value == nullptr)
				return (this->_value == nullptr ? true : false);
			else if (this->_value->value == nullptr && rhs._value->value == nullptr)
				return false;
			else if (this->_value->value == nullptr || rhs._value->value == nullptr)
				return (this->_value->value == nullptr ? true : false);
			else
				return (*(this->_value->value) > *(rhs._value->value));
		}
		
		bool				operator<=(const binary_iterator& rhs)
		{
			if (this->_value == nullptr && rhs._value == nullptr)
				return true;
			else if (this->_value == nullptr || rhs._value == nullptr)
				return false;
			else if (this->_value->value == nullptr && rhs._value->value == nullptr)
				return true;
			else if (this->_value->value == nullptr || rhs._value->value == nullptr)
				return (this->_value->value == nullptr ? false : true);
			else
				return (*(this->_value->value) <= *(rhs._value->value));
		}
		
		bool				operator>=(const binary_iterator& rhs)
		{
			if (this->_value == nullptr && rhs._value == nullptr)
				return true;
			else if (this->_value == nullptr || rhs._value == nullptr)
				return false;
			else if (this->_value->value == nullptr && rhs._value->value == nullptr)
				return true;
			else if (this->_value->value == nullptr || rhs._value->value == nullptr)
				return (this->_value->value == nullptr ? true : false);
			else
				return (*(this->_value->value) >= *(rhs._value->value));
		}

};

#endif				//BINARY_ITERATOR_HPP