#include "RBTree_dclr.hpp"

namespace ft {

//constructors
	template<class T, class Allocator>
	RBTree<T, Allocator>::RBTree(const Allocator alloc) : _size(0), _height(0), _alloc(alloc)
	{
		this->_end.parent = nullptr;
		this->_end.value = nullptr;
		this->_end.left = nullptr;
		this->TNULL = new typename RBTree<T, Allocator>::node;
		this->TNULL->color = BLACK;
		this->TNULL->left = nullptr;
		this->TNULL->right = nullptr;
		this->TNULL->parent = nullptr;
		this->_root = this->TNULL;
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
		if (start == this->TNULL)
			return this->end();
		while (start->left != this->TNULL)
		{
			start = start->left;
		}	
		return typename RBTree<T, Allocator>::iterator(start, this->TNULL);
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::const_iterator			RBTree<T, Allocator>::begin( void ) const
	{
		//find left most node
		nodePTR start = this->_root;
		if (start == this->TNULL)
			return this->_end();
		while (start->left != this->TNULL)
			start = start->left;
		return typename RBTree<T, Allocator>::const_iterator(start, this->TNULL);
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::iterator					RBTree<T, Allocator>::end( void )
	{
		return iterator(&(this->_end), this->TNULL);
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::const_iterator				RBTree<T, Allocator>::end( void )   const
	{
		return const_iterator(&(this->_end), this->TNULL);
	}

	template<class T, class Allocator>
	typename RBTree<T, Allocator>::nodePTR
	RBTree<T, Allocator>::minimum(nodePTR node)
	{
		if (node == this->TNULL)
			return node;
		while (node->left != this->TNULL)
			node = node->left;
		return node; 
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
		nodePTR	next = this->TNULL;
		//binary search for insertion
		while (current != this->TNULL)
		{
			if (new_val < *(current->value))
				next = current->left;
			else if (new_val > *(current->value))
				next = current->right;
			else
				throw RBTree::sameValueException();
			if (next == this->TNULL)
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

	template<class T, class Allocator>
	void RBTree<T, Allocator>::rbTransplant(nodePTR u, nodePTR v){
		if (u == this->_root) {
			this->_root = v;
			this->_root->parent = &this->_end;
			this->_end.left = v;
		} else if (u == u->parent->left){
			u->parent->left = v;
		} else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	template<class T, class Allocator>
	void
	RBTree<T, Allocator>::erase(const value_type &val_to_delete)
	{
		//find element in tree
		nodePTR	current = this->_root;
		nodePTR	min = this->TNULL;
		nodePTR	res = this->TNULL;
		while (current != this->TNULL)
		{
			if (val_to_delete == *(current->value))
				break ;
			else if (val_to_delete < *(current->value))
				res = current->left;
			else 
				res = current->right;
			current = res;
		}
		if (current == this->TNULL)
			return ;
		//finded: it point to the element
		// std::cout << "element finded: " << *current << std::endl;

		int original_color = current->color;
		if (current->left == this->TNULL) {
			res = current->right;
			rbTransplant(current, res);
		} else if (current->right == this->TNULL) {
			res = current->left;
			rbTransplant(current, res);
		} else {
			// std::cout << "two childs " << std::endl;
			min = minimum(current->right);
			// std::cout << "min R = " << *min << std::endl;
			original_color = min->color;
			res = min->right;
			if (min->parent == current) {
				res->parent = min;
			} else {
				rbTransplant(min, min->right);
				min->right = current->right;
				min->right->parent = min;
			}

			rbTransplant(current, min);
			min->left = current->left;
			min->left->parent = min;
			min->color = original_color;
		}
		// this->print();
		// std::cout << "FIX delete " << original_color << std::endl;
		if (original_color == BLACK){
			this->fix_delete(res);
		}
		delete current;
		this->_size--;
		return ;
	}

//affichage
	template<class T, class Allocator>
	void
	RBTree<T, Allocator>::print( void ) const
	{
		if (this->_root == this->TNULL)
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
		if (node == this->TNULL)
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
		newNode->left = this->TNULL;
		newNode->right = this->TNULL;
		newNode->color = BLACK;
		//TODO delete newNode value at end of life
		return newNode;
	}  //REVIEW en static?

/*
** ------------------------------- BALANCING --------------------------------
*/

	template<class T, class Allocator>
	void					RBTree<T, Allocator>::fix_insert(nodePTR k)
	{
		while (k->parent->color == RED)
		{
			nodePTR uncle = k->getUncle();
			if ((uncle != this->TNULL && uncle != nullptr) && uncle->color == RED)
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
	void					RBTree<T, Allocator>::fix_delete(nodePTR k)
	{
		if (k == this->TNULL)
			return ;
		nodePTR S;
		while (k != this->_root && k->color == BLACK)
		{
			if (k == k->parent->left)
			{
				S = k->parent->right;
				if (S->color == RED) // cas 3.1
				{
					k->parent->right->color = BLACK;
					k->parent->color = RED;
					this->leftRotate(k->parent);
					S = k->parent->right;
				}
				if (S->left->color == BLACK
				&&	S->right->color == BLACK) // case 3.2
				{
					S->color = RED;
					k = k->parent;
				}
				else
				{
					if (S->right->color == BLACK) //case 3.3
					{
						S->left->color = BLACK;
						S->color = RED;
						this->rightRotate(S);
						S = k->parent->right;
					}
					S->color = k->parent->color;//case 3.4
					k->parent->color = BLACK;
					S->right->color = BLACK;
					this->leftRotate(k->parent);
					k = this->_root;
				}
			}
			else
			{
				S = k->parent->left;
				if (S->color == RED) // cas 3.1
				{
					k->parent->left->color = BLACK;
					k->parent->color = RED;
					this->rightRotate(k->parent);
					S = k->parent->left;
				}
				if (S->left->color == BLACK
				&&	S->right->color == BLACK) // case 3.2
				{
					S->color = RED;
					k = k->parent;
				}
				else
				{
					if (S->left->color == BLACK) //case 3.3
					{
						S->right->color = BLACK;
						S->color = RED;
						this->leftRotate(S);
						S = k->parent->left;
					}
					S->color = k->parent->color;//case 3.4
					k->parent->color = BLACK;
					S->left->color = BLACK;
					this->rightRotate(k->parent);
					k = this->_root;
				}
			}
		}
		k->color = BLACK;
	}

	template<class T, class Allocator>
	void					RBTree<T, Allocator>::leftRotate(nodePTR x)
	{
		nodePTR	y = x->right;
		if (y->left != this->TNULL)
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
	void					RBTree<T, Allocator>::rightRotate(nodePTR x)
	{
		nodePTR	y = x->left;
		if (y->right != this->TNULL)
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