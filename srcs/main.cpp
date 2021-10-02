#include "test.hpp"

int main()
{
	std::vector<std::string>	vector_stl_1;
	ft::vector<std::string>		vector_me_1;

	std::cout << "---- TEST resize" << std::endl;
	test_resizing<std::string>(vector_stl_1, vector_me_1);
	printElem<std::string>(vector_stl_1, vector_me_1);

	std::vector<int>	vector_stl_2(7, 3);
	ft::vector<int>		vector_me_2(7, 3);

	std::cout << "---- TEST resize" << std::endl;
	test_resizing<int>(vector_stl_2, vector_me_2);
	printElem<int>(vector_stl_2, vector_me_2);

	std::cout << "---- TEST access" << std::endl;
	accessTest(vector_stl_2, vector_me_2);

	std::cout << "---- TEST access CONST" << std::endl;
	accessTestConst(vector_stl_2, vector_me_2);
	return 0;
}
