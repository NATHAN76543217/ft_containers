#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <memory>
#include <iostream>

#define RED		0
#define BLACK	1

#define COLOR_RED		"\e[31m"
#define COLOR_BGRED		"\e[41m"
#define COLOR_BGGREY	"\e[47m"
#define COLOR_RESET		"\e[0m"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class RBTree {
		public:
			typedef T       		value_type;
			typedef	size_t			size_type;
			typedef Allocator		allocator_type;

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

					friend std::ostream		&operator<<(std::ostream& os, const typename RBTree<T, Allocator>::node &node)
					{
						os << "(" << node.value << ","  << ((node.color == RED) ? COLOR_BGRED : COLOR_BGGREY) << " " << COLOR_RESET << ")";
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

			typedef node*			nodePTR;
			typedef node&			nodeREF;

			RBTree(const Allocator alloc = Allocator());
			virtual ~RBTree();

			nodePTR			getRoot( void );
/*
** ------------------------------- MODIFIERS --------------------------------
*/
			node			&insert(const value_type &new_val);

			void			print( void ) const;
			void			print(std::string prefix, node *node, bool isLeft) const;
    	
	/*
	** ------------------------------- CAPACITY --------------------------------
	*/
			bool			empty( void ) const;
			size_type		size( void ) const;

	/*
	** ----------------------------- ALLOCATOR --------------------------------
	*/
			allocator_type	getAllocator( void ) const;
	
		protected:
			node	*create_node(const value_type &value, node *parent = nullptr);
			void	fix_insert(node *k);
			void	leftRotate(node *x);
			void	rightRotate(node *x);

		private:
			node		*_root;
			size_type	_size;
			//TODO implement height variable with getter
			size_type	_height;
			Allocator	_alloc;
	};

};

//TODO put RBT in ft namespace
#endif      //RBTREE_HPP