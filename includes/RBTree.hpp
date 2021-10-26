#include "RBTree_dclr.hpp"

namespace ft {

//constructors
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	RBTree<T, Checker, Allocator>::RBTree(const Allocator alloc) : _size(0), _height(0), _alloc(alloc)
	{
		this->_end.parent = nullptr;
		this->_end.value = nullptr;
		this->_end.left = nullptr;
		this->_end.right = nullptr;
		this->TNULL = new typename RBTree<T, Checker, Allocator>::node;
		this->TNULL->color = BLACK;
		this->TNULL->left = nullptr;
		this->TNULL->right = nullptr;
		this->TNULL->parent = nullptr;
		this->TNULL->value = nullptr;
		this->_root = this->TNULL;
		// std::cout << "RBT default creation" << std::endl;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	RBTree<T, Checker, Allocator>::~RBTree() {
				//TODO delete every node and value inside it (allocator.desallocate) done?
			this->clear();
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::nodePTR
	RBTree<T, Checker, Allocator>::getRoot( void ) {
		return this->_root;
	}

/*
** ------------------------------- ITERATORS --------------------------------
*/
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::iterator					RBTree<T, Checker, Allocator>::begin( void )
	{
		//find left most node
		nodePTR start = this->_root;
		if (start == this->TNULL)
			return this->end();
		while (start->left != this->TNULL)
		{
			start = start->left;
		}	
		return typename RBTree<T, Checker, Allocator>::iterator(start, this->TNULL);
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::const_iterator			RBTree<T, Checker, Allocator>::begin( void ) const
	{
		//find left most node
		nodePTR start = this->_root;
		if (start == this->TNULL)
			return this->end();
		while (start->left != this->TNULL)
			start = start->left;
		return typename RBTree<T, Checker, Allocator>::const_iterator(start, this->TNULL);
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::iterator					RBTree<T, Checker, Allocator>::end( void )
	{
		return iterator(&(this->_end), this->TNULL);
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::const_iterator				RBTree<T, Checker, Allocator>::end( void )   const
	{
		return const_iterator(const_cast<const nodePTR>(&(this->_end)), this->TNULL);
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::reverse_iterator
	RBTree<T, Checker, Allocator>::rbegin( void )
	{
		typename RBTree<T, Checker, Allocator>::iterator res = --this->end();
		return reverse_iterator(res);
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::const_reverse_iterator
	RBTree<T, Checker, Allocator>::rbegin( void ) const
	{
		// typename RBTree<T, Checker, Allocator>::const_iterator res = ;
		return const_reverse_iterator(--this->end());
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::reverse_iterator
	RBTree<T, Checker, Allocator>::rend( void )
	{
		return reverse_iterator(this->end());
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::const_reverse_iterator
	RBTree<T, Checker, Allocator>::rend( void ) const
	{
		return const_reverse_iterator(this->end());
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::nodePTR
	RBTree<T, Checker, Allocator>::minimum(nodePTR node)
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
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::nodeREF
	RBTree<T, Checker, Allocator>::insert(const value_type &new_val)
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
			if (Checker(new_val, *(current->value)))
				next = current->left;
			else if (Checker(*(current->value), new_val))
				next = current->right;
			else
				throw RBTree::sameValueException();
			if (next == this->TNULL)
			{
				if (Checker(new_val, *(current->value)))
					next = current->left = this->create_node(new_val, current);
				else if (Checker(*(current->value), new_val))
					next = current->right = this->create_node(new_val, current);
				else
					throw RBTree::sameValueException();
				current = next;
				break ;
			}	
			else
				current = next;
		}
		current->color = RED;
		this->_size++;
		if (current != this->_root)
			this->fix_insert(current);
		return *current;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void RBTree<T, Checker, Allocator>::rbTransplant(nodePTR u, nodePTR v){
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

	template<class T, bool (*Checker)(const T&, const T&), class Allocator>
	typename RBTree<T, Checker, Allocator>::size_type
	RBTree<T, Checker, Allocator>::erase(const value_type &val_to_delete)
	{
		//find element in tree
		nodePTR	current = this->_root;
		nodePTR	min = this->TNULL;
		nodePTR	res = this->TNULL;
		while (current != this->TNULL)
		{
			if (Checker(val_to_delete,  *(current->value)))
				res = current->left;
			else if (Checker(*(current->value), val_to_delete))
				res = current->right;
			else 
				break ;
			current = res;
		}
		if (current == this->TNULL)
			return 0;

		int original_color = current->color;
		if (current->left == this->TNULL) {
			res = current->right;
			rbTransplant(current, res);
		} else if (current->right == this->TNULL) {
			res = current->left;
			rbTransplant(current, res);
		} else {
			min = minimum(current->right);
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
		if (original_color == BLACK){
			this->fix_delete(res);
		}
		if (current->value != nullptr)
			this->_alloc.deallocate(current->value, 1);
		this->_node_alloc.deallocate(current, 1);
		this->_size--;
		return 1;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void
	RBTree<T, Checker, Allocator>::clear( void )
	{
		typename RBTree<T, Checker, Allocator>::iterator it = this->begin();
		while (it != this->end())
			this->erase(*(it++));
	}

/*
** ------------------------------- DISPLAY --------------------------------
*/

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void
	RBTree<T, Checker, Allocator>::print( void ) const
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

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void
	RBTree<T, Checker, Allocator>::print(std::string prefix, node *node, bool isLeft) const
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
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	bool
	RBTree<T, Checker, Allocator>::empty( void ) const {
		return (this->_size == 0);
	}
		
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::size_type
	RBTree<T, Checker, Allocator>::size( void ) const
	{
		return this->_size;
	}

/*
** ------------------------------- ALLOCATORS --------------------------------
*/
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::allocator_type
	RBTree<T, Checker, Allocator>::get_allocator( void ) const
	{
		return this->_alloc;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::nodePTR
	RBTree<T, Checker, Allocator>::create_node(const value_type &value, node *parent) {
		nodePTR	newNode = this->_node_alloc.allocate(1);
		newNode->value = this->_alloc.allocate(1);
		this->_alloc.construct(newNode->value, value);
		newNode->parent = parent;
		newNode->left = this->TNULL;
		newNode->right = this->TNULL;
		newNode->color = BLACK;
		// TODO delete newNode at end of life
		// TODO delete newNode value at end of life
		return newNode;
	}  //REVIEW en static?

/*
** ----------------------------- OPERATIONS --------------------------------
*/
	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::iterator
	RBTree<T, Checker, Allocator>::find(const typename RBTree<T, Checker, Allocator>::value_type& k)
	{
		nodePTR current = this->_root;
		// std::find(this->begin(), this->end())
		while (current != this->TNULL)
		{
			if (Checker(k,  *(current->value)))
				current = current->left;
			else if (Checker(*(current->value), k))
				current = current->right;
			else
				return iterator(current);
		}
		return this->end();
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
    typename RBTree<T, Checker, Allocator>::const_iterator
	RBTree<T, Checker, Allocator>::find(const typename RBTree<T, Checker, Allocator>::value_type& k) const
	{
		nodePTR current = this->_root;
		// std::find(this->begin(), this->end())
		while (current != this->TNULL)
		{
			if (Checker(k,  *(current->value)))
				current = current->left;
			else if (Checker(*(current->value), k))
				current = current->right;
			else
				return const_iterator(current, this->TNULL);
		}
		return this->end();
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::iterator
	RBTree<T, Checker, Allocator>::lower_bound(const value_type& k)
	{
		iterator it = this->begin();

		while(it != this->end() && Checker(*it, k))
			++it;
		return it;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::const_iterator
	RBTree<T, Checker, Allocator>::lower_bound(const value_type& k) const
	{
		const_iterator it = this->begin();

		while(it != this->end() && Checker(*it, k))
			++it;
		return it;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::iterator
	RBTree<T, Checker, Allocator>::upper_bound(const value_type& k)
	{
		iterator it = this->begin();

		while(it != this->end() && !Checker(k, *it))
			++it;
		return it;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	typename RBTree<T, Checker, Allocator>::const_iterator
	RBTree<T, Checker, Allocator>::upper_bound(const value_type& k) const
	{
		const_iterator it = this->begin();

		while(it != this->end() && !Checker(k, *it))
			++it;
		return it;
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	ft::pair<typename RBTree<T, Checker, Allocator>::iterator, typename RBTree<T, Checker, Allocator>::iterator>
	RBTree<T, Checker, Allocator>::equal_range(const value_type& k)
	{
		iterator it = this->begin();
		while(it != this->end() && Checker(*it, k))
			++it;
		iterator first = it;
		while(it != this->end() && !Checker(k, *it))
			++it;
		return ft::make_pair(first, it);
	}

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	ft::pair<typename RBTree<T, Checker, Allocator>::const_iterator, typename RBTree<T, Checker, Allocator>::const_iterator>
	RBTree<T, Checker, Allocator>::equal_range(const value_type& k) const
	{
		const_iterator it = this->begin();
		while(it != this->end() && Checker(*it, k))
			++it;
		const_iterator first = it;
		while(it != this->end() && !Checker(k, *it))
			++it;
		return ft::make_pair(first, it);
	}

/*
** ------------------------------- BALANCING --------------------------------
*/

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void					RBTree<T, Checker, Allocator>::fix_insert(nodePTR k)
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


	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void					RBTree<T, Checker, Allocator>::fix_delete(nodePTR k)
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

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void					RBTree<T, Checker, Allocator>::leftRotate(nodePTR x)
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

	template<class T, bool (*Checker)(const T&, const T&), class Allocator >
	void					RBTree<T, Checker, Allocator>::rightRotate(nodePTR x)
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