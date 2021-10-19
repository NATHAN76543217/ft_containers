#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <memory>
#include <iostream>

#define RED		0
#define BLACK	1

#define COLOR_RED		"\e[31m"
#define COLOR_BGRED		"\e[41m"
#define COLOR_BGGREY		"\e[47m"
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
					value_type  value;
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

			RBTree(const Allocator alloc = Allocator()) : _root(NULL), _size(0), _height(0), _alloc(alloc)
			{
				std::cout << "RBT default creation" << std::endl;
			}

			nodePTR	getRoot( void ) {
				return this->_root;
			}

			node	&insert(const value_type &new_val)
			{
				if (this->_size == 0 )
				{
					this->_root = this->create_node(new_val);
					this->_size++;
					return *this->_root;
				}
				nodePTR	current = this->_root;
				nodePTR	next;
				//binary search for insertion
				while (current != nullptr)
				{
					if (new_val < current->value)
						next = current->left;
					else if (new_val > current->value)
						next = current->right;
					else
						throw RBTree::sameValueException();
					if (next == nullptr)
					{
						if (new_val < current->value)
							next = current->left = this->create_node(new_val, current);
						else
							next = current->right = this->create_node(new_val, current);
						current = next;
						break ;
					}	
					else
						current = next;
				}
				//RBT insertion for balencing the tree
				current->color = RED;
				this->_size++;
				// std::cout << "BEFORE FIX:" << std::endl;
				// this->print();
				if (current->parent->parent != nullptr)
					this->fix_insert(current);
				return *current;
			}

			void	print( void ) const
			{
				if (this->_root == nullptr)
					std::cout << "Empty tree" << std::endl;
				else
				{
					std::cout << std::endl << "size: " << this->_size << ", height: " << this->_height << std::endl;
					this->print("", this->_root, false);
				}
				return ;
			}

			void	print(std::string prefix, node *node, bool isLeft) const
			{
				if (node == nullptr)
					return ;
				std::cout << prefix;
				std::cout << (!isLeft ? "├──────" : "└──────" );

				// print the value of the node
				std::cout << *node << std::endl;

				// enter the next tree level - left and right branch
				print( prefix + (!isLeft ? "│      " : "       "), node->right, false);
				print( prefix + (!isLeft ? "│      " : "       "), node->left, true);
			}

		protected:
			node	*create_node(const value_type &value){
				node *newNode = reinterpret_cast<node *>(this->_alloc.allocate(sizeof(node)));
				newNode->value = value;
				newNode->parent = nullptr;
				newNode->left = nullptr;
				newNode->right = nullptr;
				newNode->color = BLACK;
				return newNode;
			} //TODO en static

			node	*create_node(const value_type &value, node *parent) {
				node *newNode = reinterpret_cast<node *>(this->_alloc.allocate(sizeof(node)));
				newNode->value = value;
				newNode->parent = parent;
				newNode->left = nullptr;
				newNode->right = nullptr;
				newNode->color = BLACK;
				return newNode;
			}

			void	fix_insert(node *k)
			{
				while (k->parent->color == RED)
				{
					node * uncle = k->getUncle();
					if (uncle != nullptr && uncle->color == RED)
					{
						uncle->swapColor();
						k->parent->color = BLACK;
						if (k->parent->parent != nullptr)
						{
							k->parent->parent->swapColor();
							k = k->parent->parent;
						}
					}
					else
					{
						if (k->isRightChild() && !k->parent->isRightChild())
						{
							k = k->parent;
							this->leftRotate(k);
						}
						else if (!k->isRightChild() && k->parent->isRightChild()){
							k = k->parent;
							this->rightRotate(k);
						}
						k->parent->swapColor();
						k->parent->parent->swapColor();
						if (k->parent->isRightChild()) //TODO factorise
							this->leftRotate(k->parent->parent);
						else
							this->rightRotate(k->parent->parent);
					}
					if (k == this->_root) {
						break ;
					}
				}
				this->_root->color = BLACK;
			}

			void	leftRotate(node *x)
			{
				// std::cout << "left rotate()" << std::endl ;
				nodePTR	y = x->right;
				if (y->left != nullptr)
					y->left->parent = x;
				x->right = y->left;
				y->left = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					this->_root = y;
				else if (x->isRightChild())
					x->parent->right = y;
				else
					x->parent->left = y;
				x->parent = y;
			}

			void	rightRotate(node *x)
			{
				// std::cout << "right rotate()" << std::endl ;
				nodePTR	y = x->left;
				if (y->right != nullptr)
					y->right->parent = x;
				x->left = y->right;
				y->right = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					this->_root = y;
				else if (x->isRightChild())
					x->parent->right = y;
				else
					x->parent->left = y;
				x->parent = y;
			}

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