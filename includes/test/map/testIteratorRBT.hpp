#ifndef TESTITERATORRBT
#define TESTITERATORRBT


//TODO check for test: create reverse_iterator from it or const_reverse_iterator
template<class Cnt, class Ite>
int		testPrintState(const Cnt &cnt, Ite &start, Ite &end)	
{
	std::cout << std::endl << "- size  = " << cnt.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << cnt.empty() << std::endl;
	for (; start != end; start++)
		std::cout << "(" << (*start).first << ", " << (*start).second << ") - ";
	return 0;
}

template<class Cnt>
int		testIteratorRBT_const(const Cnt &cnt)
{
	std::cout << std::endl << "TEST	const Iterator" << std::endl;
	typename Cnt::const_iterator it = cnt.begin();
	typename Cnt::const_iterator end = cnt.end();
	typename Cnt::const_reverse_iterator rit = cnt.rbegin();
	typename Cnt::const_reverse_iterator rend = cnt.rend();
	std::cout << std::endl << "TEST	inc/dec" << std::endl;
	it++;
	it--;
	end--;
	end++;
	++rit;
	--rit;
	--rend;
	++rend;
	testPrintState(cnt, it, end);
	testPrintState(cnt, rit, rend);
	return 0;
}

template<class Cnt>
int		testIteratorRBT(Cnt &cnt)
{
	std::cout << std::endl << "TEST	Iterator" << std::endl;
 	typename Cnt::iterator it = cnt.begin();
	typename Cnt::iterator end = cnt.end(); 
	typename Cnt::reverse_iterator rit = cnt.rbegin(); //segfault here
	typename Cnt::reverse_iterator rend = cnt.rend();
	std::cout << std::endl << "TEST	inc/dec" << std::endl;
	it++;
	it--;
	end--;
	end++;
	++rit;
	--rit;
	--rend;
	++rend;
	testPrintState(cnt, it, end);
	testPrintState(cnt, rit, rend);
	testIteratorRBT_const(cnt);
	typename Cnt::allocator_type alloc =  cnt.get_allocator();
	typename Cnt::value_type *v = alloc.allocate(1);
	alloc.deallocate(v, 1);
	return 0;
}

#endif