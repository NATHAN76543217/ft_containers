#ifndef TESTITERATORRBT_HPP
#define TESTITERATORRBT_HPP


template<class Cnt, class Ite>
int		testKey(Cnt &cnt, typename Cnt::key_type key)
{
	Ite it = cnt.find(key);
	it = cnt.find(key);
	if (it == cnt.end())
		std::cout << "Key `" << key << "` not found" << std::endl;
	else
		std::cout << "Key '" << (*it).first << "' founded with value: " << (*it).second << std::endl;
	std::cout << "key count = " << cnt.count(key) << std::endl;;
	return 0;
}

template<class Cnt>
int		testFind(Cnt &cnt)
{
	std::cout << std::endl << std::endl << "TEST find" << std::endl;
	std::string key = "specialKey";
	cnt.insert(ft::pair<std::string, int>(key, 42));
	testKey<Cnt, typename Cnt::iterator>(cnt, key);
	key = "coucou";
	testKey<Cnt, typename Cnt::iterator>(cnt, key);
	return 0;
}

template<class Cnt>
int		testFind_const(Cnt &cnt)
{
	std::cout << std::endl << std::endl << "TEST find const " << std::endl;
	std::string key = "specialKey";
	testKey<Cnt, typename Cnt::const_iterator>(cnt, key);
	key = "coucou";
	testKey<Cnt, typename Cnt::const_iterator>(cnt, key);
	return 0;
}

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
	testFind_const(cnt);
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
	testFind(cnt);
	testIteratorRBT_const(cnt);
	typename Cnt::allocator_type alloc =  cnt.get_allocator();
	typename Cnt::value_type *v = alloc.allocate(1);
	alloc.deallocate(v, 1);

	return 0;
}

#endif