#ifndef ITERATOR_DCLR_HPP
# define ITERATOR_DCLR_HPP

#include <cstddef>

namespace ft {

/*
** ------------------------------- ITERATOR TAGS --------------------------------
*/
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	typedef	 input_iterator_tag _input_iterator_tag;
	typedef	 output_iterator_tag _output_iterator_tag; 
	typedef	 forward_iterator_tag _forward_iterator_tag; 
	typedef	 bidirectional_iterator_tag _bidirectional_iterator_tag; 
	typedef	 random_access_iterator_tag _random_access_iterator_tag; 

	template <class Iterator>
	struct iterator_traits
	{
	   typedef typename Iterator::value_type			value_type;
	   typedef typename Iterator::difference_type		difference_type;
	   typedef typename Iterator::pointer				pointer;
	   typedef typename Iterator::reference				reference;
	   typedef typename Iterator::iterator_category		iterator_category;
	};

// Specialization
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef ptrdiff_t					difference_type;
		typedef random_access_iterator_tag	iterator_category;
	};

}
#endif      //ITERATOR_DCLR_HPP