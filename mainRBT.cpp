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
    return 0;
}