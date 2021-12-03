#include "test.hpp"
# include <sstream>
class test {
	public:
	test(){
		std::cout << "test constructor called" << std::endl;
	}
	test(const test &t){
		(void)t;
		std::cout << "test copy called" << std::endl;
	}
	test &operator=(const test &rhs)
	{
		(void)rhs;
		std::cout << "operator =" << std::endl;
		return *this;
	}
	~test(){
		std::cout << "test destructor called" << std::endl;
	}
};

int		testSet()
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "------------------- SET --------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	ft::set<std::string> s1;
	std::cout << "value = " << is_iterator<ft::set<std::string>::iterator>::value;
	testPrintState_set(s1, s1.begin(), s1.end());
	std::cout << "insert element\n";
	s1.insert("firstKey");
	std::cout << "- size  = " << s1.size() << "\n";
	std::cout << "insert 4 other elements\n";
	s1.insert("secondKey");
	s1.insert("thirdKey");
	s1.insert("forthKey");
	s1.insert("fithKey");
	testPrintState_set(s1, s1.begin(), s1.end());


	std::cout << std::endl << "ERASE second key" << std::endl << std::endl;
	s1.erase("secondKey");
	testPrintState_set(s1, s1.begin(), s1.end());

	
	std::cout << std::endl << "ERASE range" << std::endl << std::endl;
	ft::set<std::string>::iterator it = s1.begin();
	s1.erase(++it, --s1.end());
	testPrintState_set(s1, s1.begin(), s1.end());

	std::cout << std::endl << "ERASE iterator" << std::endl << std::endl;
	it = s1.begin();
	s1.erase(--s1.end());
	testPrintState_set(s1, s1.begin(), s1.end());
	
	std::cout << std::endl << "TEST	CLEAR" << std::endl << std::endl;
	s1.insert("secondKey");
	s1.insert("thirdKey");
	s1.insert("forthKey");
	s1.insert("fithKey");
		it = s1.begin();
	for (; it != s1.end(); it++)
		std::cout << "(" << *it << ", " << *it << ") - ";
	std::cout << std::endl;
	s1.clear();
	it = s1.begin();
	if (it == s1.end() && s1.size() == 0)
		std::cout << "empty set"<< std::endl;

	std::cout << "Fill set" << std::endl;
	s1.insert("secondKey");
	s1.insert("thirdKey");
	uint max = 15000;
	while (max > 0)
	{
		std::stringstream key;
		key << "key=" << max;
		s1.insert(key.str());
		max--;
	}
	s1.insert("forthKey");
	s1.insert("fithKey");
	testIteratorRBT_set<ft::set<std::string> >(s1);
	testInsertion_set<ft::set<std::string> >(s1);
	testComparator_set<ft::set<std::string> >(s1);
	return 0;
}

int		testMap( void ) {
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "------------------- MAP --------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	ft::map<std::string, int> m1;
	std::cout << "value = " << is_iterator<ft::map<std::string, int>::iterator>::value;
	std::cout << "- size  = " << m1.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << m1.empty() << std::endl;
	std::cout << "insert element\n";
	m1.insert(ft::pair<std::string, int>("firstKey", 1));
	std::cout << "- size  = " << m1.size() << "\n";
	std::cout << "insert 4 other elements\n";
	m1.insert(ft::pair<std::string, int>("secondKey", 2));
	m1.insert(ft::pair<std::string, int>("thirdKey", 3));
	m1.insert(ft::pair<std::string, int>("forthKey", 4));
	m1.insert(ft::pair<std::string, int>("fithKey", 5));
	std::cout << "- size  = " << m1.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << m1.empty() << std::endl;
	ft::map<std::string, int>::iterator it = m1.begin();
	for (; it != m1.end(); it++)
		std::cout << "(" << (*it).first << ", " << (*it).second << ") - ";

	std::cout << std::endl << "ERASE second key" << std::endl << std::endl;
	m1.erase("secondKey");
	std::cout << "- size  = " << m1.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << m1.empty() << std::endl;
	it = m1.begin();
	for (; it != m1.end(); it++)
		std::cout << "(" << (*it).first << ", " << (*it).second << ") - ";

	
	std::cout << std::endl << "ERASE range" << std::endl << std::endl;
	it = m1.begin();
	m1.erase(++it, --m1.end());
	std::cout << "- size  = " << m1.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << m1.empty() << std::endl;
	it = m1.begin();
	for (; it != m1.end(); it++)
		std::cout << "(" << (*it).first << ", " << (*it).second << ") - ";

	std::cout << std::endl << "ERASE iterator" << std::endl << std::endl;
	it = m1.begin();
	m1.erase(--m1.end());
	std::cout << "- size  = " << m1.size() << "\n";
	std::cout << std::boolalpha << "- empty = " << m1.empty() << std::endl;
	it = m1.begin();
	for (; it != m1.end(); it++)
		std::cout << "(" << (*it).first << ", " << (*it).second << ") - ";
	
	std::cout << std::endl << "TEST	CLEAR" << std::endl << std::endl;
	m1.insert(ft::pair<std::string, int>("secondKey", 2));
	m1.insert(ft::pair<std::string, int>("thirdKey", 3));
	m1.insert(ft::pair<std::string, int>("forthKey", 4));
	m1.insert(ft::pair<std::string, int>("fithKey", 5));
		it = m1.begin();
	for (; it != m1.end(); it++)
		std::cout << "(" << (*it).first << ", " << (*it).second << ") - ";
	std::cout << std::endl;
	m1.clear();
	it = m1.begin();
	if (it == m1.end() && m1.size() == 0)
		std::cout << "empty map"<< std::endl;

	std::cout << "Fill map" << std::endl;
	m1.insert(ft::pair<std::string, int>("secondKey", 2));
	m1.insert(ft::pair<std::string, int>("thirdKey", 3));
	uint max = 15000;
	while (max > 0)
	{
		std::stringstream key;
		key << "key=" << max;
		m1.insert(ft::pair<std::string, int>( key.str(), 2));
		max--;
	}
	m1.insert(ft::pair<std::string, int>("forthKey", 4));
	m1.insert(ft::pair<std::string, int>("fithKey", 5));
	testIteratorRBT<ft::map<std::string, int> >(m1);
	testInsertion<ft::map<std::string, int> >(m1);
	testComparator<ft::map<std::string, int> >(m1);
	return 0;
}
int		testStack()
{
	// ft::stack<std::string> s1;
	ft::vector<std::string> v1(10, "hey test");
	stack_constructor(v1, std::string("test_string"));
	// ft::stack<std::string, ft::vector<std::string> > s2;
	std::list<std::string> l1(10, "hey test");
	stack_constructor(l1, std::string("test_string"));
	std::cout << "End test for STACK\n" << std::endl;
	return 0;
}

int		testVector()
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "------------------- VECTOR --------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	ft::vector<std::string>		vector_1;
	std::string svalue("value");

	std::cout << "---- TEST constructor (string)" << std::endl;
	vector_constructor<std::string>(vector_1, svalue);
	std::cout << "---- TEST resize (string)" << std::endl;
	test_resizing<std::string>(vector_1);
	printElem<std::string>(vector_1);

	ft::vector<int>		vector(7, 3);

	std::cout << "---- TEST resize (int)" << std::endl;
	test_resizing<int>(vector);
	printElem<int>(vector);

	std::cout << "---- TEST access" << std::endl;
	accessTest(vector);

	std::cout << "---- TEST access CONST" << std::endl;
	accessTestConst(vector);

	std::cout << "---- TEST ITERATOR" << std::endl;
	testIterator<int>(vector);

	std::cout << "---- TEST resize" << std::endl;
	vector.resize(10);
	printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;
	vector.resize(30, 3);
	printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;

	// vector_stl_2.assign(23, 1);
	// vector_me_2.assign(23, 1);
	// 	printElem<int>(vector_stl_2, vector_me_2);
	// std::cout << vector_stl_2.size() << "/" << vector_stl_2.capacity() << std::endl;
	// std::cout << vector_me_2.size() << "/" << vector_me_2.capacity() << std::endl;

	// vector_stl_2.assign(32, 7);
	// vector_me_2.assign(32, 7);
	// 	printElem<int>(vector_stl_2, vector_me_2);
	// std::cout << vector_stl_2.size() << "/" << vector_stl_2.capacity() << std::endl;
	// std::cout << vector_me_2.size() << "/" << vector_me_2.capacity() << std::endl;

	std::cout << "pop back" << std::endl;
	vector.pop_back();
		printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;

	vector.back() = 90;
		printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;

	vector.front() = 90;
		printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;


	vector.insert(vector.begin(), 42);
		printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;

	vector.insert(vector.end(), 42);
		printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;

	vector.insert(vector.begin() + 4, 5, 80);
	printElem<int>(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;
// REVIEW  
	std::cout << "---- TEST assign" << std::endl;
	vector.assign(vector.begin() + 4, vector.end() - 1);
	test_push_back(vector);
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;
// TODO test with end()
//TODO mouve this test in modifier
	std::cout << vector.size() << "/" << vector.capacity() << std::endl;
	std::cout << "---- TEST modifier" << std::endl;
	int val = 4;
	testModifier<int>(vector, val);
	test_op_vector<int>(vector, val);
	// {
	// 	std::cout << "create t1" << std::endl;
	// 	test t1;
	// 	std::cout << "create uno" << std::endl;
	// 	ft::vector<test> uno;
	// 	std::cout << "create due" << std::endl;
	// 	ft::vector<test> due(4);
	// 	std::cout << "push uno t1" << std::endl;
	// 	uno.push_back(t1);
	// 	std::cout << "push due t1" << std::endl;
	// 	due.push_back(t1);
	// 	#ifdef STL
	// 		std::cout << "STL used" << std::endl;
	// 	#else
	// 		std::cout << "FT used" << std::endl;
	// 	#endif
	// 	std::cout << "delete uno - due" << std::endl;
	// }
	// printElem<test>(vector);
	return 0;
}

int main()
{
	testVector();
	testMap();
	testSet();
	testStack();
	return 0;
}
