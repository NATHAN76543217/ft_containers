#include "RBTree_dclr.hpp"

namespace ft {

//constructors
	template<class T, class Allocator>
	RBTree<T, Allocator>::RBTree(const Allocator alloc) : _root(NULL), _size(0), _height(0), _alloc(alloc)
	{
		this->_end.value = nullptr;
		this->_end.left = nullptr;
		std::cout << "RBT default creation" << std::endl;
	}

	template<class T, class Allocator>
	RBTree<T, Allocator>::~RBTree() {
				//TODO delete avery node and value inside it (allocator.desallocate)
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::nodePTR
	RBTree<T, Allocator>::getRoot( void ) {
		return this->_root;
	}

/*
** ------------------------------- ITERATORS --------------------------------
*/
	template<class T, class Allocator>
	typename RBTree<T, Allocator>::iterator					RBTree<T, Allocator>::begin( void )
	{
		//find left most node
		nodePTR start = this->_root;
		if (start == nullptr)
			return this->end();
		while (start->left != nullptr)
		{
			start = start->left;
		}	
		return typename RBTree<T, Allocator>::iterator(start);
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::const_iterator			RBTree<T, Allocator>::begin( void ) const
	{
		//find left most node
		nodePTR start = this->_root;
		if (start == nullptr)
			return this->_end();
		while (start->left != nullptr)
			start = start->left;
		return typename RBTree<T, Allocator>::const_iterator(start);
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::iterator					RBTree<T, Allocator>::end( void )
	{
		return iterator(&(this->_end));
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::const_iterator				RBTree<T, Allocator>::end( void )   const
	{
		return const_iterator(&(this->_end));
	}

/*
** ------------------------------- MODIFIERS --------------------------------
*/
	template<class T, class Allocator>
	typename RBTree<T, Allocator>::nodeREF
	RBTree<T, Allocator>::insert(const value_type &new_val)
	{
		if (this->_size == 0 )
		{
			this->_root = this->create_node(new_val, &this->_end);
			this->_end.left = this->_root;
			this->_root->parent = &this->_end;
			this->_size++;
			return *this->_root;
		}
		nodePTR	current = this->_root;
		nodePTR	next;
		//binary search for insertion
		while (current != nullptr)
		{
			if (new_val < *(current->value))
				next = current->left;
			else if (new_val > *(current->value))
				next = current->right;
			else
				throw RBTree::sameValueException();
			if (next == nullptr)
			{
				if (new_val < *(current->value))
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
		if (current != this->_root)
			this->fix_insert(current);
		return *current;
	}

//affichage
	template<class T, class Allocator>
	void
	RBTree<T, Allocator>::print( void ) const
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

	template<class T, class Allocator>
	void
	RBTree<T, Allocator>::print(std::string prefix, node *node, bool isLeft) const
	{
		//TODO change printing that match the content size
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
    	
/*
** ------------------------------- CAPACITY --------------------------------
*/
	template<class T, class Allocator>
	bool
	RBTree<T, Allocator>::empty( void ) const {
		return (this->_size == 0);
	}
		
	template<class T, class Allocator>
	typename RBTree<T, Allocator>::size_type
	RBTree<T, Allocator>::size( void ) const
	{
		return this->_size;
	}

/*
** ------------------------------- ALLOCATORS --------------------------------
*/
	template<class T, class Allocator>
	typename RBTree<T, Allocator>::allocator_type
	RBTree<T, Allocator>::getAllocator( void ) const
	{
		return this->_alloc;
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::nodePTR
	RBTree<T, Allocator>::create_node(const value_type &value, node *parent) {
		node *newNode = reinterpret_cast<node *>(this->_alloc.allocate(sizeof(node)));
		newNode->value = reinterpret_cast<value_type *>(this->_alloc.allocate(sizeof(value_type)));
		new (newNode->value) value_type(value);
		newNode->parent = parent;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->color = BLACK;
		//TODO delete newNode value at end of life
		return newNode;
	}  //REVIEW en static?

/*
** ------------------------------- BALANCING --------------------------------
*/

	template<class T, class Allocator>
	void					RBTree<T, Allocator>::fix_insert(node *k)
	{
		while (k->parent->color == RED)
		{
			node * uncle = k->getUncle();
			if (uncle != nullptr && uncle->color == RED)
			{
				uncle->swapColor();
				k->parent->color = BLACK;
				if (k != this->_root)
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

	template<class T, class Allocator>
	void					RBTree<T, Allocator>::leftRotate(node *x)
	{
		nodePTR	y = x->right;
		if (y->left != nullptr)
			y->left->parent = x;
		x->right = y->left;
		y->left = x;
		y->parent = x->parent;
		if (x == this->_root)
		{
			this->_root = y;
			this->_root->parent = &this->_end;
			this->_end.left = this->_root;
		}
		else if (x->isRightChild())
			x->parent->right = y;
		else
			x->parent->left = y;
		x->parent = y;
	}

	template<class T, class Allocator>
	void					RBTree<T, Allocator>::rightRotate(node *x)
	{
		nodePTR	y = x->left;
		if (y->right != nullptr)
			y->right->parent = x;
		x->left = y->right;
		y->right = x;
		y->parent = x->parent;
		if (x == this->_root)
		{
			this->_root = y;
			this->_root->parent = &this->_end;
			this->_end.left = this->_root;
		}
		else if (x->isRightChild())
			x->parent->right = y;
		else
			x->parent->left = y;
		x->parent = y;
	}
};