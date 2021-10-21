#include "RBTree.hpp"

int main(){
    ft::RBTree<std::string> tree;
    ft::RBTree<int> treeInt;
    std::string mystring("1st element");

    std::cout << "TEST STRING" << std::endl;
    tree.print();
    tree.insert(mystring);
    try {
        tree.insert(mystring);
    } catch (const std::exception &e) {
        std::cout << "catch:" << e.what() << "\n";
    }
    tree.print();
    tree.insert("Uno");
    tree.insert("Due");
    tree.insert("Tre");
    tree.insert("Quatro");
    tree.print();

    treeInt.insert(76);
    treeInt.insert(101);
    treeInt.insert(16);
    treeInt.insert(90);
    treeInt.insert(85);
    treeInt.insert(65);
    treeInt.print();

    std::cout << "TEST INT" << std::endl;
    treeInt.insert(55);
    treeInt.insert(20);
    treeInt.insert(71);
    treeInt.insert(81);
    treeInt.insert(93);
    treeInt.insert(52);
    treeInt.insert(100);
    treeInt.insert(61);
    treeInt.print();

    treeInt.insert(7);
    treeInt.insert(6);
    treeInt.insert(9);
    treeInt.insert(8);
    treeInt.insert(2);
    treeInt.insert(3);
    treeInt.insert(1);
    treeInt.print();

    std::cout << "TEST PAIR" << std::endl;
    //TODO implement test with pair
    std::cout << "TEST ITERATOR" << std::endl;
	ft::RBTree<int>::iterator it = treeInt.begin();
	// std::cout << "begin = " << it; 
	std::cout << "at begin = " << *it << std::endl; 
	for (; it != treeInt.end(); ++it)
		std::cout << *it << ", ";

	std::cout << " |  ";
	std::cout << *(++it) << ", ";
	std::cout << *(++it) << ", ";
	std::cout << *(++it) << ", ";
	std::cout << *(++it) << ", ";
	std::cout << *(++it) << ", " << std::endl;
	for (; it != treeInt.end(); --it)
		std::cout << *it << ", ";
	--it;
	// std::cout << *(--it) << ", " << std::endl;
	std::cout << std::endl;
	// std::cout << (it >= treeInt.begin())  << ", " << std::endl;
    for (; it > treeInt.begin(); --it)
		std::cout << *it << ", ";
	std::cout << *it << ", " << std::endl;
	it = treeInt.end() - 1;
	for (; it != treeInt.end(); it--)
		std::cout << *it << ", ";
	std::cout << "substract two iterator" << std::endl; 
	std::cout << treeInt.end() - treeInt.begin() << std::endl; //21
	std::cout << treeInt.end() - (treeInt.begin() + 1) << std::endl;//20 
	std::cout << (treeInt.end()-1) - treeInt.begin() << std::endl; //20
	std::cout << "substract two iterator" << std::endl; 
	std::cout << (treeInt.begin()) - treeInt.end() << std::endl; //-21
	std::cout << (treeInt.begin()+1) - treeInt.end() << std::endl; //-20
	std::cout << (treeInt.begin()) - (treeInt.end() - 1) << std::endl; //-20 
	std::cout << (treeInt.begin()) - (treeInt.end() + 1) << std::endl; //0
	std::cout << (treeInt.begin()-1) - treeInt.end() << std::endl; //0

    ft::RBTree<int> treeInt2;
	std::cout << "b == e = " << (treeInt2.begin() == treeInt2.end()) << std::endl;
	treeInt2.insert(42);
	treeInt2.print();
	it = treeInt2.begin();
	for (; it != treeInt2.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "b == e = " << (treeInt2.begin() == treeInt2.end()) << std::endl;
	treeInt2.insert(50);
	treeInt2.insert(60);
	treeInt2.insert(70);
	it = treeInt2.begin();
	for (; it != treeInt2.end(); ++it)
		std::cout << *it << std::endl;
	treeInt2.print();
	return 0;
}