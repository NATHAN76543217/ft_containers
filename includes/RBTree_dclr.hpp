#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <memory>
#include <iostream>
#include "binary_iterator.hpp"
#include "base.hpp"
#define RED		0
#define BLACK	1
#define LEFT	0
#define RIGHT	1

#define COLOR_RED		"\e[31m"
#define COLOR_BGRED		"\e[41m"
#define COLOR_BGGREY	"\e[47m"
#define COLOR_RESET		"\e[0m"

namespace ft {
	template<class T, bool (*Checker)(const T&, const T&) = ft::is_equal<T>, class Allocator = std::allocator<T> >
	class RBTree {
		public:
			typedef T       				value_type;
			typedef	size_t					size_type;
			typedef Allocator				allocator_type;
			// typedef bool (*Checker)(value_type, value_type);

			class sameValueException : public std::exception {
				public:
					virtual const char *what( void ) const throw()
					{
						return "RBTree cannot contain the same value twice."; 
					}
			};
			class  node
			{
				public:
					node		*parent;
					node		*left;
					node		*right;
					value_type  *value;
					bool		color;

					friend std::ostream		&operator<<(std::ostream& os, const typename RBTree<T, Checker, Allocator>::node &node)
					{
						os << "(" << *(node.value) << ","  << ((node.color == RED) ? COLOR_BGRED : COLOR_BGGREY) << " " << COLOR_RESET << ")";
						return os;
					}

					void	swapColor()
					{
						this->color = !this->color;
					}

					bool	isRightChild( void ) const
					{
						if (this->parent == nullptr)
							return true;
						if (this->parent->right == this)
							return true;
						return (false);
					}

					static node	*getSibling(node &node) {
						if (node.parent == nullptr)
							return nullptr;
						if (node.parent->right == &node)
							return node.parent->left;
						else
							return node.parent->right;
					}

					node	*getUncle( void ) {
						if (this->parent != nullptr)
							return node::getSibling(*this->parent);
						return nullptr; 
					}
			};

			typedef node*					nodePTR;
			typedef node&					nodeREF;
			typedef std::allocator<node>	node_allocator_type;

			RBTree(const Allocator alloc = Allocator());
			virtual ~RBTree();

			nodePTR			getRoot( void );

//TODO implement/ verifie usage of comparator function for comparison
/*
** ------------------------------- ITERATORS --------------------------------
*/
		class iterator : public binary_iterator<T, nodePTR>
		{
			public:
				typedef typename binary_iterator<T, nodePTR>::value_type			value_type;
				typedef typename binary_iterator<T, nodePTR>::difference_type		difference_type;
				typedef typename binary_iterator<T, nodePTR>::pointer				pointer;
				typedef typename binary_iterator<T, nodePTR>::reference				reference;
				typedef typename binary_iterator<T, nodePTR>::iterator_category		iterator_category;
				iterator() : binary_iterator<T, nodePTR>() {}
				iterator(const nodePTR node, nodePTR leaf) : binary_iterator<T, nodePTR>(node, leaf) {}
				iterator(const iterator &src) : binary_iterator<T, nodePTR>(src) {}
				iterator(const binary_iterator<T, nodePTR> &src) : binary_iterator<T, nodePTR>(src) {}

				iterator	&operator=(const iterator & rhs)
				{
					if (this != &rhs)
					{
						this->_value = rhs._value;
						this->TNULL = rhs.TNULL;
					}
					return *this;
				}
				
				iterator	&operator=(const binary_iterator<T, nodePTR> & rhs)
				{
					if (this != &rhs)
					{
						this->binary_iterator<T, nodePTR>::operator=(rhs);
					}
					return *this;
				}

				iterator			&operator++(void)
				{
					this->binary_iterator<T, nodePTR>::operator++();
					return *this;
				}

				iterator			operator++(int)
				{
					iterator	cpy(*this);
					this->binary_iterator<T, nodePTR>::operator++();
					return cpy;
				}
				
				iterator			&operator--(void)
				{
					this->binary_iterator<T, nodePTR>::operator--();
					return *this;
				}

				iterator			operator--(int)
				{
					iterator	cpy(*this);
					this->binary_iterator<T, nodePTR>::operator--();
					return cpy;
				}
		};

		class const_iterator : public binary_iterator<const T, nodePTR>
		{
			public:
				typedef typename binary_iterator<const T, nodePTR>::value_type			value_type;
				typedef typename binary_iterator<const T, nodePTR>::difference_type		difference_type;
				typedef typename binary_iterator<const T, nodePTR>::pointer				pointer;
				typedef typename binary_iterator<const T, nodePTR>::reference			reference;
				typedef typename binary_iterator<const T, nodePTR>::iterator_category	iterator_category;
			
				const_iterator() : binary_iterator<const T, nodePTR>() {}
				const_iterator(const nodePTR node, const nodePTR leaf) : binary_iterator<const T, nodePTR>(node, leaf) {}
				const_iterator(const iterator &src) : binary_iterator< const T, nodePTR>(src) {}
				const_iterator(const binary_iterator<T, nodePTR> &src) : binary_iterator< const T, nodePTR>(src) {}
			
			const_iterator	&operator=(const const_iterator & rhs)
			{
				if (this != &rhs)
				{
					this->_value = rhs._value;
					this->TNULL = rhs.TNULL;
				}
				return *this;
			}
			
			const_iterator	&operator=(const binary_iterator<const T, nodePTR> & rhs)
			{
				if (this != &rhs)
				{
					this->binary_iterator<const T, nodePTR>::operator=(rhs);
				}
				return *this;
			}

			const_iterator			&operator++(void)
			{
				this->binary_iterator<const T, nodePTR>::operator++();
				return *this;
			}

			const_iterator			operator++(int)
			{
				const_iterator	cpy(*this);
				this->binary_iterator<const T, nodePTR>::operator++();
				return cpy;
			}

			const_iterator			&operator--(void)
			{
				this->binary_iterator<const T, nodePTR>::operator--();
				return *this;
			}

			const_iterator			operator--(int)
			{
				const_iterator	cpy(*this);
				this->binary_iterator<const T, nodePTR>::operator--();
				return cpy;
			}

		};

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			
		iterator					begin( void );
		const_iterator				begin( void ) const;
		iterator					end( void );
		const_iterator				end( void )   const;
		reverse_iterator			rbegin( void );
		const_reverse_iterator		rbegin( void ) const;
		reverse_iterator			rend( void );
		const_reverse_iterator		rend( void )   const;
/*
** ------------------------------- MODIFIERS --------------------------------
*/
			nodeREF			insert(const value_type &new_val);
			size_type		erase(const value_type &val_to_delete);

			void			clear();

			void			print( void ) const;
			void			print(std::string prefix, nodePTR node, bool isLeft) const;

	/*
	** ------------------------------- CAPACITY --------------------------------
	*/
			bool			empty( void ) const;
			size_type		size( void ) const;

	/*
	** ----------------------------- ALLOCATOR --------------------------------
	*/
			allocator_type	get_allocator( void ) const;
	
	/*
	** ----------------------------- OPERATIONS --------------------------------
	*/
	    iterator							find(const value_type& k);
    	const_iterator						find(const value_type& k) const;
		iterator							lower_bound(const value_type& k);
		const_iterator						lower_bound(const value_type& k) const;
		iterator							upper_bound(const value_type& k);
		const_iterator						upper_bound(const value_type& k) const;

		pair<iterator,iterator>             equal_range(const value_type& k);	
		pair<const_iterator,const_iterator> equal_range(const value_type& k) const;

		protected:
			void			rbTransplant(nodePTR u, nodePTR v);
			nodePTR			minimum(nodePTR node);
			nodePTR			create_node(const value_type &value, nodePTR parent = nullptr);
			void			fix_insert(nodePTR k);
			void			fix_delete(nodePTR k);
			void			leftRotate(nodePTR x);
			void			rightRotate(nodePTR x);

//TODO repasser en private
		public:
			nodePTR					_root;
			nodePTR					TNULL;
			size_type				_size;
			//TODO implement height variable with getter
			size_type				_height;
			node_allocator_type		_node_alloc;
			allocator_type			_alloc;
			node					_end;
	};

};
#endif      //RBTREE_HPP