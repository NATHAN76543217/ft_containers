#ifndef TESTITERATORRBT_SET_HPP
#define TESTITERATORRBT_SET_HPP


template<class Cnt, class Ite>
int		testKey_set(Cnt &cnt, typename Cnt::key_type key)
{
	Ite it = cnt.find(key);
	it = cnt.find(key);
	if (it == cnt.end())
		std::cout << "Key `" << key << "` not found" << std::endl;
	else
		std::cout << "Key founded: '" << *it << std::endl;
	std::cout << "key count = " << cnt.count(key) << std::endl;;
	return 0;
}

template<class Cnt>
int		testFind_set(Cnt &cnt)
{
	std::cout << std::endl << std::endl << "TEST find" << std::endl;
	std::string key = "specialKey";
	cnt.insert(key);
	testKey_set<Cnt, typename Cnt::iterator>(cnt, key);
	key = "coucou";
	testKey_set<Cnt, typename Cnt::iterator>(cnt, key);
	return 0;
}

template<class Cnt>
int		testFind_const_set(Cnt &cnt)
{
	std::cout << std::endl << std::endl << "TEST find const " << std::endl;
	std::string key = "specialKey";
	testKey_set<Cnt, typename Cnt::const_iterator>(cnt, key);
	key = "coucou";
	testKey_set<Cnt, typename Cnt::const_iterator>(cnt, key);
	return 0;
}

//TODO check for test: create reverse_iterator from it or const_reverse_iterator
template<class Cnt, class Ite>
int		testPrintState_set(const Cnt &cnt, Ite &start, Ite &end)	
{
	std::cout << std::endl << "- size  = " << cnt.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << cnt.empty() << std::endl;
	for (; start != end; start++)
		std::cout << "(" << *start << ") - ";
	return 0;
}

template<class Cnt>
int		testIteratorRBT_const_set(const Cnt &cnt)
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
	testPrintState_set(cnt, it, end);
	testPrintState_set(cnt, rit, rend);
	testFind_const_set(cnt);
	return 0;
}

template<class Cnt>
int		testIteratorRBT_set(Cnt &cnt)
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
	testPrintState_set(cnt, it, end);
	testPrintState_set(cnt, rit, rend);
	testFind_set(cnt);
	testIteratorRBT_const_set(cnt);
	typename Cnt::allocator_type alloc =  cnt.get_allocator();
	typename Cnt::value_type *v = alloc.allocate(1);
	alloc.deallocate(v, 1);

	return 0;
}

#endif