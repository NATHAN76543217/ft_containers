#include "test.hpp"

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

int		testMap( void ) {
	//TODO add tests for MAP
	ft::map<std::string, int> m1;

	return 0;
}

int		testStack()
{
	// stack<> s1
	return 0;
}

int		testVector()
{
	ft::vector<std::string>		vector_1;
	std::string svalue("value");
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "------------------- VECTOR --------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

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
	testStack();
	testMap();
	return 0;
}
